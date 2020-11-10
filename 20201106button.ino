//delay(ms)裡面是毫秒

void setup() {
  // put your setup code here, to run once:
  pinMode(21, INPUT);
  pinMode(22, OUTPUT);
  Serial.begin(9600); //終端開啟鮑率
}
boolean data, oldata;
int temp = 0, A = 0, flag = 0;
void loop() {
  // put your main code here, to run repeatedly:
  data = digitalRead(21);//抓取腳位
  delay(200);
  oldata = data;
  if (data == oldata && data == LOW) {
    digitalWrite(22, HIGH);
    temp += 1;
    if (temp > 5 && flag == 1) {
      A = 0;
      temp = 0;
      flag = 0;
    }

  }
  else if (data == oldata && data == HIGH) {
    digitalWrite(22, LOW);
    Serial.println(A);
    if (flag == 0 ) {
      A += 1;
    }
    flag = 1;
  }
}


//for(i=0;i<4;i++){
//  old_state[i]=old_state[i+1];
//  }
