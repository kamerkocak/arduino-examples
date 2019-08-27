const int digitalPin = 2;
const int analogPin = A0;
int analogDeger;

void setup()
{
  pinMode(digitalPin, INPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
analogDeger = analogRead(analogPin); 
analogDeger = map(analogDeger,0,1024,0,100);
if(digitalRead(digitalPin) == LOW) 
  {
    Serial.println("Yağmur sensörü şu anda ıslak."); 
    Serial.print("Islaklık Oranı : ");
    Serial.println(100-(analogDeger)); 
    Serial.println("");
    delay(10); 
  }
else
  {
    Serial.println("Yağmur sensörü şu anda kuru.");
    Serial.print("Kuruluk Oranı : ");
    Serial.println(analogDeger); 
    Serial.println("");
    delay(10); 
  }

  delay(2000);
}
