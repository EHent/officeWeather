#include <Wire.h>  
#include "SH1106Wire.h"
#include <sstream>
#include "displayTests.hpp"


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

namespace Display
{
DisplayTests::DisplayTests(BME::BME280* _pBmeSensor):
    display(0x3c, SDA, SCL, GEOMETRY_128_64),
    pBmeSensor(_pBmeSensor)
{
    
}

DisplayTests::~DisplayTests()
{
    ;
}

void DisplayTests::init(){
    // just initialize the display
    display.init();
    display.flipScreenVertically();
}

void DisplayTests::writeData(){
    display.clear();
    display.display();

    std::stringstream ss;
    ss << "Temperature: " << pBmeSensor->getTemperatureAsString();
    display.drawString(15, 1, ss.str().c_str());
    ss.str("");
    ss << "Humidity: " << pBmeSensor->getHumidityAsString();
    display.drawString(15, 10, ss.str().c_str());
    ss.str("");
    ss << "Pressure: " << pBmeSensor->getPressureAsString();
    display.drawString(15, 20, ss.str().c_str());

    display.display();
}

void DisplayTests::firstTest(const char* s){
  display.drawString(1,6,"- - - - - - - - - - - - -");
  display.drawCircle(32, 28, 8);
  display.drawProgressBar(10,10,30,10,65);
  display.drawString(64, 16, "Hello");
  display.drawString(40, 40, "Does it snow?");
  display.drawCircle(32, 34, 8);


  display.drawString(15, 20, s);



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