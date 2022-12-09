//********************* Wire Functions *********************//
void eventoRecepcion(){

  if( Wire.read() == 'S' ){
//          comparison          //    
    h = dht.readHumidity();
    t = dht.readTemperature();
    if(h >= SpH && t >= SpT){
      ReleState = 1;
    }
    else{
      ReleState = 2;
    }
//          comparison          // 

    S = true;
    //message = String(ReleState) + '\n';
    message = ReleState;
  }
  delay(1500);
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
//********************* Wire Functions *********************//