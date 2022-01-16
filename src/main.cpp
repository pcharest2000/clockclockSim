#include "config.h"
#ifndef SIM
#include "fabgl.h"
#include <Arduino.h>
#else
#include "Canvas.h"
#endif
#include "Animation.h"
#include "ClockMatrix.h"
#include "dali_digit.h"
#include "myTime.h"
#include <cstdint>
#ifdef SIM
SDL_Thread *updateThread = NULL;
Canvas cv;
#endif
ClockMatrix clocks;
myTime myTi;
DaliDigit dalDig;
int updateT(void *data) {
  uint32_t time = micros();
  random16_set_seed(time);
  while (1) {
    clocks.setSpeedAll(20, 20);
    if (myTi.getTimeChanged())
      clockLoop(&clocks, &myTi);
    SDL_Delay(1000);
  }
  return 0;
}
void setup() {
  clocks.begin(&cv);
  clocks.setSpeedAll(10, 10);
  dalDig.begin(&cv, &myTi);
  updateThread = SDL_CreateThread(updateT, "updateT", (void *)NULL);
}
int frames = 0;
int main() {
  uint8_t blend = 0;
  setup();
  while (1) {
    cv.clear();
    cv.draw(); // Sets color to white
    // clocks.draw();
    // printf("Blend %d\n\r",blend);
    dalDig.drawClockBlend();
    cv.swapBuffers();
    SDL_Delay(1);
  }
}
