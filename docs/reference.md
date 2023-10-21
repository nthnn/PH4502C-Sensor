# PH4502C Sensor Arduino Library Documentation

The PH4502C Sensor Arduino Library provides a comprehensive set of classes, functions, and definitions to interface with the PH4502C sensor, enabling accurate pH level measurements in your Arduino projects. This documentation aims to provide detailed information about each component of the library.

## PH4502C_Sensor Class

The PH4502C_Sensor class represents the PH4502C sensor and provides methods to initialize, calibrate, and read pH levels and temperature. It offers multiple constructors to accommodate different configuration needs.


### Constructors

```cpp
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
```

**PH4502C_Sensor::init()**

The ```init()``` method initializes the PH4502C sensor for communication. It should be called once in the setup() function of your Arduino sketch.

```cpp
void PH4502C_Sensor::init();
```

**PH4502C_Sensor::recalibrate()**

The ```recalibrate()``` method allows you to set a new calibration value for the sensor. This function adjusts the pH readings to match the calibration solution used.

```cpp
void recalibrate(float calibration);
```

- Parameters:
    - ```calibration``` *(float)*: The new calibration value to adjust pH readings.

**PH4502C_Sensor::read_ph_level()**

The ```read_ph_level()``` method reads the pH level from the sensor and returns the average pH value over multiple readings. It performs multiple readings according to the configured reading_count value and calculates the average.

```cpp
float read_ph_level();
```

- Returns: The average pH level value over multiple readings.

**PH4502C::read_ph_level_single()**

The ```read_ph_level_single()``` method reads a single pH level value from the sensor without averaging. It provides a single pH level reading without performing multiple measurements.

```cpp
float read_ph_level_single();
```

- Returns: The pH level value from a single reading.

**PH4502C_Sensor::read_temp()**

The ```read_temp()``` method reads the temperature value from the sensor and returns it in degrees Celsius. The temperature compensation is automatically applied to the pH readings for improved accuracy.

```cpp
int read_temp();
```

- Returns: The temperature analog value.

### Definitions

The PH4502C Sensor Arduino Library provides several pre-defined constants for convenience and customization.

**PH4502C_DEFAULT_CALIBRATION**

The ```PH4502C_DEFAULT_CALIBRATION``` constant represents the default calibration value used by the library. The default value is set to ```14.8```.

```cpp
#define PH4502C_DEFAULT_CALIBRATION 14.8f
```

**PH4502C_DEFAULT_READING_INTERVAL**

The ```PH4502C_DEFAULT_READING_INTERVAL``` constant represents the default time interval between consecutive pH level readings in milliseconds. The default value is set to 100 milliseconds.

```cpp
#define PH4502C_DEFAULT_READING_INTERVAL 100
```

**PH4502C_DEFAULT_READING_COUNT**

The ```PH4502C_DEFAULT_READING_COUNT``` constant represents the default number of pH level readings to average when using read_ph_level(). The default value is set to 10.

```cpp
#define PH4502C_DEFAULT_READING_COUNT 10
```

**PH4502C_DEFAULT_ADC_RESOLUTION**

The `PH4502C_DEFAULT_ADC_RESOLUTION` constant represents the default ADC resolution for the PH4502C sensor. The default value is set to `1024.0`.

```cpp
#define PH4502C_DEFAULT_ADC_RESOLUTION 1024.0f
```

**PH4502C_VOLTAGE**

The `PH4502C_VOLTAGE` constant defines the operating voltage for the PH4502C sensor. The value is set to `5.0`.

```cpp
#define PH4502C_VOLTAGE 5.0f
```

**PH4502C_MID_VOLTAGE**

The `PH4502C_MID_VOLTAGE` constant defines the voltage that represents a neutral pH reading (pH = 7). The value is set to `2.5`.

```cpp
#define PH4502C_MID_VOLTAGE 2.5f
```

**PH4502C_PH_VOLTAGE_PER_PH**

The `PH4502C_PH_VOLTAGE_PER_PH` constant defines the rate of change in voltage per unit change in pH. The value is set to `0.18`.

```cpp

#define PH4502C_PH_VOLTAGE_PER_PH 0.18f
```

---

This concludes the documentation for the PH4502C Sensor Arduino Library. With this library, you can easily interface with the PH4502C sensor, calibrate it, and obtain accurate pH level and temperature measurements for your Arduino projects. For more details and examples, please refer to the library's examples and the provided source code.
