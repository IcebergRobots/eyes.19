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
      bitmap(FLIRT_FRAMES, 0);
      break;

    case DEAD:
      left.drawBitmap(0, 0, DEAD_0_L, 8, 8, LED_ON);
      right.drawBitmap(0, 0, DEAD_0_R, 8, 8, LED_ON);
      break;

    case TIRED:
      if (aniPos <= 0) {
        left.drawBitmap(0, 0, TIRED_0_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, TIRED_0_R, 8, 8, LED_ON);
      } else if (aniPos == 1 || aniPos == 2) {
        left.drawBitmap(0, 0, TIRED_1_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, TIRED_1_R, 8, 8, LED_ON);
      } else if (aniPos == 3 || aniPos == 4) {
        left.drawBitmap(0, 0, TIRED_2_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, TIRED_2_R, 8, 8, LED_ON);
      } else if (aniPos == 5 || aniPos == 6) {
        left.drawBitmap(0, 0, TIRED_3_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, TIRED_3_R, 8, 8, LED_ON);
      } else {
        left.drawBitmap(0, 0, TIRED_4_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, TIRED_4_R, 8, 8, LED_ON);
      }
      break;

    case SEARCHING:
      if (aniPos <= 0) {
        left.drawBitmap(0, 0, SEARCHING_0_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_0_R, 8, 8, LED_ON);
      } else if (aniPos == 1 || aniPos == 2) {
        left.drawBitmap(0, 0, SEARCHING_1_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_1_R, 8, 8, LED_ON);
      } else if (aniPos == 3 || aniPos == 4) {
        left.drawBitmap(0, 0, SEARCHING_2_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_2_R, 8, 8, LED_ON);
      } else if (aniPos >= 8 && aniPos % 8 == 0) {                  //ab hier
        left.drawBitmap(0, 0, SEARCHING_3_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_3_R, 8, 8, LED_ON);
      } else if (aniPos >= 8 && aniPos % 8 == 1 || aniPos % 8 == 2 || aniPos % 8 == 3) {                      //extrem
        left.drawBitmap(0, 0, SEARCHING_4_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_4_R, 8, 8, LED_ON);
      } else if (aniPos >= 8 && aniPos % 8 == 4) {
        left.drawBitmap(0, 0, SEARCHING_5_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_5_R, 8, 8, LED_ON);
      } else if (aniPos >= 8 && aniPos % 8 == 5 || aniPos % 8 == 6 || aniPos % 8 == 7) {                     //extrem
        left.drawBitmap(0, 0, SEARCHING_6_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_6_R, 8, 8, LED_ON);
      } else {
        left.drawBitmap(0, 0, SEARCHING_2_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, SEARCHING_2_R, 8, 8, LED_ON);
        aniPos = 5;
      }
      break;
  }
  aniPos++;

  left.writeDisplay();
  right.writeDisplay();
}

void Feeling::bitmap(byte frame[], byte index) {
  for (int row = 0; row < 8; row++) {
    byte bitlineLeft[] = {frame[index*8+row]};
    byte bitlineRight[] = {reverse(frame[index*8+row])};
    //const byte bitlineLeft[] = {reverse(/*frame[index*8+i]*/)};

    //byte a = B10101010;
    //byte b = reverse(B10101010);
    //byte p[] = {a};
    left.drawBitmap(0, row, bitlineLeft, 8, 1, LED_ON);
    right.drawBitmap(0, row, bitlineRight, 8, 1, LED_ON);
  }
}

byte Feeling::reverse(byte in) {
  byte out = 0;
  if (in & 0x01) out |= 0x80;
  if (in & 0x02) out |= 0x40;
  if (in & 0x04) out |= 0x20;
  if (in & 0x08) out |= 0x10;
  if (in & 0x10) out |= 0x08;
  if (in & 0x20) out |= 0x04;
  if (in & 0x40) out |= 0x02;
  if (in & 0x80) out |= 0x01;
  return out;
}

