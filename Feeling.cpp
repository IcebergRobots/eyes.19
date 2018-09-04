#include "Feeling.h"

Feeling::Feeling() {
  left.begin(0x71);  // pass in the address
  right.begin(0x70);
}

void Feeling::setState(byte s){
  if(s != state){
  state = s;
  aniPos = 0;
  }
}

void Feeling::blink(){
  setState(BLINK);
}

void Feeling::frame() {
  //switch (state) {
    //case BLINK:
      if (aniPos == 0) aniPos = random(1,30);
      if (aniPos < 50) {
        left.drawBitmap(0, 0, BLINK_0_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_0_R, 8, 8, LED_ON);
      } else if (aniPos < 51) {
        left.drawBitmap(0, 0, BLINK_1_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_1_R, 8, 8, LED_ON);
      } else if (aniPos < 52) {
        left.drawBitmap(0, 0, BLINK_2_L, 8, 8, LED_ON);
        right.drawBitmap(0, 0, BLINK_2_R, 8, 8, LED_ON);
      } else {
        aniPos = 0;
      }
      //break;
  //}

  left.writeDisplay();
  right.writeDisplay();
  aniPos++;
}


