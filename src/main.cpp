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
  while (1) {
    uint32_t time = micros();
    clocks.setTargetDelay(time, 0, 0, 200, -200, 3000, 1000);
    clocks.runToDestination();
    time = micros();
    clocks.setTargetDelay(time,0, 0, 0, 0, 1000, 3000);
    clocks.runToDestination();
    // uint8_t state = myTi.getTime();
    // clocks.printClock(myTi.hourTenth, myTi.hourDigit, myTi.minTenth,
    //                   myTi.minDigit);
    // clocks.runToDestination();
  }
  return 0;
}
void setup() {
  clocks.begin(&cv);
  updateThread = SDL_CreateThread(updateT, "updateT", (void *)NULL);
    clocks.setSpeedAll(10, 10);
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
