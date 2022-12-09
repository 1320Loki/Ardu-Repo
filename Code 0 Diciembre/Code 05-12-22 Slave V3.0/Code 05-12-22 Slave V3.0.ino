/*  https://patorjk.com/software/taag/#p=display&f=Big&t=MASTER%20%20V%203
|  _____ _          __      ________  __      __  ____  
  / ____| |        /\ \    / /  ____| \ \    / / |___ \ 
 | (___ | |       /  \ \  / /| |__     \ \  / /    __) |
  \___ \| |      / /\ \ \/ / |  __|     \ \/ /    |__ < 
  ____) | |____ / ____ \  /  | |____     \  /     ___) |
 |_____/|______/_/    \_\/   |______|     \/     |____/ 
*/

//--------------------- Code essencials --------------------//
#include <Wire.h>
String message;
bool S = false;
int rele = 12;
int ReleState = 0;
//--------------------- Code essencials --------------------//

//----------------------- DHT11 LIB ------------------------//
#include "DHT.h"              //  DHT11-DHT22 LIB
#define DHTPIN 2              //  DHT Pin
#define DHTTYPE DHT11         //  Typing of DHT used
DHT dht(DHTPIN, DHTTYPE);     //  DHT Lib Parameters
float h, t;                   //  Temp & Humy variables
float SpH=50, SpT=22;         //  Set Point Humy and temp
//----------------------- DHT11 LIB ------------------------//

//--------------------- Milis Function ---------------------//
unsigned long start;                  // Estructura De millis
unsigned long current, current2;      //
const unsigned long period1 = 1500;   //
const unsigned long period2 = 500;    //
//--------------------- Milis Function ---------------------//

void setup() {
  Serial.begin(9600);
  start = millis();

  pinMode(rele, OUTPUT);              //  Output relay pin
  digitalWrite(rele, LOW);            //  Output turned off 
  dht.begin();                        //  DHT11 function start

  Wire.begin(1);                      // unirse al bus i2c con la direccion #23
  Wire.onRequest(eventoSolicitud);    // registrar evento de solicitud de datos
  Wire.onReceive(eventoRecepcion);    // registrar evento de recepcion de datos
}

void loop() {
  current = millis();
  if(current - start >= period1)
  {
    ReadDht();
    IfDht(h,t);

    start = millis();
  }
}



