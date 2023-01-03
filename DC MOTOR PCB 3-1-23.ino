/* https://patorjk.com/software/taag/#p=display&f=Big&t=DC%20MOTOR
  _____   _____   __  __  ____ _______ ____  _____  
 |  __ \ / ____| |  \/  |/ __ \__   __/ __ \|  __ \ 
 | |  | | |      | \  / | |  | | | | | |  | | |__) |
 | |  | | |      | |\/| | |  | | | | | |  | |  _  / 
 | |__| | |____  | |  | | |__| | | | | |__| | | \ \ 
 |_____/ \_____| |_|  |_|\____/  |_|  \____/|_|  \_\
*/

//--------------------- Code essencials --------------------//
int l1=4, l2=2;

#define In1 6   //  MOTOR 1 PINS
#define In2 7
#define ENA 8
#define In3 10  //  MOTOR 1 PINS
#define In4 11
#define ENB 12
//--------------------- Code essencials --------------------//

//--------------------- Milis function ---------------------//
unsigned long start;                  // Estructura De millis
unsigned long current, current2;      //
const unsigned long period1 = 1500;   //
const unsigned long period2 = 500;    //
//--------------------- Milis function ---------------------//

void setup() {

  pinMode(l1, OUTPUT);  //  Green LED
  pinMode(l2, OUTPUT);  //  Red LED

  pinMode(In1, OUTPUT); //  Motor 1
  pinMode(In2, OUTPUT); //  Motor 1
  pinMode(In3, OUTPUT); //  Motor 2
  pinMode(In4, OUTPUT); //  Motor 2

  pinMode(ENA, OUTPUT); //  PWM Motor 1
  pinMode(ENB, OUTPUT); //  PWM Motor 2

  Serial.begin(9600);

}

void loop() {

  current = millis();
  if(current - start >= period1)
  {
    digitalWrite(In1, HIGH);  //  direction pin
    digitalWrite(In2, LOW);   //  direction pin
    digitalWrite(In3, HIGH);  //  direction pin
    digitalWrite(In4, LOW);   //  direction pin
    analogWrite(ENA, 255);    //  Speed
    analogWrite(ENB, 100);    //  Speed


    start = millis();
  }
  digitalWrite(l1, HIGH);
  digitalWrite(l2, HIGH);
}