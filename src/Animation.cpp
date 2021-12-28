#include "Animation.h"

void aniSquare(ClockMatrix *clocks) {
  const int32_t Turns = DEG360 * 1;
  clocks->setSpeedAll(8, 8);
  for (uint8_t j = 0; j < clocks->getCols(); j++) {
    for (uint8_t i = 0; i < clocks->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clocks->setTarget(i, j, DEG0,-DEG90);
        } else {
          clocks->setTarget(i, j, DEG0, DEG90);
        }
      } else {
        if (i & 1) {
          clocks->setTarget(i, j, -DEG180, -DEG90);

        } else {
          clocks->setTarget(i, j ,-DEG180, DEG90);
        }
      }
    }
  }
  clocks->runToDestination();
  for (uint8_t j = 0; j < clocks->getCols(); j++) {
    for (uint8_t i = 0; i < clocks->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clocks->setTarget(i, j, DEG0+Turns,-DEG90+Turns);
        } else {
          clocks->setTarget(i, j, DEG0-Turns, DEG90-Turns);
        }
      } else {
        if (i & 1) {
          clocks->setTarget(i, j, -DEG180-Turns, -DEG90-Turns);

        } else {
          clocks->setTarget(i, j ,-DEG180+Turns, DEG90+Turns);
        }
      }
    }
  }
  clocks->runToDestination();
}
void aniDiamond(ClockMatrix *clocks) {
  const int32_t Turns = DEG360 * 4;
  clocks->setSpeedAll(8, 8);
  for (uint8_t j = 0; j < clocks->getCols(); j++) {
    for (uint8_t i = 0; i < clocks->getRows(); i++) {
      if (j & 1) {

        if (i & 1) {
          clocks->setTarget(i, j, DEG225, -DEG45);
        } else {
          clocks->setTarget(i, j, DEG135, DEG45);
        }
      } else {
        if (i & 1) {
          clocks->setTarget(i, j, DEG135, DEG45);

        } else {
          clocks->setTarget(i, j, DEG225, -DEG45);
        }
      }
    }
  }
  clocks->runToDestination();
  for (uint8_t j = 0; j < clocks->getCols(); j++) {
    for (uint8_t i = 0; i < clocks->getRows(); i++) {
      if (j & 1) {

        if (i & 1) {
          clocks->setTarget(i, j, DEG225 - Turns, -DEG45 + Turns);
        } else {
          clocks->setTarget(i, j, DEG135 + Turns, DEG45 - Turns);
        }
      } else {
        if (i & 1) {
          clocks->setTarget(i, j, DEG135 + Turns, DEG45 - Turns);

        } else {
          clocks->setTarget(i, j, DEG225 - Turns, -DEG45 + Turns);
        }
      }
    }
  }
  clocks->runToDestination();
}
