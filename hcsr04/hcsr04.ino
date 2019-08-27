#define trigPin 7
#define echoPin 6
 
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
long sure, mesafe;

/* Başlangıçta LOW durumda olan trigger bacağına gerilim uygulayıp 
  ardından gerilimi keserek bir ses dalgası
  oluşturmuş oluyoruz. Bu işlem arasında 10 mikro saniye beklenmenin
  sebebi HC-SR04'ün en az 10 mikro saniyelik dalgalar ile çalışmasıdır. */
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
sure = pulseIn(echoPin, HIGH);
/* Dalga üretildikten sonra geri yansıyıp Echo bacağının 
   HIGH duruma geçireceği süreyi pulseIn fonksiyonu ile kaydediyoruz. */

mesafe = (sure/2) / 29.1; 
//mesafe gidiş-geliş şeklinde olduğundan yarıya bölüyoruz.
//saniyede kat ettiği yola göre de hesaplamamızı yapıyoruz.
   if (mesafe > 200 || mesafe < 0){
   Serial.println("Menzil Dışı");
   }
   else {
   Serial.print(mesafe);
   Serial.println(" cm");
   }
delay(500);
}

