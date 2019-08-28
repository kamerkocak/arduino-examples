#define MQ2pin (0) //analog pinlerden A0

float sensorValue; 

void setup()
{
  Serial.begin(9600); 
  Serial.println("Gaz sensörü ısınıyor...");
  Serial.println("Sensör değeri 300 değerinin üstüne çıkarsa uyarılacaksınız...");
  delay(20000); 
}

void loop()
{
  sensorValue = analogRead(MQ2pin); 
  
  Serial.print("Sensör Değeri: ");
  Serial.print(sensorValue);
  
  if(sensorValue > 300)
  {
    Serial.print(" | Yanıcı gaz tespit edildi!");
  }
  
  Serial.println("");
  delay(2000); 
}
