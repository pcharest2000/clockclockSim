#include "myTime.h"

myTime::myTime() {}

void myTime::updateNptTime() {
#ifndef SIM
  // connect to WiFi
  WiFi.begin(ssid, password);
  unsigned long timeout = millis() + _WifiTimeout;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (millis() > timeout) {
      _lastUpdateSuccesfull = false;
      return;
    }
  }
  // init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  if (!getLocalTime(&_lastTimeInfo)) {
    _lastUpdateSuccesfull = false;
    // TODO
    // add fallback condition if NPT time does note work
  }
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
#else

  time_t t2 = time(NULL);
  _lastTimeInfo = *localtime(&t2);

#endif

  prevSeconds = _lastTimeInfo.tm_sec;
  prevMin = _lastTimeInfo.tm_min;
  prevHour = _lastTimeInfo.tm_hour;
  currentSeconds = _lastTimeInfo.tm_sec;
  currentMin = _lastTimeInfo.tm_min;
  currentHour = _lastTimeInfo.tm_hour;
  // disconnect WiFi as it's no longer needed
  // esp_wifi_deinit();
  _lastUpdateSuccesfull = true;
  _lastTimeUpdate = time(NULL);
  _nextTimeUptade = _lastTimeUpdate + _ntpUpdateFreq;
}

void myTime::checkNptUpdatetime() {
  if (time(NULL) > _nextTimeUptade) {
    updateNptTime();
    _nextTimeUptade = time(NULL) + _ntpUpdateFreq;
  }
}
void myTime::printInfo() {
  struct tm timeinfo;
// getLocalTime(&timeinfo);
#ifndef SIM
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "Current Time: %A, %B %d %Y %H:%M:%S");
  Serial.print("time now: ");
  Serial.println(time(NULL));
  Serial.print("Last npt update: ");
  Serial.println(_lastTimeUpdate);
  Serial.print("Next npt update: ");
  Serial.println(_nextTimeUptade);
  Serial.print("Last update Sucessfull: ");
  Serial.println(_lastUpdateSuccesfull);
#endif
}

bool myTime::getTimeChangedSeconds() {
  bool changed = false;

#ifndef SIM
  getLocalTime(&_currentTimeInfo);
#else
  time_t t2 = time(NULL);
  _currentTimeInfo = *localtime(&t2);
#endif

  // if (_currentTimeInfo.tm_sec != _lastTimeInfo.tm_sec) {
  //   whatChanged = whatChanged | SEC_DIG;
  // } else
  //   return whatChanged;
  if (_currentTimeInfo.tm_sec != _lastTimeInfo.tm_sec) {
    changed = true;
    _lastTimeInfo = _currentTimeInfo;
    updateDigits();
  }
  return changed;
}
bool myTime::getTimeChanged() {
  bool changed = false;

#ifndef SIM
  getLocalTime(&_currentTimeInfo);
#else
  time_t t2 = time(NULL);
  _currentTimeInfo = *localtime(&t2);
#endif

  // if (_currentTimeInfo.tm_sec != _lastTimeInfo.tm_sec) {
  //   whatChanged = whatChanged | SEC_DIG;
  // } else
  //   return whatChanged;
  if (_currentTimeInfo.tm_min != _lastTimeInfo.tm_min) {
    changed = true;
    _lastTimeInfo = _currentTimeInfo;
    updateDigits();
  }
  return changed;
}
void myTime::getTime() {
  bool changed = false;

#ifndef SIM
  getLocalTime(&_currentTimeInfo);
#else
  time_t t2 = time(NULL);
  _currentTimeInfo = *localtime(&t2);
#endif

  // if (_currentTimeInfo.tm_sec != _lastTimeInfo.tm_sec) {
  //   whatChanged = whatChanged | SEC_DIG;
  // } else
  //   return whatChanged;
    _lastTimeInfo = _currentTimeInfo;
    updateDigits();
  }
void myTime::updateDigits() {

  prevHourDigit = hourDigit;
  prevHourTenth = hourTenth;
  prevMinDigit = minDigit;
  prevMinTenth = minTenth;
  prevSecDigit = secDigit;
  prevSecTenth = secTenth;

  hourDigit = (_currentTimeInfo.tm_hour % 10);
  hourTenth = (_currentTimeInfo.tm_hour / 10);
  minDigit = (_currentTimeInfo.tm_min % 10);
  minTenth = (_currentTimeInfo.tm_min / 10);
  secDigit = (_currentTimeInfo.tm_sec % 10);
  secTenth = (_currentTimeInfo.tm_sec / 10);
}
