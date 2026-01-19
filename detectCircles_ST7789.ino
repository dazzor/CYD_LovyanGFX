#include <LovyanGFX.hpp>
#include "lovyanGFX_ST7789.h"

static LGFX lcd;

//uint16_t touch_point[8];
//uint16_t x1
//uint16_t y1
//uint16_t x2
//uint16_t y2
//uint16_t x3
//uint16_t y3
//uint16_t x4
//uint16_t y4

uint16_t touch_point[8] = {3828, 202, 3728, 3651, 430, 212, 416, 3625};


void setup(void) {
  Serial.begin(115200);
  lcd.init();                   // Call the initialization function first.
  lcd.setRotation(0);           // Set the rotation direction from 4 directions from 0~3.(If you use 4~7, it will be upside down.))

//  lcd.calibrateTouch(touch_point, TFT_BLACK, TFT_YELLOW);
//  lcd.clear();

//  for (int i=0; i<8; i++) {
//    lcd.printf("%4x:", touch_point[i]);
//  }

  lcd.setTouchCalibrate(touch_point);

  lcd.setBrightness(128);       // Set the brightness of the backlight in the range of 0~255.
  lcd.setColorDepth(24);        // Set to RGB888 24-bit
  lcd.fillScreen(TFT_BLUE); // Fill the entire screen
  lcd.drawCircle (100, 100, 10, TFT_YELLOW);
  Serial.print("width = "); Serial.println(lcd.width());
  Serial.print("height = "); Serial.println(lcd.height());
}

void loop(void) {
  uint16_t tX, tY;
  bool touched = lcd.getTouch(&tX, &tY);
  if( touched ) {
    Serial.println("touched (" + String(tX) + "," + String(tY) + ")");
    lcd.setColor(TFT_YELLOW);
    lcd.drawCircle (tX, tY, 10, TFT_YELLOW);
  }
}