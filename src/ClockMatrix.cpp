#include "ClockMatrix.h"

ClockMatrix::ClockMatrix() {}

void ClockMatrix::begin(Canvas *cv) {
  _cv = cv;
  _drawW = _cv->getWidth();
  _drawH = _cv->getHeight();
  _rows = MHEIGTH;
  _cols = MWIDTH;
  int clockwidth = _drawW / _cols;
  int ypadding = (_drawH - _rows * clockwidth) / 2 + clockwidth / 2;
  int ypos = 0 + ypadding;
  int xpos = clockwidth / 2;
  for (uint32_t j = 0; j < _cols; j++) {
    ypos = ypadding; // clockwidth / 2;
    for (uint32_t i = 0; i < _rows; i++) {
      _matrix[i][j].begin(xpos, ypos, clockwidth, cv);
      ypos += clockwidth;
    }
    xpos += clockwidth;
  }
}

void ClockMatrix::run(uint32_t micro) {
  for (uint32_t i = 0; i < _rows; i++) {
    for (uint32_t j = 0; j < _cols; j++) {
      _matrix[i][j].run(micro);
    }
  }
}
void ClockMatrix::runDelay(uint32_t millis) {
  uint32_t microDelay = millis * 1000;
  uint32_t startMicro = micros();
  uint32_t timeNow = startMicro;
  while (!(timeNow - startMicro > microDelay)) {
    run(timeNow);
    timeNow = micros();
  }
}

void ClockMatrix::runToDestination() {
  uint64_t time;
  bool don = false;
  while (!don) {
    don = true;
    time = micros();
    for (uint32_t i = 0; i < _rows; i++) {
      for (uint32_t j = 0; j < _cols; j++) {
        _matrix[i][j].run(time);
        if (_matrix[i][j].clockDone() == false)
          don = false;
      }
    }
  }
}
bool ClockMatrix::isDone() {
  for (uint32_t i = 0; i < _rows; i++) {
    for (uint32_t j = 0; j < _cols; j++) {
      if (!_matrix[i][j].clockDone())
        return false;
    }
  }
  return true;
}

void ClockMatrix::draw() {
  for (uint32_t i = 0; i < _rows; i++) {
    for (uint32_t j = 0; j < _cols; j++) {
      _matrix[i][j].draw();
    }
  }
}

void ClockMatrix::setAngle(uint32_t i, uint32_t j, int hourA, int minA) {
  if (i >= _rows || j > _cols)
    return;
  _matrix[i][j].setAngle(hourA, minA);
}

void ClockMatrix::setAngleAll(int hourA, int minA) {
  for (uint32_t i = 0; i < _rows; i++) {
    for (uint32_t j = 0; j < _cols; j++) {
      _matrix[i][j].setAngle(hourA, minA);
    }
  }
}

void ClockMatrix::setTarget(uint32_t i, uint32_t j, int hourT, int minT) {
  if (i >= _rows || j >= _cols)
    return;
  _matrix[i][j].setTarget(hourT, minT);
}
void ClockMatrix::setTargetDelay(uint32_t micro, uint32_t i, uint32_t j,
                                 int hourA, int minA, uint32_t hourDmillis,
                                 uint32_t minDmillis) {
  if (i >= _rows || j >= _cols)
    return;
  _matrix[i][j].setTargetDelay(micro, hourA, minA, hourDmillis, minDmillis);
}
void ClockMatrix::setTargetAll(int hourT, int minT) {
  for (uint32_t i = 0; i < _rows; i++) {
    for (uint32_t j = 0; j < _cols; j++) {
      _matrix[i][j].setTarget(hourT, minT);
    }
  }
}
void ClockMatrix::setTargetBox(uint32_t i, uint32_t j, uint32_t heigth, uint32_t width, int hourA, int minA){
  for (int i1 = i; i1 < i + heigth; i1++) {
    for (int j1 = j; j1 < j + width; j1++) {
      if (j1 >= _cols || i1 >= _rows)
        continue;
      _matrix[i1][j1].setTarget(hourA, minA);
    }
  }
}
void ClockMatrix::setSpeed(uint32_t i, uint32_t j, float hourRPM,
                           float minRPM) {
  if (i >= _rows || j >= _cols)
    return;
  _matrix[i][j].setSpeed(hourRPM, minRPM);
}

void ClockMatrix::setSpeedAll(float hourRPM, float minRPM) {
  for (uint32_t i = 0; i < _rows; i++) {
    for (uint32_t j = 0; j < _cols; j++) {
      _matrix[i][j].setSpeed(hourRPM, minRPM);
    }
  }
}

uint32_t ClockMatrix::getCols() { return _cols; }

uint32_t ClockMatrix::getRows() { return _rows; }

void ClockMatrix::printDigit(uint32_t x, uint32_t y, uint8_t dig) {
  digitA *digPtr = getDigitPtr(dig);
  if (digPtr == nullptr) {
    printf("Why Here");
    return;
  }
  for (uint32_t i = 0; i < DIGITW; i++) {
    for (uint32_t j = 0; j < DIGITH; j++) {
      setTarget(j + y, i + x, (*digPtr)[i][j][0], (*digPtr)[i][j][1]);
    }
  }
}

void ClockMatrix::printClock(myTime *timeObj, float rpm) {
  uint32_t state = timeObj->getTime();
  if (state == MIN_DIG) {
    printDigit(1, 2, timeObj->hourTenth);
    printDigit(4, 2, timeObj->hourDigit);
    printDigit(8, 2, timeObj->minTenth);
    printDigit(11, 2, timeObj->minDigit);
  }
}
void ClockMatrix::printClockNormalized(myTime *timeObj, float rpm) {
  bool changed = timeObj->getTime();
  if (changed) {
    printDigit(1, 2, timeObj->hourTenth);
    printDigit(4, 2, timeObj->hourDigit);
    printDigit(8, 2, timeObj->minTenth);
    printDigit(11, 2, timeObj->minDigit);
    normalizeSpeedBox(1, 2, 6, 3, rpm);
    normalizeSpeedBox(4, 2, 6, 3, rpm);
    normalizeSpeedBox(8, 2, 6, 3, rpm);
    normalizeSpeedBox(11, 2, 6, 3, rpm);
    printf("Changed");
    fflush(stdout);
  }
}
void ClockMatrix::normalizeSpeed(float rpm) {
  int32_t longest = 0;
  uint32_t longI = 0;
  uint32_t longJ = 0;

  // first find the longest distance travaelle
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      if (_matrix[i][j].getHourDistance() > longest) {
        longest = _matrix[i][j].getHourDistance();
        longI = i;
        longJ = j;
      }
      if (_matrix[i][j].getMinDistance() > longest) {
        longest = _matrix[i][j].getMinDistance();
        longI = i;
        longJ = j;
      }
    }
  }
  // We do not want to divide by zero! !:
  if (longest == 0) {
    return;
  }
  float hourspeed, minspeed;
  float longestf = longest;
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      hourspeed = ((float)_matrix[i][j].getHourDistance() / longestf) * rpm;
      minspeed = ((float)_matrix[i][j].getMinDistance() / longestf) * rpm;
      _matrix[i][j].setSpeed(hourspeed, minspeed);
    }
  }
}

void ClockMatrix::normalizeSpeedBox(uint32_t i, uint32_t j, uint8_t heigth,
                                    uint8_t width, float rpm) {
  int32_t longest = 0;
  uint32_t longI = i;
  uint32_t longJ = j;

  // first find the longest distance travaelle
  for (int i1 = i; i1 < i + heigth; i1++) {
    for (int j1 = j; j1 < j + width; j1++) {
      if (j1 >= _cols || i1 >= _rows)
        continue;
      if (_matrix[i1][j1].getHourDistance() > longest) {
        longest = _matrix[i1][j1].getHourDistance();
        longI = i1;
        longJ = j1;
      }
      if (_matrix[i1][j1].getMinDistance() > longest) {
        longest = _matrix[i1][j1].getMinDistance();
        longI = i1;
        longJ = j1;
      }
    }
  }
  // We do not want to divide by zero! !:
  if (longest == 0) {
    return;
  }
  float hourspeed, minspeed;
  float longestf = longest;
  for (int i1 = i; i1 < i + heigth; i1++) {
    for (int j1 = j; j1 < j + width; j1++) {
      if (j1 >= _cols || i1 >= _rows)
        continue;
      hourspeed = ((float)_matrix[i1][j1].getHourDistance() / longestf) * rpm;
      minspeed = ((float)_matrix[i1][j1].getMinDistance() / longestf) * rpm;
      _matrix[i1][j1].setSpeed(hourspeed, minspeed);
    }
  }
}
void ClockMatrix::normalizeAngles() {

  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      _matrix[i][j].normalizeAngles();
    }
  }
}
