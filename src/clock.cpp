#include "clock.h"

#ifdef SIM
uint32_t micros() {
  return std::chrono::high_resolution_clock::now().time_since_epoch().count() /
         1000;
}
#endif

Clock::Clock(int x, int y, int width, Canvas *cv) {
  _center.x = x;
  _center.y = y;
  _cv = cv;
  _width = width;
  _width2 = width / 2;
}

Clock::Clock() {}
void Clock::draw() {
  _calEndPoints();
  _cv->drawLine(_center.x, _center.y, _endMin.x, _endMin.y);
  _cv->drawLine(_center.x, _center.y, _endHour.x, _endHour.y);
  // _cv->drawEllipse(_center.x, _center.y, _width, _width);
}

void Clock::_calEndPoints() {
  _endMin.x = _center.x + (_width2 * ((int16_t)cos8(_minAngle) - 128)) / 128;
  _endMin.y = _center.y - (_width2 * ((int16_t)sin8(_minAngle) - 128)) / 128;
  _endHour.x = _center.x + (_width2 * ((int16_t)cos8(_hourAngle) - 128)) / 128;
  _endHour.y = _center.y - (_width2 * ((int16_t)sin8(_hourAngle) - 128)) / 128;
}

bool Clock::clockDone() {
  if (_minDir == 0 && _hourDir == 0)
    return true;
  else
    return false;
}

void Clock::setSpeed(float hourRPM, float minRPM) {
  _minDelay = (60.0 * 1000000 / STEPSPER360) / minRPM;
  _hourDelay = (60.0 * 1000000 / STEPSPER360) / hourRPM;
}
void Clock::run(uint32_t currentMicro) {
  if (_hourDir != 0) {
    if (currentMicro - _hourLastMicro >= _hourDelay + _hourStartDelay) {
      _hourStartDelay = 0;
      _hourLastMicro = currentMicro;
      _hourAngle += _hourDir;
      if (_hourAngle == _hourTarget) {
        _hourDir = 0;
      }
    }
  }
  if (_minDir != 0) {
    if (currentMicro - _minLastMicro >= _minDelay + _minStartDelay) {
      _minStartDelay = 0;
      _minLastMicro = currentMicro;
      _minAngle += _minDir;
      if (_minAngle == _minTarget) {
        _minDir = 0;
      }
    }
  }
}

void Clock::begin(int x, int y, int width, Canvas *cv) {
  _center.x = x;
  _center.y = y;
  _cv = cv;
  _width = width;
  _width2 = width / 2;
  _calEndPoints();
}

void Clock::setAngle(int hourA, int minA) {

  _minDir = 0;
  _hourDir = 0;
  _hourAngle = hourA;
  _minAngle = minA;
  _hourTarget = hourA;
  _minAngle = minA;
}
void Clock::setTarget(int hourT, int minT) {

  if (hourT > _hourAngle)
    _hourDir = 1;
  else if (hourT < _hourAngle)
    _hourDir = -1;
  else if (hourT == _hourAngle)
    _hourDir = 0;

  if (minT > _minAngle)
    _minDir = 1;
  else if (minT < _minAngle)
    _minDir = -1;
  else if (minT == _minAngle)
    _minDir = 0;
  _minStartDelay=0;
  _hourStartDelay=0;
  _hourTarget = hourT;
  _minTarget = minT;
}

void Clock::addToTarget(int angleH, int angleM){


  _hourTarget += angleH;
  _minTarget += angleM;

  if (_hourTarget < _hourAngle)
    _hourDir = -1;
  else if (_hourTarget > _hourAngle)
    _hourDir = 1;
  else if (_hourTarget == _hourAngle)
    _hourDir = 0;

  if (_minTarget < _minAngle)
    _minDir = -1;
  else if (_minTarget > _minAngle)
    _minDir = 1;
  else if (_minTarget == _minAngle)
    _minDir = 0;
}


void Clock::setTargetDelay(uint32_t micro, int hourT, int minT,
                           uint32_t hourDmillis, uint32_t minDmillis) {
  setTarget(hourT, minT);
  _hourStartDelay = hourDmillis * 1000;
  _minStartDelay = minDmillis * 1000;
  _hourLastMicro = micro;
  _minLastMicro = micro;
}
void Clock::printInfo() {
  // Serial.print("Angle: ");
  // Serial.println(_minAngle);
  // Serial.print("Target: ");
  // Serial.println(_minTarget);
  // Serial.print("Dir: ");
  // Serial.println(_minDir);
}
uint32_t Clock::getMinDistance() { return abs(_minTarget - _minAngle); }

uint32_t Clock::getHourDistance() { return abs(_hourTarget - _hourAngle); }

void Clock::normalizeHourAngle() {
  _hourAngle = _hourAngle % STEPSPER360;
  _hourDir = 0;
  _hourTarget = _hourAngle;
}

void Clock::normalizeMinAngle() {
  _minAngle = _minAngle % STEPSPER360;
  _minDir = 0;
  _hourTarget = _hourAngle;
}

void Clock::normalizeAngles() {
  normalizeHourAngle();
  normalizeMinAngle();
}
