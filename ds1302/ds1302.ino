#include <virtuabotixRTC.h>                                                                              

//CLK -> 6
//DATA-> 7 
//RST -> 8
virtuabotixRTC myRTC(6, 7, 8);

void setup() {
Serial.begin(9600);
/*Başlangıç olarak belirlenmesini istediğiniz zamanı 
 aşağıdaki formatta girebilirsiniz*/
// saniye, dakika, saat, haftanın günü, ayın günü, ay, yıl
myRTC.setDS1302Time(00, 57, 14,2, 227, 8, 2019);
}

void loop() {

myRTC.updateTime(); //her seferinde zamanı güncellemesi için

Serial.print("Şu anki Tarih / Saat : ");
Serial.print(myRTC.dayofmonth);
Serial.print("/");
Serial.print(myRTC.month);
Serial.print("/");
Serial.print(myRTC.year);
Serial.print(" ");
Serial.print(myRTC.hours);
Serial.print(":");
Serial.print(myRTC.minutes);
Serial.print(":");
Serial.println(myRTC.seconds);

delay(3000); // 3 saniyelik aralıklarla güncellemesi için
}                                                                                              
