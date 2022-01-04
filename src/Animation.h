#ifndef ANIMATIONS_H
#define ANIMATIONS_H
#include "ClockMatrix.h"
#include "digits.h"
#include "myTime.h"
#include "lib8tion.h"


void aniSquare(ClockMatrix *clock);
void aniDiamond(ClockMatrix *clock);
void drawWave2(ClockMatrix *clock);
void drawWave(ClockMatrix *clock);
void setSquare(ClockMatrix *clock, int32_t turns);
void drawSquares(ClockMatrix *clock);
void drawRectangles(ClockMatrix *clock);
void drawDiamond(ClockMatrix *clock);
void drawStairs(ClockMatrix *clock);
void drawSwans(ClockMatrix *clock);
void clockLoop(ClockMatrix *clock,myTime *timeObj);
#endif //ANIMATIONS_S
