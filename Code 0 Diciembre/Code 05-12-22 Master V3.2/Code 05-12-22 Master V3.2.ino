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
int BtCont = 0, BtState = 0, LastBtState = 0;   //  Button code
int request = 22;
//--------------------- Code essencials --------------------//

//--------------------- Milis function ---------------------//
unsigned long start;                  // Estructura De millis
unsigned long current, current2;      //
const unsigned long period1 = 1500;   //
const unsigned long period2 = 500;    //
//--------------------- Milis function ---------------------//


void setup() {
  pinMode(request, INPUT);

  Serial.begin(9600);
  Wire.begin(0);        // unirse al bus i2c como master
}

void loop() {
  current = millis();
  if(current - start >= period1)
  {
    //slave(1);     //  No borrar. esta funcion es para el dht 11
    //SlaveF();
    BtState = digitalRead(request);

    if(BtState != LastBtState){
    
      if(BtState == HIGH){
        BtCont++;
        Serial.print("Boton ON ");
        Serial.println(BtCont);
        if(BtCont > 0){
          SlaveF();
        }
      }

      else{
        Serial.println("off");
        BtCont = 0;
      }
    }

    LastBtState = BtState;
    start = millis();
  }
}