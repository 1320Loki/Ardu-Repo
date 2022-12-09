//------------------- lIBRARY SERVOMOTOR -------------------//
#include <Servo.h>            // SERVO LIB
#include <AccelStepper.h>     // STEPPER LIB
Servo servo1, servo2;         // CREACION DE OBJETO SERVO
int angle1 = 90, angle2 = 0;  // P GUARDADA
//------------------- lIBRARY SERVOMOTOR -------------------//

//--------------------- Milis function ---------------------//
unsigned long start;                  // Estructura De millis
unsigned long current, current2;      //
const unsigned long period1 = 50;     //
const unsigned long period2 = 500;    //
//--------------------- Milis function ---------------------//

int angle1 = 90, angle2 = 0;

void setup() {
  Serial.begin(9600);

  int angle1 = 90, angle2 = 0;                    //  Setting Intial Angle
  servo1.attach(3, 600, 2300);           //  Servo Motor Pin
  servo2.attach(5, 600, 2300);
  servo1.write(angle1);               //  Servo Intial Angle
  servo2.write(angle2);
  
  start = millis();
}

void loop() {
  
  ServoL();
  delay(5000);
  ServoR();
  delay(5000);
}

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