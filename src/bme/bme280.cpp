#include "bme280.hpp"
#include <Adafruit_BME280.h>  
#include <sstream>

// define device I2C address: 0x76 or 0x77 (0x77 is library default address)
#define BME280_I2C_ADDRESS  0x76
// initialize Adafruit BME280 library
Adafruit_BME280  bme280;

namespace BME
{
BME280::BME280()
{
    
}

BME280::~BME280()
{
    ;
}

void BME280::init(){
    bme280.begin(BME280_I2C_ADDRESS);    
}

void BME280::poll(){
    temperatureOld = temperature;
    humidityOld = humidity;
    pressureOld = pressure;
    temperature = bme280.readTemperature();    // get temperature in degree Celsius
    humidity = bme280.readHumidity();       // get humidity in rH%
    pressure = bme280.readPressure();       // get pressure in Pa
}

const char* BME280::getTemperatureAsString(){
    std::stringstream ss;
    ss << temperature;
    if(temperature>temperatureOld){
        ss << "!↑";
    }else{
        ss << "?↓";
    }
    return ss.str().c_str();
}

const char* BME280::getHumidityAsString(){
    std::stringstream ss;
    ss << humidity;
    if(humidity>humidityOld){
        ss << "!↑";
    }else{
        ss << "?↓";
    }
    return ss.str().c_str();
}

const char* BME280::getPressureAsString(){
    std::stringstream ss;
    ss << pressure;
    if(pressure>pressureOld){
        ss << "!↑";
    }else{
        ss << "?↓";
    }
    return ss.str().c_str();
}
}