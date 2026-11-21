#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 25
#define LED_PIN 2


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void) {
  Serial.begin(9600);
  sensors.begin();
  pinMode(LED_PIN, OUTPUT);
}

void loop(void) {
  sensors.requestTemperatures();

    float tempC = sensors.getTempCByIndex(0);
  digitalWrite(LED_PIN, HIGH);
  Serial.println(tempC);
  delay(500);
  digitalWrite(LED_PIN, LOW);
}
