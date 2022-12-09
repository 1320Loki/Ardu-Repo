/*  https://patorjk.com/software/taag/#p=display&f=Big&t=MASTER%20%20V%203
|  _____ _          __      ________  __      __  ____  
  / ____| |        /\ \    / /  ____| \ \    / / |___ \ 
 | (___ | |       /  \ \  / /| |__     \ \  / /    __) |
  \___ \| |      / /\ \ \/ / |  __|     \ \/ /    |__ < 
  ____) | |____ / ____ \  /  | |____     \  /     ___) |
 |_____/|______/_/    \_\/   |______|     \/     |____/ 
*/

//--------------------- Code essencials --------------------//
#include <Wire.h>             //  I2C LIB 
String message;
bool S = false; 
int Mov = 0, LastMov=0, MovCont=0;

#include <Servo.h>            // SERVO LIB
#include <AccelStepper.h>     // STEPPER LIB
Servo servo1, servo2;         // CREACION DE OBJETO SERVO
int angle1 = 90, angle2 = 0;  // P GUARDADA
//--------------------- Code essencials --------------------//

//--------------------- Milis function ---------------------//
unsigned long start;                  // Estructura De millis
unsigned long current, current2;      //
const unsigned long period1 = 1500;   //
const unsigned long period2 = 500;    //
//--------------------- Milis function ---------------------//

void setup() {
  Serial.begin(9600);
  /////////////////////////////////////////////////////////////////////////////
  Wire.begin(2);                      // unirse al bus i2c con la direccion #23
  Wire.onRequest(eventoSolicitud);    // registrar evento de solicitud de datos
  Wire.onReceive(eventoRecepcion);    // registrar evento de recepcion de datos
  /////////////////////////////////////////////////////////////////////////////
  int angle1 = 90, angle2 = 0;        //  Setting Intial Angle
  servo1.attach(3, 600, 2300);        //  Servo Motor Pin
  servo2.attach(5, 600, 2300);
  servo1.write(angle1);               //  Servo Intial Angle
  servo2.write(angle2);               //  Servo Intial Angle
}

void loop() {
  current = millis();
  if(current - start >= period1)
  {
/////////////////////////////////////////////////////////////////////////////
    if(Mov != LastMov){

      if(Mov == 1){
        MovCont++;
        Serial.println(Mov);
        ServoL();
      }
      Mov=0;
    }
    LastMov = Mov;
/////////////////////////////////////////////////////////////////////////////
    start = millis();
  }
}

void eventoRecepcion(){
    if( Wire.read() == 'S' ){
      S = true;
      Mov = 1;
      message = String( "Slave says 'ola'" ) + '\n';
      Serial.println("Master Says 'Dance'");
      return Mov;
    } 
}

// function that executes whenever data is requested by master
void eventoSolicitud() {
  if( S == true ){
    Wire.write(message.length());
    S = false;
    Serial.println(message.length());
  }
  else{
    Wire.println(message);
  }
}

//-------------------- Created Functions --------------------//
void ServoL(){
  servo1.write(180);
  delay(750);
  servo2.write(90);
  delay(1500);
  servo2.write(0);
  delay(750);
  servo1.write(90);
}

void ServoR(){
  servo1.write(0);
  delay(750);
  servo2.write(90);
  delay(1500);
  servo2.write(0);
  delay(750);
  servo1.write(90);
}
void AvPots(int a){
  digitalWrite(a, LOW);
  Serial.print("Pot n ");
  Serial.println(a);
}
//-------------------- Created Functions --------------------//