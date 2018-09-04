#ifndef Feeling_h
#define Feeling_h

#include "Config.h"

class Feeling {
  public:
    Feeling();
    void frame();
    void angry();
    void blink();
    void searching();
    void tired();
    void flirt();
    void dead();
  private:
    void setState(byte s);
    byte state = 0;
    unsigned int aniPos = 0; 
};

static const uint8_t PROGMEM
BLINK_0_L[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
},
BLINK_0_R[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
},
BLINK_1_L[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10111101,
  B10000001,
  B01000010,
  B00111100
},
BLINK_1_R[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10111101,
  B10000001,
  B01000010,
  B00111100
},
BLINK_2_L[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
},
BLINK_2_R[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};

#endif
