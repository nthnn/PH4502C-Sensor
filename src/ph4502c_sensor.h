#ifndef PH4502C_SENSOR_H
#define PH4502C_SENSOR_H

#include <Arduino.h>

/// Default calibration value for the PH4502C sensor.
#define PH4502C_DEFAULT_CALIBRATION 14.8f

/// Default reading interval (in milliseconds) between pH readings.
#define PH4502C_DEFAULT_READING_INTERVAL 100

/// Default number of pH readings to average.
#define PH4502C_DEFAULT_READING_COUNT 10

/// Default ADC resolution for the PH4502C sensor.
#define PH4502C_DEFAULT_ADC_RESOLUTION 1024.0f

/// Operating voltage for the PH4502C sensor.
#define PH4502C_VOLTAGE 5.0f

/// Voltage that represents a neutral pH reading (pH = 7).
#define PH4502C_MID_VOLTAGE 2.5f

/// Rate of change in voltage per unit change in pH.
#define PH4502C_PH_VOLTAGE_PER_PH 0.18f

/**
 * @brief A class to interface with the PH4502C pH sensor.
 */
class PH4502C_Sensor {
    public:

    /**
     * @brief Construct a new PH4502C_Sensor object.
     * 
     * @param ph_level_pin Analog pin connected to the pH level output of the sensor.
     * @param temp_pin Analog pin connected to the temperature output of the sensor.
     * @param calibration Calibration value to adjust pH readings (default is PH4502C_DEFAULT_CALIBRATION).
     * @param reading_interval Time interval between consecutive pH level readings in milliseconds (default is PH4502C_DEFAULT_READING_INTERVAL).
     * @param reading_count Number of pH level readings to average when using read_ph_level() (default is PH4502C_DEFAULT_READING_COUNT).
     * @param adc_resolution ADC resolution used for voltage calculation from the analog read (default is PH4502C_DEFAULT_ADC_RESOLUTION).
     */
    PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin,
                   float calibration = PH4502C_DEFAULT_CALIBRATION,
                   int reading_interval = PH4502C_DEFAULT_READING_INTERVAL,
                   int reading_count = PH4502C_DEFAULT_READING_COUNT,
                   float adc_resolution = PH4502C_DEFAULT_ADC_RESOLUTION)
        : _ph_level_pin(ph_level_pin), _temp_pin(temp_pin),
          _calibration(calibration), _reading_interval(reading_interval),
          _reading_count(reading_count), _adc_resolution(adc_resolution) {}

    /**
     * @brief Initialize the pH and temperature sensor pins.
     */
    void init();

    /**
     * @brief Recalibrate the pH readings with a new calibration value.
     * 
     * @param calibration New calibration value for pH readings.
     */
    void recalibrate(float calibration);

    /**
     * @brief Read the pH level, averaging over multiple readings.
     * 
     * @return float Averaged pH value.
     */
    float read_ph_level();

    /**
     * @brief Read the pH level for a single reading.
     * 
     * @return float pH value from a single reading.
     */
    float read_ph_level_single();

    /**
     * @brief Read the temperature value.
     * 
     * @return int Analog reading from the temperature pin.
     */
    int read_temp();

    private:
    uint16_t _ph_level_pin; ///< Analog pin for pH level readings.
    uint16_t _temp_pin;     ///< Analog pin for temperature readings.
    int _reading_interval;  ///< Interval between pH readings.
    int _reading_count;     ///< Number of pH readings to average.
    float _calibration;     ///< Calibration value for pH readings.
    float _adc_resolution;  ///< ADC resolution for voltage calculation.
};

#endif
