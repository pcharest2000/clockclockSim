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


void aniSquare(ClockMatrix *clocks) {
  const int32_t Turns = DEG360 * 1;
  clocks->setSpeedAll(8, 8);
  for (uint8_t j = 0; j < clocks->getCols(); j++) {
    for (uint8_t i = 0; i < clocks->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clocks->setTarget(i, j, DEG0, -DEG90);
        } else {
          clocks->setTarget(i, j, DEG0, DEG90);
        }
      } else {
        if (i & 1) {
          clocks->setTarget(i, j, -DEG180, -DEG90);
        } else {
          clocks->setTarget(i, j, -DEG180, DEG90);
        }
      }
    }
  }
  clocks->runToDestination();
  for (uint8_t j = 0; j < clocks->getCols(); j++) {
    for (uint8_t i = 0; i < clocks->getRows(); i++) {
      if (j & 1) {
        if (i & 1) {
          clocks->setTarget(i, j, DEG0 + Turns, -DEG90 + Turns);
        } else {
          clocks->setTarget(i, j, DEG0 - Turns, DEG90 - Turns);
        }
      } else {
        if (i & 1) {
          clocks->setTarget(i, j, -DEG180 - Turns, -DEG90 - Turns);
        } else {
          clocks->setTarget(i, j, -DEG180 + Turns, DEG90 + Turns);
        }
      }
    }
  }
  clocks->runToDestination();
}
void aniDiamond(ClockMatrix *clock) {
  clock->normalizeAngles();
  const int32_t Turns = DEG360 * 4;
  clock->setSpeedAll(8, 8);
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
  delay=0;
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
