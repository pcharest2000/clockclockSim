#ifndef DIGITS_H
#define DIGITS_H
#include "clock.h"

#define DIGITW 3
#define DIGITH 6

typedef struct {
  int32_t minPosition; // Positions are mapped from 0-360 deg from 0-2048
  int32_t hourPosition;
} digitS;

typedef const int32_t digitA[DIGITW][DIGITH][2];
digitA *getDigitPtr(uint8_t digit);
#endif // DIGITS_H
