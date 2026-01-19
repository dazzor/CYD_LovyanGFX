#include <LovyanGFX.hpp>
#include "lovyanGFX_ST7789.h"

static LGFX display;

uint16_t touch_point[8];

void setup() {
  Serial.begin(115200);
  display.begin();
  display.setRotation(3);
  display.calibrateTouch(touch_point, TFT_BLACK, TFT_YELLOW);
  display.clear();

  for (int i=0; i<8; i++) {
    display.printf("%4x:", touch_point[i]);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
}



//By passing a pointer to a uint16_t[8] as the first argument, 
//you can obtain calibration values that can be used with setTouchCalibrate.
//By saving these values to flash memory or similar storage 
//and using setTouchCalibrate on the next startup, you can skip manual calibration.
