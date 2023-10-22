/**
 * 
  *  Full example for PH4502C_Sensor.h
  * 
  *  By: Nathanne Isip
  *  27/06/2023
  * 
  */

#include <ph4502c_sensor.h>

// Define the pH level pin and temperature pin
#define PH4502C_PH_LEVEL_PIN A0
#define PH4502C_TEMP_PIN A1

// Create an instance of the PH4502C_Sensor
PH4502C_Sensor ph4502(PH4502C_PH_LEVEL_PIN, PH4502C_TEMP_PIN);

void setup() {
    Serial.begin(9600);
    Serial.println("Starting PH4502C Sensor...");

    // Initialize the PH4502 instance
    ph4502.init();
}

void loop() {
    // Read the temperature from the sensor
    Serial.println("Temperature reading:"
        + String(ph4502.read_temp()));

    // Read the pH level by average
    Serial.println("pH Level Reading: "
        + String(ph4502.read_ph_level()));

    // Read a single pH level value
    Serial.println("pH Level Single Reading: "
        + String(ph4502.read_ph_level_single()));

    delay(1000);
}