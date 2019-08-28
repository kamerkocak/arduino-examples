int analogPin = A0;  
int esikDeger = 300;
int sensorDegeri = 0;  

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // pin13 ve GND'ye bağlı led için çıkış belirledik.
  Serial.begin(9600);
}

void loop() {
  if (analogRead(analogPin) < esikDeger) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Aydınlık");
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Karanlık");
  }
  
  delay(500);
}
