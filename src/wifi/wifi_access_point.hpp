#include <Arduino.h>
//#include <Wire.h>  
#include <brzo_i2c.h>
//#include "SSD1306Wire.h"

#include "SH1106Wire.h"
#include <ESP8266WiFi.h>


#ifndef WIFI_H_
#define WIFI_H_

namespace Wifi
{
class Wifi_Access_Point
{
public:
    Wifi_Access_Point();
    virtual ~Wifi_Access_Point();

    void init();
    
};
}

#endif /* WIFI_H_ */