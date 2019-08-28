int vib_pin=7;

void setup() {
  pinMode(vib_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  int val;
  val=digitalRead(vib_pin);
  if(val==1)
  {
    Serial.println("titreşim algılandı!");
   }
   else{
   Serial.println("algılanan titreşim bulunmamakta...");
}
delay(2000);
}
