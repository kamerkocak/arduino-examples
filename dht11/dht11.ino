
#include <dht11.h>  //http://arduinoturkiye.com/wp-content/uploads/dht11.rar linkinden kütüphane indirilebilir.
#define DHT11PIN 2 

dht11 DHT11;

void setup()
{
  Serial.begin(9600); 
  Serial.println("DHT11 İle Ortamdan Sıcaklık ve Nem Verisi Alma");
}

void loop()
{
  
  Serial.println();
  // Sensörün okunup okunmadığını konrol ediyoruz. 
  // chk 0 ise sorunsuz okunuyor demektir. Sorun yaşarsanız
  // chk değerini serial monitörde yazdırıp kontrol edebilirsiniz.
  int chk = DHT11.read(DHT11PIN);
  delay(500);
  
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);

  Serial.print("Sicaklik (Fahrenheit): ");
  Serial.println(DHT11.fahrenheit(), 2);

  Serial.print("Sicaklik (Kelvin): ");
  Serial.println(DHT11.kelvin(), 2);

  delay(5000);

}
