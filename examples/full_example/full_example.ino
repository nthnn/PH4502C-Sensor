#include <ph4502c_sensor.h>

#define PH4502C_PH_LEVEL_PIN A0
#define PH4502C_TEMP_PIN A1

PH4502C_Sensor ph4502(PH4502C_PH_LEVEL_PIN, PH4502C_TEMP_PIN);

void setup() {
    Serial.begin(9600);
    Serial.println("Starting PH4502C Sensor...");

    ph4502.init();
}

void loop() {
    Serial.println("Temperature reading:"
        + String(ph4502.read_temp()));
    Serial.println("pH Level Reading: "
        + String(ph4502.read_ph_level()));
    Serial.println("pH Level Single Reading: "
        + String(ph4502.read_ph_level_single()));

    delay(1000);
}