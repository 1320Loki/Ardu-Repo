void slave(int a){
  //    Coms con el bus 1
  Wire.beginTransmission(a);      // Comunicarse con esclavo #1
  Wire.write('S');
  Wire.endTransmission();
  Wire.requestFrom(a, 3);         // Solicitar 1 byte del esclavo #1
  byte len = Wire.read();
  Wire.requestFrom(a, (int)len);  // Solicitar 'len' byte del esclavo #1
  //    Coms con el bus 1

  while (Wire.available()) { // slave may send less than requested
    msg = Wire.read();    // receive a byte as character
    Serial.println(msg);         // print the character
  }
  
  if(msg == '2'){
    Serial.println("hola");   //  LLEGA MENSAJE DE QUE TEMP Y HUM ESTAN ELEVADOS
  }
  else if(msg == '1'){
    Serial.println("chao");   //  LLEGA MENSAJE DE TEMP NOMINAL
  }
}

