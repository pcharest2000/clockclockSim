#include "config.h"
#ifndef SIM
#include "fabgl.h"
#include <Arduino.h>
#else
#include "Canvas.h"
#endif
#include "Animation.h"
#include "ClockMatrix.h"
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
    //drawStairs(&clocks);
    // clocks.runDelay(3000);
     //drawSwans(&clocks);
    // drawSquares(&clocks);
     //aniSquare(&clocks);
    // aniDiamond(&clocks);
    aniWave(&clocks, &myTi);
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
    cv.draw(); //Sets color to white
    clocks.draw();
    cv.swapBuffers();
    SDL_Delay(1);
  }
}
