#ifndef CLOCKMATRIX_H_
#define CLOCKMATRIX_H_

#include "clock.h"
#include "config.h"
#include "myTime.h"
#ifndef SIM
#include "fabgl.h"
#else
#include "Canvas.h"
#endif

#include "digits.h"
#include "lib8tion.h"
#include "math.h"
#include <cstdint>
#define MWIDTH 15
#define MHEIGTH 10

class ClockMatrix {
public:
  ClockMatrix();
  void begin(Canvas *cv);
  void draw();
  void run(uint32_t micros);
  void runDelay(uint32_t millis);
  void runToDestination();
  void setAngle(uint32_t i, uint32_t j, int hourA, int minA);
  void setAngleAll(int hourA, int minA);
  void setTargetBox(uint32_t i, uint32_t j, uint32_t heigth, uint32_t width,
                    int hourA, int minA);
  void setTarget(uint32_t i, uint32_t j, int hourA, int minA);
  void setTargetDelay(uint32_t micro, uint32_t i, uint32_t j, int hourA,
                      int minA, uint32_t hourDmillis, uint32_t minDmillis);
  void addTarget(uint32_t i, uint32_t j, int hourT, int minT);
  void addTargetAll(int hourT, int minT);
  void setTargetAll(int hourT, int minT);
  void setSpeed(uint32_t i, uint32_t j, float hourRPM, float minRPM);
  void setSpeedAll(float hourRPM, float minRPM);
  bool isDone();
  uint32_t getCols();
  uint32_t getRows();
  void printDigit(uint32_t x, uint32_t y, uint8_t digit);
  void printClock(myTime *timeObject);
  void printClockCheck(myTime *timeObject);
  void printClockNormalized(myTime *timeObject, float rpm);
  void printClockNormalizedChecked(myTime *timeObject, float rpm);
  void normalizeSpeed(float rpm);
  void normalizeSpeedBox(uint32_t i, uint32_t j, uint8_t heigth, uint8_t width,
                         float rpm);
  void normalizeAngles();
  void normalizeAnglesBox(uint32_t i, uint32_t j, uint32_t heigth, uint32_t width);

private:
  Clock _matrix[MHEIGTH][MWIDTH];
  uint32_t _rows;
  uint32_t _cols;
  int _drawW;
  int _drawH;
  Canvas *_cv;
};

#endif // CLOCKMATRIX_H_
