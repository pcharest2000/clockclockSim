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

void aniWave(ClockMatrix *clock, myTime *timeObj) {

  clock->setTargetAll(DEG45, DEG225);
  clock->runToDestination();
  uint32_t turns = DEG360 * 2;
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
  // timeObj->getTime();
  // clock->printClock(timeObj->hourTenth, timeObj->hourDigit, timeObj->minTenth,
  //                   timeObj->minDigit);
  // clock->normalizeSpeedBox(2, 1, 6, 6, 10);
  // clock->normalizeSpeedBox(8, 1, 6, 6, 10);
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
  // clock->printClock(timeObj->hourTenth, timeObj->hourDigit, timeObj->minTenth,
  //                   timeObj->minDigit);
  // clock->normalizeSpeedBox(2, 1, 6, 6, 10);
  // clock->normalizeSpeedBox(8, 1, 6, 6, 10);
  clock->runToDestination();
}
