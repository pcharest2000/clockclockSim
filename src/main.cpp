#include "config.h"
#ifndef SIM
#include "fabgl.h"
#include <Arduino.h>
#else
#include "Canvas.h"
#endif
#include "Animation.h"
#include "ClockMatrix.h"
#include "clock.h"
#include "myTime.h"
#include <cstdint>

SDL_Thread *updateThread = NULL;
#ifdef SIM
Canvas cv;
#endif
ClockMatrix clocks;
myTime myTi;

int updateT(void *data) {
    uint32_t time = micros();
  while (1) {
    //clocks.printClockNormalized(&myTi, 30);
    clocks.setSpeedAll(5, 10);
    clocks.setTargetBox(1, 1, 4, 4, 230, -430);
    clocks.normalizeSpeedBox(1, 1, 2, 2, 20);
    clocks.runToDestination();
    clocks.setSpeedAll(10, 5);
    clocks.setTargetBox(1, 1, 4, 4, -230, 430);
    clocks.runToDestination();
    //aniSquare(&clocks);
    //aniWave(&clocks,&myTi);
    // clocks.setAngleAll(DEG45, DEG225);
    // clocks.setTargetDelay(time, 0, 0, 200, -200, 3000, 1000);
    // clocks.runToDestination();
    // time = micros();
    // clocks.setTargetDelay(time,0, 0, 0, 0, 1000, 3000);
    // clocks.runToDestination();



    // uint8_t state = myTi.getTime();
    // clocks.printClock(myTi.hourTenth, myTi.hourDigit, myTi.minTenth,
    //                   myTi.minDigit);
    // clocks.runToDestination();
  }
  return 0;
}
void setup() {
  clocks.begin(&cv);
    clocks.setSpeedAll(10, 10);
  updateThread = SDL_CreateThread(updateT, "updateT", (void *)NULL);
}
int frames = 0;
int main() {
  setup();
  while (1) {
    cv.clear();
    cv.draw();
    clocks.draw();
    cv.swapBuffers();

    SDL_Delay(1);
  }
}
