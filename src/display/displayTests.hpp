#include <Arduino.h>
#include "SH1106Wire.h"
#include "../bme/bme280.hpp"

#ifndef DISPLAY_H_
#define DISPLAY_H_

namespace Display
{
class DisplayTests
{
public:
    DisplayTests(BME::BME280* _pBmeSensor);
    virtual ~DisplayTests();

    void init();
    void firstTest(const char* s);

    void writeText(int16_t topPos,int16_t leftPos,bool multiLine);
    void writeData();

    SH1106Wire display;
    BME::BME280* pBmeSensor = new BME::BME280();
};
}

#endif /* DISPLAY_H_ */