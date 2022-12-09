/* https://patorjk.com/software/taag/#p=display&f=Big&t=SLAVE%20V%203
  __  __           _____ _______ ______ _____    __      __  ____  
 |  \/  |   /\    / ____|__   __|  ____|  __ \   \ \    / / |___ \ 
 | \  / |  /  \  | (___    | |  | |__  | |__) |   \ \  / /    __) |
 | |\/| | / /\ \  \___ \   | |  |  __| |  _  /     \ \/ /    |__ < 
 | |  | |/ ____ \ ____) |  | |  | |____| | \ \      \  /     ___) |
 |_|  |_/_/    \_\_____/   |_|  |______|_|  \_\      \/     |____/
*/
//--------------------- Code essencials --------------------//
#include <Wire.h>
char msg;
int boton = 22;
int BtCont = 0, BtState = 0, LastBtState = 0;   //  Button code
//--------------------- Code essencials --------------------//

//--------------------- Milis function ---------------------//
unsigned long start;                  // Estructura De millis
unsigned long current, current2;      //
const unsigned long period1 = 1500;   //
const unsigned long period2 = 500;    //
//--------------------- Milis function ---------------------//


void setup() {
  Serial.begin(9600);

  Wire.begin(0);        // unirse al bus i2c como master
  pinMode(boton, INPUT);
}

void loop() {
  current = millis();
  if(current - start >= period1)
  {
    //slave(1);     //  No borrar. esta funcion es para el dht 11
    /*
    Wire.beginTransmission(2);      // Comunicarse con esclavo #1
    Wire.write('S');
    Wire.endTransmission();
    Wire.requestFrom(2, 3);         // Solicitar 1 byte del esclavo #1
    byte len = Wire.read();
    Wire.requestFrom(2, (int)len);  // Solicitar 'len' byte del esclavo #1
    //    Coms con el bus 1

    while (Wire.available()) { // slave may send less than requested
      msg = Wire.read();    // receive a byte as character
      Serial.print(msg);         // print the character
    }
    */
 


    start = millis();
  }
}