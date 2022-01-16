#include "dali_digit.h"

const dali_digit_t *digits[] = {
    &DIGIT_INFO(zero),  &DIGIT_INFO(one),   &DIGIT_INFO(two),
    &DIGIT_INFO(three), &DIGIT_INFO(four),  &DIGIT_INFO(five),
    &DIGIT_INFO(six),   &DIGIT_INFO(seven), &DIGIT_INFO(eight),
    &DIGIT_INFO(nine),  &DIGIT_INFO(colon), &DIGIT_INFO(slash)};

DaliDigit::DaliDigit() {}

DaliDigit::DaliDigit(Canvas *cv) { _cv = cv; }

void DaliDigit::begin(Canvas *cv, myTime *tm) {
  _tm = tm;
  _cv = cv;
  _digitWidth = digits[0]->width;
  _digitHeigth = digits[0]->height;
  _colwidth = digits[10]->width;
  _xclockoffset = (_cv->getWidth() - 6 * _digitWidth - 2 * _colwidth) / 2;
  _yclockoffset = (_cv->getHeight() - _digitHeigth) / 2;
}

void DaliDigit::drawDigitBlend(uint8_t numFrom, uint8_t numTo, int ix, int jx,
                               uint8_t blend) {
  if (numFrom > 9 || numTo > 9)
    return;
  uint8_t start[4], final[4];
  for (uint32_t j = 0; j < 131; j++) {
    start[0] = digits[numFrom]->packed_rle[0 + j * 4];
    start[1] = digits[numFrom]->packed_rle[1 + j * 4];
    start[2] = digits[numFrom]->packed_rle[2 + j * 4];
    start[3] = digits[numFrom]->packed_rle[3 + j * 4];
    final[0] = digits[numTo]->packed_rle[0 + j * 4];
    final[1] = digits[numTo]->packed_rle[1 + j * 4];
    final[2] = digits[numTo]->packed_rle[2 + j * 4];
    final[3] = digits[numTo]->packed_rle[3 + j * 4];

    blend_rle(start, final, blend);
    _cv->drawLine(final[0] + ix, j + jx, final[1] + ix, j + jx);
    if (final[3] != 0) {
      _cv->drawLine(final[2] + ix, j + jx, final[3] + ix, j + jx);
    }
  }
}
void DaliDigit::drawDigit(uint8_t num, int ix, int jx) {
  if (num > 12)
    return;
  uint32_t x = 0;
  uint32_t x2 = 0;
  uint32_t width1 = 0;
  uint32_t width2 = 0;

  for (uint32_t j = 0; j < 131; j++) {
    x = digits[num]->packed_rle[0 + j * 4];
    width1 = digits[num]->packed_rle[1 + j * 4];
    if (width1 == 0)
      continue;
    x2 = digits[num]->packed_rle[2 + j * 4] + x + width1;
    width2 = digits[num]->packed_rle[3 + j * 4];
    _cv->drawLine(x + ix, j + jx, x + ix + width1, j + jx);
    if (width2 != 0) {
      _cv->drawLine(x2 + ix, j + jx, x2 + ix + width2, j + jx);
    }
  }
}

void DaliDigit::draw(uint8_t num, uint8_t num2, uint32_t ix, uint32_t jx,
                     uint8_t blend) {
  if (num > 9)
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
    _cv->drawLine(x + ix, j, x + ix + width1, j);
    if (width2 != 0) {
      _cv->drawLine(x2 + ix, j, x2 + ix + width2, j);
    }
  }
}

void DaliDigit::drawClockBlend() {
  uint32_t xpos = _xclockoffset;
  static uint32_t aniBlend = 0;
  static uint32_t secBlend = 0;
  static bool secondAnimFlag = false;
  static bool animationFlag = false;

  if (animationFlag == false && _tm->getTimeChanged()) {
    animationFlag = true;
    aniBlend = 0;
  }
  if (animationFlag) {
    aniBlend += 2;
    if (aniBlend > 255) {
      aniBlend = 255;
      animationFlag = false;
    }
    drawDigitBlend(_tm->prevHourTenth, _tm->hourTenth, xpos, _yclockoffset,
                   aniBlend);
    xpos += _digitWidth;
    drawDigitBlend(_tm->prevHourDigit, _tm->hourDigit, xpos, _yclockoffset,
                   aniBlend);
    xpos += _digitWidth;
    drawDigit(10, xpos, _yclockoffset);
    xpos += _colwidth;
    drawDigitBlend(_tm->prevMinTenth, _tm->minTenth, xpos, _yclockoffset,
                   aniBlend);
    xpos += _digitWidth;
    drawDigitBlend(_tm->prevMinDigit, _tm->minDigit, xpos, _yclockoffset,
                   aniBlend);
    xpos += _digitWidth;
    drawDigit(10, xpos, _yclockoffset);
    xpos += _colwidth;
    drawDigitBlend(_tm->prevSecTenth, _tm->secTenth, xpos, _yclockoffset,
                   aniBlend);
    xpos += _digitWidth;
    drawDigitBlend(_tm->prevSecDigit, _tm->secDigit, xpos, _yclockoffset,
                   aniBlend);
    return;
  } else {

    drawDigit(_tm->hourTenth, xpos, _yclockoffset);
    xpos += _digitWidth;
    drawDigit(_tm->hourDigit, xpos, _yclockoffset);
    xpos += _digitWidth;
    drawDigit(10, xpos, _yclockoffset);
    xpos += _colwidth;
    drawDigit(_tm->minTenth, xpos, _yclockoffset);
    xpos += _digitWidth;
    drawDigit(_tm->minDigit, xpos, _yclockoffset);
    xpos += _digitWidth;
    drawDigit(10, xpos, _yclockoffset);
    xpos += _colwidth;
  }

  if (secondAnimFlag == false && _tm->getTimeChangedSeconds()) {
    secondAnimFlag = true;
    secBlend = 0;
  }
  if (secondAnimFlag) {
    secBlend += 4;
    if (secBlend > 255) {
      secBlend = 255;
      secondAnimFlag = false;
    }
    drawDigitBlend(_tm->prevSecTenth, _tm->secTenth, xpos, _yclockoffset,
                   secBlend);
    xpos += _digitWidth;
    drawDigitBlend(_tm->prevSecDigit, _tm->secDigit, xpos, _yclockoffset,
                   secBlend);
  } else {

    // drawDigit(_tm->hourTenth, xpos, _yclockoffset);
    // xpos += _digitWidth;
    // drawDigit(_tm->hourDigit, xpos, _yclockoffset);
    // xpos += _digitWidth;
    // drawDigit(10, xpos, _yclockoffset);
    // xpos += _colwidth;
    // drawDigit(_tm->minTenth, xpos, _yclockoffset);
    // xpos += _digitWidth;
    // drawDigit(_tm->minDigit, xpos, _yclockoffset);
    // xpos += _digitWidth;
    // drawDigit(10, xpos, _yclockoffset);
    // xpos += _colwidth;
    drawDigit(_tm->secTenth, xpos, _yclockoffset);
    xpos += _digitWidth;
    drawDigit(_tm->secDigit, xpos, _yclockoffset);
  }
}
void DaliDigit::drawClock() {
  uint32_t xpos = _xclockoffset;
  drawDigit(_tm->hourTenth, xpos, _yclockoffset);
  xpos += _digitWidth;
  drawDigit(_tm->hourDigit, xpos, _yclockoffset);
  xpos += _digitWidth;
  drawDigit(10, xpos, _yclockoffset);
  xpos += _colwidth;
  drawDigit(_tm->minTenth, xpos, _yclockoffset);
  xpos += _digitWidth;
  drawDigit(_tm->minDigit, xpos, _yclockoffset);
  xpos += _digitWidth;
  drawDigit(10, xpos, _yclockoffset);
  xpos += _colwidth;
  drawDigit(_tm->secTenth, xpos, _yclockoffset);
  xpos += _digitWidth;
  drawDigit(_tm->secDigit, xpos, _yclockoffset);
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
  // segment_endpoints_to_rle(final);
}
