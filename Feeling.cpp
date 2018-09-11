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

void Feeling::frame() {
  switch (state) {
    case BLINK:
      if (aniPos == 0) aniPos = random(1, 30);
      aniPos %= 52;
      if (aniPos < 50) {
        left.drawBitmap(0, 0, BLINK_0_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_0_R, 8, 8, LED_ON);
      } else if (aniPos < 51) {
        left.drawBitmap(0, 0, BLINK_1_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_1_R, 8, 8, LED_ON);
      } else {
        left.drawBitmap(0, 0, BLINK_2_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_2_R, 8, 8, LED_ON);
      }
      break;
  }

  left.writeDisplay();
  right.writeDisplay();
  aniPos++;
}


