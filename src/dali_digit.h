/****************************************************************************
 *   DaliClock by (c) 2018 Marcio Teixeira                               *
 *                                                                          *
 *   This program is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by   *
 *   the Free Software Foundation, either version 3 of the License, or      *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   To view a copy of the GNU General Public License, go to the following  *
 *   location: <http://www.gnu.org/licenses/>.                              *
 ****************************************************************************/

#ifndef _DALI_DIGIT_H_
#define _DALI_DIGIT_H_

#include "config.h"
#include "dali_font_C3.h"
#include <cstdint>

#ifndef SIM
#include "fabgl.h"
#else
#include "Canvas.h"
#include <chrono>
uint32_t micros();
#define PROGMEM       //
#define pgm_read_word //
#endif

class DaliDigit {
public:
  DaliDigit();
  DaliDigit(Canvas *cv);
  void begin(Canvas *cv);
  void draw();
  void draw(uint8_t blend);
  void draw(uint8_t num, uint32_t ix, uint32_t jx);
  static void load_digit(uint32_t addr, const dali_digit_t &d1,
                         const dali_digit_t &d2, uint8_t blend);
  static void load_digit(uint32_t addr, uint8_t d1, uint8_t d2, uint8_t blend);
  static void load_digit(uint32_t addr, float digit, uint8_t wrap = 9);
  static void load_colon(uint32_t addr);

private:
  Canvas *_cv;
  static void rle_to_segment_endpoints(uint8_t rle[]);
  static void segment_endpoints_to_rle(uint8_t rle[]);
  static void blend_rle(uint8_t start[4], uint8_t final[], uint8_t blend);
};

#endif // _DALI_DIGIT_H_
