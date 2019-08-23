#include <virtuabotixRTC.h>
int analogDeger;
const int digitalPinYagmur = 4;
const int analogPinYagmur = A0;
const int analogPinSicaklik = A1;
float gerilimDeger = 0, sensorDeger = 0, sicaklikDeger = 0;
const int yagmurAralik = 5000, sicaklikAralik = 3000;
unsigned long sonYagmurZamani = 0, sonSicaklikZamani = 0;
virtuabotixRTC myRTC(6, 7, 8);

void setup() {
 Serial.begin(9600);
 pinMode(digitalPinYagmur, INPUT);
 pinMode(analogPinYagmur, INPUT);
 myRTC.setDS1302Time(16, 32, 16, 4, 22, 8, 2019);
 delay(500); 
}

void zaman() {
 // This allows for the update of variables for time or accessing the individual elements.
 myRTC.updateTime();

// Start printing elements as individuals

 Serial.print(" ");
 Serial.print(myRTC.hours);
 Serial.print(":");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 Serial.println(myRTC.seconds);

// Delay so the program doesn't print non-stop

}

void yagmurSensoru()
{ 
  if (millis() - sonYagmurZamani >= yagmurAralik) {
    Serial.println("**************************************");
  zaman();
  if(digitalRead(digitalPinYagmur) == LOW) 
  {
    Serial.println("Yağmur sensörü şu anda ıslak."); 
    delay(10); 
  }
else
  {
    Serial.println("Yağmur sensörü şu anda kuru.");
    delay(10); 
  }
 analogDeger=analogRead(analogPinYagmur); 
 Serial.print("Yağmur sensörünün analog değeri : ");
 Serial.println(analogDeger); 
 sonYagmurZamani = millis();}
 

// Start printing elements as individuals

}

void sicaklikSensoru()//LM35 Sıcaklık Sensörü
{ 
  
   if (millis() - sonSicaklikZamani >= sicaklikAralik) {
  // analogRead() fonksiyonu ile A0 pinindeki değeri okuyoruz.
 sensorDeger = analogRead(analogPinSicaklik);
 Serial.println("**************************************");
 zaman();
 Serial.print("Sıcaklık sensörünün analog değeri:  ");
 Serial.println(sensorDeger);
 
 // A0 pininden okunan değeri mV cinsinden gerilim değerine dönüştürüyoruz.
 gerilimDeger = (sensorDeger/1023)*5000;
 
 Serial.print("Sıcaklık sensörünün gerilim değeri: ");
 Serial.println(gerilimDeger);
 
 // Gerilim değerini sıcaklık değerine dönüştürüyoruz.
 sicaklikDeger = gerilimDeger / 10.0;
 
 Serial.print("Sıcaklık Değeri: ");
 Serial.println(sicaklikDeger);
 sonSicaklikZamani = millis(); 
  }

}


void loop() {

  yagmurSensoru();
  sicaklikSensoru();
}
 

