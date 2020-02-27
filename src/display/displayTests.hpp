#include <Arduino.h>
#include "SH1106Wire.h"

#ifndef DISPLAY_H_
#define DISPLAY_H_

namespace Display
{
class DisplayTests
{
public:
    DisplayTests();
    virtual ~DisplayTests();

    void init();
    void firstTest(const char* s);

    void writeText(int16_t topPos,int16_t leftPos,bool multiLine);

    SH1106Wire display;
};
}

#endif /* DISPLAY_H_ */