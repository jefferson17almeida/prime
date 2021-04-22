#include <DHT.h> //https://github.com/adafruit/DHT-sensor-library.git

#define DHTPIN A1  
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void temperatura(){
  dht.begin();
}

void ler_temperatura(){
  h = dht.readHumidity();
  t = dht.readTemperature();
   if (isnan(t) || isnan(h)) 
  {
    Serial.println("Falha ao ler de DHT");
  } 
  else
  {
    //Serial.print("Umidade: ");
    //Serial.print(h);
    //Serial.print(" %t")
    
  }
}
