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
  clock->normalizeAngles();
  const int32_t Turns = DEG360 * 4;
  clock->setSpeedAll(20, 20);
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

void aniWave(ClockMatrix *clock, myTime *timeObj) {
  clock->normalizeAngles();
  clock->setSpeedAll(20, 20);
  clock->setTargetAll(DEG45, DEG225);
  clock->runToDestination();
  uint32_t turns = DEG360;
  uint32_t time = micros();
  clock->setSpeedAll(10, 10);
  uint32_t delay2 = 0;
  uint32_t delay = 0;
  for (uint32_t i = 0; i < clock->getRows(); i++) {
    for (uint32_t j = 0; j < clock->getCols(); j++) {
      clock->setTargetDelay(time, i, j, DEG45 + turns, DEG225 + turns, delay,
                            delay);
      delay += 10;
    }
    delay += 100;
  }
  clock->runDelay(4000);
  clock->printClockNormalized(timeObj, 20);
  clock->runToDestination();
  time = micros();
  delay = 0;
  for (uint32_t i = 0; i < clock->getRows(); i++) {
    for (uint32_t j = 0; j < clock->getCols(); j++) {
      clock->setTargetDelay(time, i, j, DEG45, DEG225, delay, delay);
      delay += 10;
    }
    delay += 100;
  }
  clock->printClockNormalized(timeObj, 20);
  clock->runToDestination();
}

void drawSquares(ClockMatrix *clock) {

  uint8_t hei = clock->getRows() - 1;
  uint8_t wei = clock->getCols() - 1;
  clock->normalizeAngles();
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
  clock->normalizeSpeed(20);
  clock->runToDestination();
}

void drawDiamond(ClockMatrix *clock) {

  clock->normalizeAngles();
  uint8_t hei = clock->getRows() - 1;
  uint8_t wei = clock->getCols() - 1;
  for (uint8_t j = 0; j < clock->getCols() / 2 + 1; j++) {
    for (uint8_t i = 0; i < clock->getRows() / 2; i++) {
        clock->setTarget(i, j, DEG45, DEG225);
        clock->setTarget(hei - i, j,DEG135, -DEG45);
        clock->setTarget(i, wei - j, DEG135, -DEG45);
        clock->setTarget(hei - i, wei - j, DEG45, DEG225);
    }
  }
  clock->normalizeSpeed(20);
  clock->runToDestination();
}

void drawStairs(ClockMatrix *clock){
  clock->normalizeAngles();
  clock->setSpeedAll(8, 8);
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
  clock->normalizeSpeed(20);
  clock->runToDestination();
  clock->addTargetAll(DEG90, DEG90);
  clock->normalizeSpeed(20);
  clock->runDelay(2000);
  clock->runToDestination();
  clock->addTargetAll(-DEG90, -DEG90);
  clock->normalizeSpeed(20);
  clock->runDelay(2000);
  clock->runToDestination();
}

void drawSwans(ClockMatrix *clock) {

  clock->normalizeAngles();
  uint8_t hei = clock->getRows() - 1;
  uint8_t wei = clock->getCols() - 1;
  int8_t iangle=0;
  int8_t jangle=0;
  for (uint8_t j = 0; j < clock->getCols()  ; j++) {
    for (uint8_t i = 0; i < clock->getRows() ; i++) {
        clock->setTarget(i, j, DEG45+iangle, -DEG45-iangle);
    }
        iangle-=4;
  }
  clock->normalizeSpeed(20);
  clock->runToDestination();
  clock->setSpeedAll(10, 10);
  clock->addTargetAll(3*STEPSPER360, -3*STEPSPER360);
  clock->runToDestination();
  clock->normalizeAngles();
}
