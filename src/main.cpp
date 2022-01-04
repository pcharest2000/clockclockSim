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
#include "dali_font_C3.h"
#include "dali_digit.h"
SDL_Thread *updateThread = NULL;
#ifdef SIM
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
    if(myTi.getTimeChanged())
    clockLoop(&clocks,&myTi);
    SDL_Delay(1000);
  }
  return 0;
}
void setup() {
  clocks.begin(&cv);
  clocks.setSpeedAll(10, 10);
  dalDig.begin(&cv);
  updateThread = SDL_CreateThread(updateT, "updateT", (void *)NULL);
}
int frames = 0;
int main() {
  uint8_t blend=0;
  setup();
  while (1) {
    cv.clear();
    cv.draw(); //Sets color to white
    clocks.draw();
    //printf("Blend %d\n\r",blend);
    dalDig.draw(6,300,0);
    dalDig.draw(5,200,0);
    dalDig.draw(4,100,0);
    dalDig.draw(3,0,0);
    cv.swapBuffers();
    SDL_Delay(1);
    blend++;
  }
}
