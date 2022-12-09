void ReadDht(){
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print(" Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("C ");
  return h,t;
}