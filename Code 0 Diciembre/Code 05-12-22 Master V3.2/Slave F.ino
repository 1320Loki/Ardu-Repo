void SlaveF(){
  
    Wire.beginTransmission(2);      // Comunicarse con esclavo #1
    Wire.write('S');
    Wire.endTransmission();
    Wire.requestFrom(2, 20);         // Solicitar 1 byte del esclavo #1
    byte len = Wire.read();
    Wire.requestFrom(2, (int)len);  // Solicitar 'len' byte del esclavo #1
    //    Coms con el bus 1

    while (Wire.available()) { // slave may send less than requested
      msg = Wire.read();    // receive a byte as character
      Serial.print(msg);         // print the character
    }
}