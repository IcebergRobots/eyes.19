#include "Feeling.h"

Feeling::Feeling() {}

void Feeling::init() {
  left.begin(0x71);  // pass in the address
  right.begin(0x70);
  Serial.println("set stuff");
}

void Feeling::setState(byte s) {
  if (s != state) {
    state = s;
    aniPos = 0;
  }
}

void Feeling::blink() {
  setState(BLINK);
}

void Feeling::angry() {
  setState(ANGRY);
}

void Feeling::searching() {
  setState(SEARCHING);
}

void Feeling::tired() {
  setState(TIRED);
}

void Feeling::flirt() {
  setState(FLIRT);
}

void Feeling::dead() {
  setState(DEAD);
}

void Feeling::frame() {
  left.clear();
  right.clear();

  switch (state) {
    case BLINK:
      if (aniPos <= 0) {
        left.drawBitmap(0, 0, BLINK_0_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_0_R, 8, 8, LED_ON);
      } else if (aniPos <= 1) {
        left.drawBitmap(0, 0, BLINK_1_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_1_R, 8, 8, LED_ON);
      } else if (aniPos <= 2) {
        left.drawBitmap(0, 0, BLINK_2_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_2_R, 8, 8, LED_ON);
      } else if (aniPos <= 3) {
        left.drawBitmap(0, 0, BLINK_3_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_3_R, 8, 8, LED_ON);
      } else if (aniPos <= 4) {
        left.drawBitmap(0, 0, BLINK_2_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_2_R, 8, 8, LED_ON);
      } else if (aniPos <= 5) {
        left.drawBitmap(0, 0, BLINK_1_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_1_R, 8, 8, LED_ON);
      } else {
        left.drawBitmap(0, 0, BLINK_0_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_0_R, 8, 8, LED_ON);
        aniPos = random(-30, -5);
      }
      break;

    case FLIRT:
      bitmap(FLIRT_0_L, FLIRT_0_R);
      break;

    case DEAD:
      bitmap(DEAD_0_L, DEAD_0_R);
      break;

    case TIRED:
      if (aniPos <= 0)      bitmap(TIRED_0_L, TIRED_0_R);
      else if (aniPos <= 2) bitmap(TIRED_1_L, TIRED_1_R);
      else if (aniPos <= 4) bitmap(TIRED_2_L, TIRED_2_R);
      else if (aniPos <= 6) bitmap(TIRED_3_L, TIRED_3_R);
      else                  bitmap(TIRED_4_L, TIRED_4_R);
      break;

    case SEARCHING:
      aniPos %= 12;
      if      (aniPos <= 0 || aniPos >= 11) bitmap(SEARCHING_0_L, SEARCHING_0_R);
      else if (aniPos <= 1 || aniPos >= 10) bitmap(SEARCHING_1_L, SEARCHING_1_R);
      else if (aniPos <= 2 || aniPos >= 9)  bitmap(SEARCHING_2_L, SEARCHING_2_R);
      else if (aniPos <= 3 || aniPos >= 8)  bitmap(SEARCHING_3_L, SEARCHING_3_R);
      else if (aniPos <= 4 || aniPos >= 7)  bitmap(SEARCHING_4_L, SEARCHING_4_R);
      else                                  bitmap(SEARCHING_5_L, SEARCHING_5_R);
      break;
  }
  aniPos++;

  left.writeDisplay();
  right.writeDisplay();
}

void Feeling::bitmap(const byte bitmapLeft[], const byte bitmapRight[]) {
  left.drawBitmap(0, 0, bitmapLeft, 8, 8, LED_ON);
  right.drawBitmap(0, 0, bitmapRight, 8, 8, LED_ON);
}

