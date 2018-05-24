void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  if (reading < 1023){
    Serial.println(reading);
  }
  
}

