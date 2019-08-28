
int digitalPin = 5;
int deger;

void setup() {
Serial.begin(9600);
}

void loop() {
deger = digitalRead(digitalPin); //hareket değerini okuyoruz ve bunu deger değişkenine atıyoruz.

if (deger == LOW)
{
Serial.println("Hareket Yok"); //okunan değer LOW ise "Hareket Yok" yaz.
}
else
{
Serial.println("Hareket Var"); //okunan değer HIGH ise "Hareket Var" yaz.
delay(5000); 

}
}

