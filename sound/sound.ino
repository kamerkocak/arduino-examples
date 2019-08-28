int soundPin=2; //D2
void setup() {
 pinMode(soundPin,INPUT);
 Serial.begin(9600);

}

void loop() {

  int SensorData=digitalRead(soundPin); 
  if(SensorData==1){

    Serial.println("Ses tespit edildi!");
    }
    else{
    Serial.println("Ortamda ses bulunmamakta...");
    }
    delay(2000);
  }
 
