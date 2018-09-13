#include "Config.h"

Adafruit_8x8matrix right = Adafruit_8x8matrix();
Adafruit_8x8matrix left = Adafruit_8x8matrix();
Feeling feeling = Feeling();

void setup() {
  Serial.begin(115200);
  Serial.println("8x8 LED Matrix Test");
  
  feeling.init();
  feeling.searching();
}

void loop() {
  feeling.frame();
  delay(150);
}
