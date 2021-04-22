#include<SoftwareSerial.h>
#include<TinyGPS.h>  //https://github.com/mikalhart/TinyGPS.git

SoftwareSerial sg(4, 3);
TinyGPS GPS;



void gps_dados(){
  sg.begin(9600);
  Serial.begin(9600);

  Serial.println("Esperando GPS...");
}


void ler_gps() {
  unsigned long start_time = millis();
  while (sg.available()) {
    if (GPS.encode(sg.read())) {
      //hora e data
      GPS.get_datetime(&data, &hora);

      Serial.print("Horas: ");
      Serial.print((hora / 1000000) - 3);
      Serial.print(":");
      Serial.print((hora % 1000000) / 10000);
      Serial.print(":");
      Serial.print((hora % 10000) / 100);
      Serial.print(" Data ");

      Serial.print(data / 10000);
      Serial.print("/");
      Serial.print((data % 10000) / 100);
      Serial.print("/");
      Serial.print(data % 100);
      Serial.println(" ");

      //Latitude e longitude
      GPS.f_get_position(&lat , &lon );

      Serial.print("Latitude: ");
      Serial.println(lat, 6);
      Serial.print("Longitude: ");
      Serial.println(lon, 6);

      Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.println("*C");

      //Serial.print("Umidade: ");
      //Serial.print(h);

      Serial.print("Voltagem: "); Serial.print(v); Serial.println(" V");
      Serial.print("Corrente_mA: ");  Serial.print(c); Serial.println(" mA");
      delay(10);

    }
  }


}
