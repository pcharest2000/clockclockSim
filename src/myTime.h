#ifndef MYTIME_H_
#define MYTIME_H_

#include "config.h"
#ifndef SIM
#include <Arduino.h>
#include <WiFi.h>
#include <esp_wifi.h>
#endif
#include <cstdint>
#include <time.h>
enum TimeChangeState : uint32_t {
  NOTHING = 0,
  SEC_DIG = 1,
  SEC_TEN = 2,
  MIN_DIG = 4,
  MIN_TEN = 8,
  HOUR_DIG = 16,
  HOUR_TEN = 32
};

class myTime {

public:
  myTime();
  void updateNptTime();
  void printInfo();
  void checkNptUpdatetime();
  bool getTime();
  void updateDigits();
  uint8_t prevSeconds;
  uint8_t currentSeconds;
  uint8_t prevMin;
  uint8_t currentMin;
  uint8_t prevHour;
  uint8_t currentHour;
  uint8_t hourDigit;
  uint8_t hourTenth;
  uint8_t minDigit;
  uint8_t minTenth;

private:
  const char *ssid = "BELL963";
  const char *password = "393CC366";
  const long gmtOffset_sec = -18000;
  const int daylightOffset_sec = 3600;
  const char *ntpServer = "north-america.pool.ntp.org";

  const time_t _ntpUpdateFreq = 60 * 60 * 24; // Seconds
  struct tm _lastTimeInfo;
  struct tm _currentTimeInfo;
  struct tm _lastNptUpdate;
  time_t _lastTimeUpdate; // In epoch
  time_t _nextTimeUptade; // In epoch
  bool _lastUpdateSuccesfull = false;
  const uint32_t _WifiTimeout = 30 * 1000; // ms
};

#endif // MYTIME_H_
