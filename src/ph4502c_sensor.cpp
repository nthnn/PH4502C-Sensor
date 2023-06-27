#include <Arduino.h>
#include "ph4502c_sensor.h"

void PH4502C_Sensor::init() {
    pinMode(this->_ph_level_pin, INPUT);
    pinMode(this->_temp_pin, INPUT);
}

void PH4502C_Sensor::recalibrate(float calibration) {
    this->_calibration = calibration;
}

float PH4502C_Sensor::read_ph_level() {
    float reading = 0.0f;

    for(int i = 0; i < this->_reading_count; i++) {
        reading += analogRead(this->_ph_level_pin);
        delayMicroseconds(this->_reading_interval);
    }

    reading = 5 / 1024.0 * reading;
    reading /= this->_reading_count;
    reading = this->_calibration + ((2.5 - reading)) / 0.18;

    return reading;
}

float PH4502C_Sensor::read_ph_level_single() {
    float reading = analogRead(this->_ph_level_pin);

    reading = 5 / 1024.0 * reading;
    reading /= this->_reading_count;

    return this->_calibration + ((2.5 - reading)) / 0.18;
}

int PH4502C_Sensor::read_temp() {
    return analogRead(this->_temp_pin);
}
