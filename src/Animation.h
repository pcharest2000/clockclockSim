#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#include "ClockMatrix.h"
#include "digits.h"
#include "myTime.h"
void aniSquare(ClockMatrix *clock);
void aniDiamond(ClockMatrix *clock);
void aniWave(ClockMatrix *clock,myTime *timeObj);
void setSquare(ClockMatrix *clock, int32_t turns);
void drawSquares(ClockMatrix *clock);
void drawDiamond(ClockMatrix *clock);
void drawStairs(ClockMatrix *clock);
#endif //ANIMATIONS_S
