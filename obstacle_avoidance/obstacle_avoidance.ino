void setup() {
 Serial.begin(9600);
 pinMode(8, INPUT); //D8

}

void loop() {
  int engelDurumu = digitalRead(8);// read obstacle status and store it into "detect"
  if(engelDurumu == LOW){
    
   Serial.println("Yakında engel bulunmakta!"); 
  }else{
    
   Serial.println("Yakında engel yok...");  
  }
  delay(500);
}
