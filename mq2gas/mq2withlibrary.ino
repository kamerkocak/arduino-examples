#include <MQ2.h>
int Analog_Input = A0;
int lpg, co, smoke;

MQ2 mq2(Analog_Input);

void setup(){
  Serial.begin(9600);
  mq2.begin();
}
void loop(){
  float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
  //lpg = values[0];
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();

  Serial.print("LPG:");
  Serial.println(lpg);
  Serial.print("CO:");
  Serial.println(co);
  Serial.print("SMOKE:");
  Serial.println(smoke);
  delay(3000);
}

