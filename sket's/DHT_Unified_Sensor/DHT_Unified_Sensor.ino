#include "Adafruit_Sensor.h"
#include "DHT.h"
#include "DHT_U.h"

#define DHTPIN 2         

//#define DHTTYPE         DHT11     // DHT 11 
#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE         DHT21     // DHT 21 (AM2301)

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600); 
  dht.begin();
  Serial.println("Sensor de umadade/temperatura Estufa");
  sensor_t sensor;
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Valor Maximo:  "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Valor Minimo:  "); Serial.print(sensor.min_value); Serial.println("%"); 
  Serial.println("------------------------------------");

  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("erro de leitura da temperatura!");
  }
  else {
    Serial.print("TEMPERATURA: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("erro de leitura da umidade!");
  }
  else {
    Serial.print("UMIDADE: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
    Serial.println("---------------------");
  }
}
