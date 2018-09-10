#ifndef Config_h
#define Config_h

#include "Arduino.h"
#include "Feeling.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define BLINK 0
#define ANGRY 1
#define SEARCHING 2
#define TIRED 3
#define FLIRT 4
#define DEAD 5

extern Adafruit_8x8matrix right, left;

#endif
