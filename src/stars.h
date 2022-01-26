#ifndef STARS_H_
#define STARS_H_

#include "config.h"
#include "dali_font_C3.h"
#include "lib8tion.h"
#include "myTime.h"
#include <cstdint>
#ifndef SIM
#include "fabgl.h"
#else
#include "Canvas.h"
#include <chrono>
uint32_t micros();
#endif

#define NUM_STARS 200
#define STAR_R 60 // Minimum start radius
struct stars {
  float x;
  float y;
  float speedX;
  float speedY;
  float acceX;
  float acceY;
};
class Stars {
public:
  Stars();
  void begin(Canvas *cv);
  void draw();
  void update();

private:
  Canvas *_cv;
  stars _starAr[NUM_STARS];
  int _centerX;
  int _centerY;
  void _reSpawn(uint8_t i);
};

#endif // STARS_H_
