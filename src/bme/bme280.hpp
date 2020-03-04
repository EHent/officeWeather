#include <Arduino.h>

#ifndef BME280_H_
#define BME280_H_

namespace BME
{
class BME280
{
public:
    BME280();
    virtual ~BME280();

    void init();
    void poll();

    float temperature;
    float humidity;
    float pressure;

    float temperatureOld;
    float humidityOld;
    float pressureOld;
    
    const char* getTemperatureAsString();
    const char* getHumidityAsString();
    const char* getPressureAsString();
};
}

#endif /* BME280_H_ */