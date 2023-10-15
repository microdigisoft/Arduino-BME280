//Import all required libraries to support BME280 sensor
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25) // Define Pressure read parameter
Adafruit_BME280 bme; //Initialize BME sensor

void setup() {
  Serial.begin(9600);

  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  Serial.println("Microdigisoft Tutorials");
  Serial.println("BME280 digital sensor Measurment!");
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println("*C");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println("%");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println("hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println("m");

  Serial.println();
  delay(1000);

}
