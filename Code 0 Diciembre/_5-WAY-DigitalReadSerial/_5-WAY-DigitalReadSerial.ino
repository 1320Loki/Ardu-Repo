
int IR = A0;
int IR1 = A1;
int IR2 = A2;
int IR3 = A3;
int IR4 = A4;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the IR's pin an input:
  pinMode(IR, INPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(IR);
  int buttonState1 = digitalRead(IR1);
  int buttonState2 = digitalRead(IR2);
  int buttonState3 = digitalRead(IR3);
  int buttonState4 = digitalRead(IR4);
  // print out the state of the button:
  Serial.print(buttonState);
    Serial.print(buttonState1);
      Serial.print(buttonState2);
        Serial.print(buttonState3);
  Serial.println(buttonState4);

 
  delay(100);        // delay in between reads for stability
}



