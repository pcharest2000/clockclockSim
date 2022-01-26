#include "stars.h"

Stars::Stars() {}
void Stars::begin(Canvas *cv) {
  _cv = cv;
  _centerX = _cv->getWidth() / 2;
  _centerY = _cv->getHeight() / 2;
  for (int i = 0; i < NUM_STARS; i++) {
    _reSpawn(i);
  }
}

void Stars::draw() {
  for (int i = 0; i < NUM_STARS; i++) {
    _cv->drawRectangle(_starAr[i].x, _starAr[i].y, _starAr[i].x + 3,
                       _starAr[i].y + 3);
    update();
  }
}
void Stars::update() {
  for (int i = 0; i < NUM_STARS; i++) {

    _starAr[i].speedX += _starAr[i].acceX;
    _starAr[i].speedY += _starAr[i].acceY;
    _starAr[i].x += _starAr[i].speedX;
    _starAr[i].y += _starAr[i].speedY;

    if (_starAr[i].x > _cv->getWidth() || _starAr[i].y > _cv->getHeight()) {
      _reSpawn(i);
      return;
    }
    if (_starAr[i].x < 0 || _starAr[i].y < 0) {
      _reSpawn(i);
    }
  }
}
void Stars::_reSpawn(uint8_t i) {

  float sinr = ((float)sin8(random8()) - 128) / 256.0;
  float cosr = ((float)cos8(random8()) - 128) / 256.0;
  _starAr[i].x = _centerX + (STAR_R * cosr);
  _starAr[i].y = _centerY + (STAR_R * sinr);
  _starAr[i].speedX = 0;
  _starAr[i].speedY = 0;
  _starAr[i].acceX = ((float)random8() / 2060000000.0 * cosr);
  _starAr[i].acceY = ((float)random8() / 2060000000.0 * sinr);
}
