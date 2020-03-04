#include <Wire.h>  
#include "wifi_access_point.hpp"
#include "SSD1306Wire.h"


namespace Wifi
{
Wifi_Access_Point::Wifi_Access_Point()
{
    
}

Wifi_Access_Point::~Wifi_Access_Point()
{
    ;
}

void Wifi_Access_Point::init(){
    
  Serial.print("Setting soft-AP ... ");
  boolean result = WiFi.softAP("It does not burn When IP", "pass-to-soft-AP");
  if(result == true)
  {
    Serial.println("Ready");
  }
  else
  {
    Serial.println("Failed!");
  }
}

}