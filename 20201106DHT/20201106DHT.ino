#include <SimpleDHT.h>

int pinDHT11 = 17;
SimpleDHT11 dht11(pinDHT11);

boolean old_state = HIGH;
int run = 1,light;
boolean data;
void setup() {
  // put your setup code here, to run once:
  pinMode(21, INPUT);
  pinMode(22, OUTPUT);
  pinMode(3, OUTPUT);
 // Serial.begin(9600);
}

void loop() {

  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  // put your main code here, to run repeatedly:
  data = digitalRead(21);
  if (old_state == HIGH && data == LOW) {
    run = -run;
  }
  if (run == -1) {
    if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
      //  Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
      return;
    }
//    Serial.print((int)temperature);//Serial.print((int)temperature);
//    Serial.print(","); //Serial.print(" *C, ");
//    Serial.println((int)humidity);//Serial.print((int)humidity); Serial.println(" H");
    delay(1300);
    light=analogRead(A19);
  }

  delay(200);
  if (int(temperature) > 26) {
    digitalWrite(3, HIGH);
  } else if (int(temperature) < 26) {
    digitalWrite(3, LOW);
  }
    if (light > 1400) {
    digitalWrite(22, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
  }
  else {
    digitalWrite(22, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second}
  }
  old_state = data;

}
