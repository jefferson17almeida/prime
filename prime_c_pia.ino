#include <Wire.h>


//struct telemetria{
//byte index;
float lat, lon, h, t;
float v, c;
//float alt;
int volt;
unsigned long data;
unsigned long hora;
//}telemetria_1, telemetria_2;



void setup(){
  gps_dados();
  setup_power_control();
  temperatura();
  //setup_radio();
  //telemetria_1.index = 1;
  //telemetria_2.index =2;
  
}

void loop() {
  ler_gps();
  ler_temperatura();
  set_new_alarm();
  //update_radio():
  //delay(3000); 
  turn_off();
}
