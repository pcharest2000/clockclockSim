#ifndef CLOCK_H_
#define CLOCK_H_

#define STEPSPER360 256 // Steps per rotation
#define DEG0 0
#define DEG45 STEPSPER360 / 8
#define DEG90 STEPSPER360 / 4
#define DEG135 DEG90 + DEG45
#define DEG180 STEPSPER360 / 2
#define DEG225 DEG180 + DEG45
#define DEG270 DEG90 + DEG180
#define DEG315 DEG270 + DEG45
#define DEG360 STEPSPER360
#include "config.h"
#ifndef SIM
#include "fabgl.h"
#else
#include "Canvas.h"
#include <chrono>
uint32_t micros();
#endif

#include "lib8tion.h"
#include "math.h"
#include <cstdint>
struct position {
  int x;
  int y;
};

class Clock {
public:
  static uint64_t lastUpdateTime;
  Clock(int x, int y, int width, Canvas *cv);
  Clock();
  void begin(int x, int y, int width, Canvas *cv);
  void draw();
  void setSpeed(float hourRPM, float minRPM);
  void setAngle(int hour, int min);
  void setTarget(int hourT, int minT);
  void addToTarget(int angleH,int angleM);
  void setTargetDelay(uint32_t micro,int  hourT, int minT, uint32_t hourD, uint32_t minD);
  void run(uint32_t micro);
  bool clockDone();
  void printInfo();
  uint32_t getHourDistance();
  uint32_t getMinDistance();
  void normalizeHourAngle();
  void normalizeMinAngle();
  void normalizeAngles();

private:
  Canvas *_cv;
 int _width;
  int _width2; // width divided by 2
  position _center;
  position _endMin, _endHour;
  int _minAngle = 0;
  int _hourAngle = 0;
  int32_t _minTarget = 0;
  int32_t _hourTarget = 0;
  uint32_t _minDelay = 0;
  uint32_t _hourDelay = 0;
  uint32_t _minLastMicro = 0;
  uint32_t _hourLastMicro = 0;
  int32_t _minDir = 0;
  int32_t _hourDir = 0;
  void _calEndPoints();
  uint32_t _hourStartDelay = 0;
  uint32_t _minStartDelay = 0;
};
#endif // CLOCK_H_
