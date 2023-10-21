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

    reading = PH4502C_VOLTAGE / this->_adc_resolution * reading;
    reading /= this->_reading_count;
    reading = this->_calibration + ((PH4502C_MID_VOLTAGE - reading)) / PH4502C_PH_VOLTAGE_PER_PH;

    return reading;
}

float PH4502C_Sensor::read_ph_level_single() {
    float reading = analogRead(this->_ph_level_pin);

    reading = PH4502C_VOLTAGE / this->_adc_resolution * reading;
    reading /= this->_reading_count;

    return this->_calibration + ((PH4502C_MID_VOLTAGE - reading)) / PH4502C_PH_VOLTAGE_PER_PH;
}

int PH4502C_Sensor::read_temp() {
    return analogRead(this->_temp_pin);
}
