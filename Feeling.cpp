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
      left.drawBitmap(0, 0, FLIRT_0_L, 8, 8, LED_ON);
      right.drawBitmap(0, 0, FLIRT_0_R, 8, 8, LED_ON);
      break;

    case DEAD:
      left.drawBitmap(0, 0, DEAD_0_L, 8, 8, LED_ON);
      right.drawBitmap(0, 0, DEAD_0_R, 8, 8, LED_ON);
      break;

    case TIRED:
      break;

      

  }
  aniPos++;

  left.writeDisplay();
  right.writeDisplay();
}
