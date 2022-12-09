void IfDht(float h, float t){
  if(h >= SpH && t >= SpT){
    float tri = h - 20;
    Serial.print("holi ");
    Serial.println(tri);
    digitalWrite(rele, HIGH);
  }
  else{
    digitalWrite(rele, LOW);
  }
}