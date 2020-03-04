#include "display/displayTests.hpp"
#include "wifi/wifi_access_point.hpp"
#include "bme/bme280.hpp"
#include <sstream>



// Uncomment to turn on WIFI AP
//#define __WIFION__

BME::BME280* pBmeSensor = new BME::BME280();
Display::DisplayTests* pDisplay = new Display::DisplayTests(pBmeSensor); 
Wifi::Wifi_Access_Point* pWifi = new Wifi::Wifi_Access_Point();

void setup(){
  #ifdef __WIFION__
  pWifi->init();
  #else
  WiFi.softAPdisconnect (true);
  #endif


  pDisplay->init();
  pBmeSensor->init();
}

void loop(){

  pBmeSensor->poll();
  delay(10000);
  //ss << "Temp: " << temp;
  

  //pDisplay->firstTest("booojaaaaaa!!");
  pDisplay->writeData();
}