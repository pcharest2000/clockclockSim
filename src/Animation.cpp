#include "Animation.h"

//   for (uint8_t j = 0; j < clocks->getCols(); j++) {
//     for (uint8_t i = 0; i < clocks->getRows(); i++) {
//       if (j & 1) {
//         if (i & 1) {
//           clocks->setTarget(i, j, DEG0 + Turns, -DEG90 + Turns);
//         } else {
//           clocks->setTarget(i, j, DEG0 - Turns, DEG90 - Turns);
//         }
//       } else {
//         if (i & 1) {
//           clocks->setTarget(i, j, -DEG180 - Turns, -DEG90 - Turns);

//         } else {
//           clocks->setTarget(i, j, -DEG180 + Turns, DEG90 + Turns);
//         }
//       }
//     }
//   }
//  }

void aniSquare(ClockMatrix *clock) {
  clock->normalizeAngles();
  const int32_t Turns = DEG360 * 1;
  clock->setSpeedAll(8, 8);
  for (uint8_t j = 0; j < clock->getCols(); j++) {
    for (uint8_t i = 0; i < clock->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clock->setTarget(i, j, DEG0, -DEG90);
        } else {
          clock->setTarget(i, j, DEG0, DEG90);
        }
      } else {
        if (i & 1) {
          clock->setTarget(i, j, -DEG180, -DEG90);
        } else {
          clock->setTarget(i, j, -DEG180, DEG90);
        }
      }
    }
  }
  clock->runToDestination();
  for (uint8_t j = 0; j < clock->getCols(); j++) {
    for (uint8_t i = 0; i < clock->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clock->setTarget(i, j, DEG0 + Turns, -DEG90 + Turns);
        } else {
          clock->setTarget(i, j, DEG0 - Turns, DEG90 - Turns);
        }
      } else {
        if (i & 1) {
          clock->setTarget(i, j, -DEG180 - Turns, -DEG90 - Turns);
        } else {
          clock->setTarget(i, j, -DEG180 + Turns, DEG90 + Turns);
        }
      }
    }
  }
  clock->runToDestination();
}
void aniDiamond(ClockMatrix *clock) {
  // clock->normalizeAngles();
  const int32_t Turns = DEG360 * 4;
  // clock->setSpeedAll(20, 20);
  for (uint8_t j = 0; j < clock->getCols(); j++) {
    for (uint8_t i = 0; i < clock->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clock->setTarget(i, j, DEG225, -DEG45);
        } else {
          clock->setTarget(i, j, DEG135, DEG45);
        }
      } else {
        if (i & 1) {
          clock->setTarget(i, j, DEG135, DEG45);

        } else {
          clock->setTarget(i, j, DEG225, -DEG45);
        }
      }
    }
  }
  clock->runToDestination();
  for (uint8_t j = 0; j < clock->getCols(); j++) {
    for (uint8_t i = 0; i < clock->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clock->setTarget(i, j, DEG225 - Turns, -DEG45 + Turns);
        } else {
          clock->setTarget(i, j, DEG135 + Turns, DEG45 - Turns);
        }
      } else {
        if (i & 1) {
          clock->setTarget(i, j, DEG135 + Turns, DEG45 - Turns);
        } else {
          clock->setTarget(i, j, DEG225 - Turns, -DEG45 + Turns);
        }
      }
    }
  }
  clock->runToDestination();
}

void drawWave(ClockMatrix *clock) {
  clock->normalizeAngles();
  clock->setTargetAll(DEG45, DEG225);
  clock->setSpeedAll(10, 10);
  clock->runToDestination();
  uint32_t turns = DEG360;

  uint32_t delay = 0;
  uint32_t time = micros();
  for (uint32_t i = 0; i < clock->getRows(); i++) {
    for (uint32_t j = 0; j < clock->getCols(); j++) {
      clock->setTargetDelay(time, i, j, DEG45 + turns, DEG225 + turns, delay,
                            delay);
      delay += 10;
    }
    delay += 100;
  }
}
void drawWave2(ClockMatrix *clock) {

uint32_t angle=0;
  for (uint32_t i = 0; i < clock->getRows(); i++) {
    for (uint32_t j = 0; j < clock->getCols(); j++) {
      clock->setTarget( i, j, DEG45+angle  , DEG225+angle);
      angle += 1;
    }
    angle += 2;
  }
}

void drawSquares(ClockMatrix *clock) {
  for (uint8_t j = 0; j < clock->getCols(); j++) {
    for (uint8_t i = 0; i < clock->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clock->setTarget(i, j, DEG0, -DEG90);
        } else {
          clock->setTarget(i, j, DEG0, DEG90);
        }
      } else {
        if (i & 1) {
          clock->setTarget(i, j, -DEG180, -DEG90);
        } else {
          clock->setTarget(i, j, -DEG180, DEG90);
        }
      }
    }
  }
}
void drawRectangles(ClockMatrix *clock) {

  uint8_t hei = clock->getRows() - 1;
  uint8_t wei = clock->getCols() - 1;
  // clock->normalizeAngles();
  // clock->setTargetAll(DEG0, DEG180);
  for (uint8_t j = 0; j < clock->getCols() / 2 + 1; j++) {
    for (uint8_t i = 0; i < clock->getRows() / 2; i++) {
      if (i == j) {
        clock->setTarget(i, j, DEG0, -DEG90);
        clock->setTarget(hei - i, j, DEG0, DEG90);
        clock->setTarget(i, wei - j, -DEG90, DEG180);
        clock->setTarget(hei - i, wei - j, DEG90, DEG180);
      } else if (i > j) {
        clock->setTarget(i, j, DEG90, -DEG90);
        clock->setTarget(hei - i, j, DEG90, -DEG90);
        clock->setTarget(i, wei - j, DEG90, -DEG90);
        clock->setTarget(hei - i, wei - j, DEG90, -DEG90);
      } else if (j > i) {
        clock->setTarget(i, j, DEG0, DEG180);
        clock->setTarget(hei - i, j, DEG0, DEG180);
        clock->setTarget(i, wei - j, DEG0, DEG180);
        clock->setTarget(hei - i, wei - j, DEG0, DEG180);
      }
    }
  }
  // clock->normalizeSpeed(20);
  // clock->runToDestination();
}

void drawDiamond(ClockMatrix *clock) {

  // clock->normalizeAngles();
  uint8_t hei = clock->getRows() - 1;
  uint8_t wei = clock->getCols() - 1;
  for (uint8_t j = 0; j < clock->getCols() / 2 + 1; j++) {
    for (uint8_t i = 0; i < clock->getRows() / 2; i++) {
      clock->setTarget(i, j, DEG45, DEG225);
      clock->setTarget(hei - i, j, DEG135, -DEG45);
      clock->setTarget(i, wei - j, DEG135, -DEG45);
      clock->setTarget(hei - i, wei - j, DEG45, DEG225);
    }
  }
  // clock->normalizeSpeed(20);
  // clock->runToDestination();
}

void drawStairs(ClockMatrix *clock) {
  //  clock->normalizeAngles();
  // clock->setSpeedAll(8, 8);
  for (uint8_t j = 0; j < clock->getCols(); j++) {
    for (uint8_t i = 0; i < clock->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clock->setTarget(i, j, DEG0, DEG90);
        } else {
          clock->setTarget(i, j, DEG180, -DEG90);
        }
      } else {
        if (i & 1) {
          clock->setTarget(i, j, DEG180, -DEG90);
        } else {
          clock->setTarget(i, j, DEG0, DEG90);
        }
      }
    }
  }
}

void drawSwans(ClockMatrix *clock) {
  uint8_t hei = clock->getRows() - 1;
  uint8_t wei = clock->getCols() - 1;
  int8_t iangle = 0;
  int8_t jangle = 0;
  for (uint8_t j = 0; j < clock->getCols(); j++) {
    for (uint8_t i = 0; i < clock->getRows(); i++) {
      clock->setTarget(i, j, DEG45 + iangle, -DEG45 - iangle);
    }
    iangle -= 4;
  }
}
void clockLoop(ClockMatrix *clock,myTime *timeObj) {
  int32_t angleHAnim = random8(1,8)*DEG180;
  int32_t angleMAnim =angleHAnim;
  uint8_t speed = random8(10,20);
  uint8_t randAnim = random8(6);
  // randAnim = 3;
  clock->normalizeAngles();
  switch (randAnim) {
  case 0:
    drawRectangles(clock);
    break;
  case 1:
    drawDiamond(clock);
    break;
  case 2:
    drawStairs(clock);
    break;
  case 3:
    drawSwans(clock);
    angleMAnim=-angleMAnim;
    break;
  case 4:
    drawSquares(clock);
    break;
  case 5:
    drawWave2(clock);
    break;
  case 6:
    drawStairs(clock);
    break;
  }
  clock->normalizeSpeed(20);
  clock->runToDestination();
  clock->runDelay(1000);
  clock->setSpeedAll(speed, speed);
  clock->addTargetAll(angleHAnim, angleMAnim);
  clock->printClockNormalized(timeObj, 20);
  clock->runDelay(3000);
  clock->runToDestination();
  clock->addTargetAll(-angleHAnim, -angleMAnim);
  clock->setSpeedAll(speed, speed);
  clock->printClockNormalized(timeObj, 20);
  clock->runToDestination();
  clock->normalizeAngles();
  clock->setTargetAll(DEG225, DEG225);
  clock->normalizeSpeed(20);
  clock->printClockNormalized(timeObj, 20);
  clock->runToDestination();
}
