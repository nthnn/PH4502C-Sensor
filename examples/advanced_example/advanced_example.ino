/**
  *  Advanced example for PH4502C_Sensor.h
  *
  * This example shows how to use the library with an esp32 devboard.
  *
  * By: Pablo Alessandro Santos Hugen
  * 21/10/2023
  */

#include <ph4502c_sensor.h>

/* Pinout: https://cdn.awsli.com.br/969/969921/arquivos/ph-sensor-ph-4502c.pdf */
#define PH4502C_TEMPERATURE_PIN 34
#define PH4502C_PH_PIN 35
#define PH4502C_PH_TRIGGER_PIN 14 
#define PH4502C_CALIBRATION 14.8f
#define PH4502C_READING_INTERVAL 100
#define PH4502C_READING_COUNT 10
// NOTE: The ESP32 ADC has a 12-bit resolution (while most arduinos have 10-bit)
#define ADC_RESOLUTION 4096.0f

// Create an instance of the PH4502C_Sensor
PH4502C_Sensor ph4502c(
  PH4502C_PH_PIN,
  PH4502C_TEMPERATURE_PIN,
  PH4502C_CALIBRATION,
  PH4502C_READING_INTERVAL,
  PH4502C_READING_COUNT,
  ADC_RESOLUTION
);

void setup() {
    Serial.begin(9600);
    Serial.println("Starting PH4502C Sensor...");

    // Initialize the PH4502 instance
    ph4502c.init();
}

void loop() {
    // Read the temperature from the sensor
    Serial.println("Temperature reading:"
        + String(ph4502c.read_temp()));

    // Read the pH level by average
    Serial.println("pH Level Reading: "
        + String(ph4502c.read_ph_level()));

    // Read a single pH level value
    Serial.println("pH Level Single Reading: "
        + String(ph4502c.read_ph_level_single()));

    delay(1000);
}
