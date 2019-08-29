

void setup()

{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()

{
  int mois = analogRead(A0);
  mois = map(mois,0,1023,0,100);
  Serial.print("Nem oranı: ");
  Serial.print((100-mois));
  Serial.print("  --->  ");

  if(mois >= 98) {
  Serial.println("Sensör toprakta değil veya bağlı değil!");
  }

  if(mois < 98 && mois >= 50) { 
  Serial.println("Toprak kuru.");
  }

  if(mois < 50 && mois >= 30) {
  Serial.println("Toprak nemli."); 
  }
  
  if(mois < 30) {
  Serial.println("Sensör suda.");
  }                                          

  delay(2000);

}


