#include "dali_digit.h"

 const  dali_digit_t *digits[] = {
    &DIGIT_INFO(zero),
    &DIGIT_INFO(one),
    &DIGIT_INFO(two),
    &DIGIT_INFO(three),
    &DIGIT_INFO(four),
    &DIGIT_INFO(five),
    &DIGIT_INFO(six),
    &DIGIT_INFO(seven),
    &DIGIT_INFO(eight),
    &DIGIT_INFO(nine),
    &DIGIT_INFO(colon),
    &DIGIT_INFO(slash)
  };
DaliDigit::DaliDigit() {}
DaliDigit::DaliDigit(Canvas *cv) { _cv = cv; }
void DaliDigit::begin(Canvas *cv) { _cv = cv; }

void DaliDigit::draw(uint8_t num,uint32_t ix, uint32_t jx) {
    if(num>9)
        return;
  uint32_t x = 0;
  uint32_t x2 = 0;
  uint32_t width1 = 0;
  uint32_t width2 = 0;

  for (uint32_t j = 0; j < 131; j++) {
    x = digits[num]->packed_rle[0 + j * 4];
    width1 = digits[num]->packed_rle[1 + j * 4];
    x2 = digits[num]->packed_rle[2 + j * 4] + x + width1;
    width2 = digits[num]->packed_rle[3 + j * 4];
    _cv->drawLine(x+ix, j, x+ix + width1, j);
    if (width2 != 0) {
      _cv->drawLine(x2+ix, j, x2+ix + width2, j);
    }
  }
}
void DaliDigit::draw() {
  uint32_t iIndex = 0;
  uint32_t x = 0;
  uint32_t x2 = 0;
  uint32_t width1 = 0;
  uint32_t width2 = 0;

  for (uint32_t j = 0; j < 131; j++) {
    x = oneC3_rle[0 + j * 4];
    width1 = oneC3_rle[1 + j * 4];
    x2 = oneC3_rle[2 + j * 4] + x + width1;
    width2 = oneC3_rle[3 + j * 4];
    _cv->drawLine(x, j, x + width1, j);
    if (width2 != 0) {
      _cv->drawLine(x2, j, x2 + width2, j);
    }
  }
}

void DaliDigit::draw(uint8_t blend) {
  uint8_t start[4], final[4];
  for (uint32_t j = 0; j < 131; j++) {
    start[0] = oneC3_rle[0 + j * 4];
    start[1] = oneC3_rle[1 + j * 4];
    start[2] = oneC3_rle[2 + j * 4];
    start[3] = oneC3_rle[3 + j * 4];
    final[0] = twoC3_rle[0 + j * 4];
    final[1] = twoC3_rle[1 + j * 4];
    final[2] = twoC3_rle[2 + j * 4];
    final[3] = twoC3_rle[3 + j * 4];
    blend_rle(start, final, blend);
    _cv->drawLine(final[0], j, final[1], j);
    if (final[3] != 0) {
      _cv->drawLine(final[2], j, final[3], j);
      //   x = oneC3_rle[0 + j * 4];
      // width1 = oneC3_rle[1 + j * 4];
      // x2 = oneC3_rle[2 + j * 4]+x+width1;
      // width2 = oneC3_rle[3 + j * 4];
      // _cv->drawLine(x, j, x + width1, j);
      // if(width2!=0){
      // _cv->drawLine(x2, j, x2 + width2, j);
    }
  }
}

void DaliDigit::rle_to_segment_endpoints(uint8_t rle[]) {
  if (rle[3] != 0) {
    rle[1] = rle[0] + rle[1];
    rle[2] = rle[1] + rle[2];
    rle[3] = rle[2] + rle[3];
  } else {
    rle[1] = rle[0] + rle[1];
    rle[2] = rle[0];
    rle[3] = rle[1];
  }
}

void DaliDigit::segment_endpoints_to_rle(uint8_t rle[]) {
  if (rle[2] > rle[1]) {
    rle[3] -= rle[2];
    rle[2] -= rle[1];
    rle[1] -= rle[0];
  } else {
    rle[1] = rle[3] - rle[0];
    rle[2] = 0;
    rle[3] = 0;
  }
}

void DaliDigit::blend_rle(uint8_t start[4], uint8_t final[], uint8_t blend) {
  rle_to_segment_endpoints(start);
  rle_to_segment_endpoints(final);
  for (uint8_t i = 0; i < 4; i++) {
    final[i] = ((256 - blend) * start[i] + blend * final[i]) / 256;
  }
  //segment_endpoints_to_rle(final);
}
