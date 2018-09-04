#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix right = Adafruit_8x8matrix();
Adafruit_8x8matrix left = Adafruit_8x8matrix();

static const uint8_t PROGMEM
smile_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
},
neutral_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10111101,
  B10000001,
  B01000010,
  B00111100
},
frown_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};

void setup() {
  Serial.begin(115200);
  Serial.println("8x8 LED Matrix Test");

  left.begin(0x71);  // pass in the address
  right.begin(0x70);
}

void loop() {
  left.clear();
  left.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
  left.writeDisplay();
  right.clear();
  right.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
  right.writeDisplay();
}
