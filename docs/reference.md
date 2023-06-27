# PH4502C Sensor Arduino Library Documentation

The PH4502C Sensor Arduino Library provides a comprehensive set of classes, functions, and definitions to interface with the PH4502C sensor, enabling accurate pH level measurements in your Arduino projects. This documentation aims to provide detailed information about each component of the library.

## PH4502C_Sensor Class

The PH4502C_Sensor class represents the PH4502C sensor and provides methods to initialize, calibrate, and read pH levels and temperature. It offers multiple constructors to accommodate different configuration needs.

### Constructors

**PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin)**

- Parameters:
    - ```ph_level_pin``` *(uint16_t)*: The Arduino analog pin connected to the pH level output of the sensor.

    - ```temp_pin``` *(uint16_t)*: The Arduino analog pin connected to the temperature output of the sensor.

**PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin, float calibration)**

- Parameters:
    - ```ph_level_pin``` *(uint16_t)*: The Arduino analog pin connected to the pH level output of the sensor.

    - ```temp_pin``` *(uint16_t)*: The Arduino analog pin connected to the temperature output of the sensor.

    - ```calibration``` *(float)*: The calibration value to adjust pH readings.

**PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin, float calibration, int reading_interval)**

- Parameters:
    - ```ph_level_pin``` *(uint16_t)*: The Arduino analog pin connected to the pH level output of the sensor.

    - ```temp_pin``` *(uint16_t)*: The Arduino analog pin connected to the temperature output of the sensor.

    - ```calibration``` *(float)*: The calibration value to adjust pH readings.

    - ```reading_interval``` *(int)**: The time interval between consecutive pH level readings in milliseconds.

**PH4502C_Sensor(uint16_t ph_level_pin, uint16_t temp_pin, float calibration, int reading_interval, int reading_count)**

- Parameters:
    - ```ph_level_pin``` *(uint16_t)*: The Arduino analog pin connected to the pH level output of the sensor.

    - ```temp_pin``` *(uint16_t)*: The Arduino analog pin connected to the temperature output of the sensor.

    - ```calibration``` (float)*: The calibration value to adjust pH readings.

    - ```reading_interval``` *(int)*: The time interval between consecutive pH level readings in milliseconds.

    - ```reading_count``` *(int)**: The number of pH level readings to average when using ```read_ph_level()```.

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

---

This concludes the documentation for the PH4502C Sensor Arduino Library. With this library, you can easily interface with the PH4502C sensor, calibrate it, and obtain accurate pH level and temperature measurements for your Arduino projects. For more details and examples, please refer to the library's examples and the provided source code.