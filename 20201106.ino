void setup() {
  // put your setup code here, to run once:
  pinMode(22, OUTPUT);
  Serial.begin(115200); //終端開啟鮑率
}
char i, x ;
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) //檢查buffer有無東西
  {
    i = Serial.read(); //將輸入轉成整數
    if (i == 'y' || i == 'Y'||i == 'n' || i == 'N') {
      x = i;
    }
    if (x == 'y' || x == 'Y') {
      digitalWrite(22, HIGH);
      delay(200);
    }
    if (x == 'n' || x == 'N') {
      digitalWrite(22, LOW);
      delay(200);
    }
  }
  Serial.println(x);
  delay(300);
}
