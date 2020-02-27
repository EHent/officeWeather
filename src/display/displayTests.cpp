#include <Wire.h>  
#include "SH1106Wire.h"

#include "displayTests.hpp"


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

namespace Display
{
DisplayTests::DisplayTests():display(0x3c, SDA, SCL, GEOMETRY_128_64)
{
    
}

DisplayTests::~DisplayTests()
{
    ;
}

void DisplayTests::init(){
    // just initialize the display
    display.init();
}

void DisplayTests::firstTest(const char* s){
  display.drawCircle(64, 16, 8);
  display.drawString(64, 16, "Hallo");
  display.drawString(40, 40, "Does it snow?");
  display.drawString(1, 1, s);
  display.setPixel(0,1);
  //display.setPixel(128,10);
  //display.setPixel(128,60);
  display.setPixel(0,64);
  //display.setPixel(18,40);
  display.setPixel(0,30);
  display.display();
  delay(3000);

  display.invertDisplay();
  display.display();
  delay(3000);

  display.clear();
  display.display();
  delay(3000);

  display.normalDisplay();
  display.display();
  delay(3000);
}
}