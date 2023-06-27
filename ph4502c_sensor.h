#ifndef PH4502C_SENSOR_H
#define PH4502C_SENSOR_H

#include <Arduino.h>

#define PH4502_DEFAULT_CALIBRATION 14.8f
#define PH4502_DEFAULT_READING_INTERVAL 100
#define PH4502_DEFAULT_READING_COUNT 10

class PH4502C_Sensor {
    public:

    PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin):
        _ph_level_pin(ph_level_pin),
        _temp_pin(temp_pin),
        _calibration(PH4502_DEFAULT_CALIBRATION),
        _reading_interval(PH4502_DEFAULT_READING_INTERVAL),
        _reading_count(PH4502_DEFAULT_READING_COUNT) { }

    PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin, float calibration):
        _ph_level_pin(ph_level_pin),
        _temp_pin(temp_pin),
        _calibration(calibration),
        _reading_interval(PH4502_DEFAULT_READING_INTERVAL),
        _reading_count(PH4502_DEFAULT_READING_COUNT) { }

    PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin, float calibration, int reading_interval):
        _ph_level_pin(ph_level_pin),
        _temp_pin(temp_pin),
        _calibration(calibration),
        _reading_interval(reading_interval),
        _reading_count(PH4502_DEFAULT_READING_COUNT) { }

    PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin, float calibration, int reading_interval, int reading_count):
        _ph_level_pin(ph_level_pin),
        _temp_pin(temp_pin),
        _calibration(calibration),
        _reading_interval(reading_interval),
        _reading_count(reading_count) { }

    void init();
    void recalibrate(float calibration);

    float read_ph_level();
    float read_ph_level_single();
    int read_temp();

    private:
    uint16_t _ph_level_pin, _temp_pin;
    int _reading_interval, _reading_count;

    float _calibration;
};

#endif