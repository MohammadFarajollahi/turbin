int start_1;
int up_fak1;
int down_fak1;
int right_main1;
int left_main1;
int left_1;
int right_1;
int start_welding1;



void button() {

  //*******fak up**********
  if (digitalRead(k1) == 0) {
    up_fak = 1;
    //Serial.println("fak up");
  }
  if (digitalRead(k1) == 1) {
    up_fak = 0;
  }

  //*******fak down**********
  if (digitalRead(k2) == 0) {
    down_fak = 1;
   // Serial.println("fak down");
  }
  if (digitalRead(k2) == 1) {
    down_fak = 0;
  }


  //*******right main**********
  if (digitalRead(k3) == 0) {
    right_main = 1;
    //Serial.println("main right");
  }
  if (digitalRead(k3) == 1) {
    right_main = 0;
  }

  //*******left main**********
  if (digitalRead(k4) == 0) {
    left_main = 1;
   // Serial.println("left main");
  }
  if (digitalRead(k4) == 1) {
    left_main = 0;
  }

  //*******change**********
  if (digitalRead(k5) == 0) {
    left_ = 1;
    Serial.println("left");
  }
  if (digitalRead(k5) == 1) {
    left_ = 0;
  }

  //*******change**********
  if (analogRead(A7) < 20) {
    right_ = 1;
    Serial.println("right");
  }
  if (analogRead(A7) > 500) {
    right_ = 0;
  }

  //*******start_wel**********
  if (analogRead(A6) < 20) {
    start_welding = 1;
    Serial.println("start_wel");
  }
  if (analogRead(A6) > 500) {
    start_welding = 0;
  }

  //*******start_**********
  if (digitalRead(k8) == 0) {
    start_ = 1;
    Serial.println("start_");
  }
  if (digitalRead(k8) == 1) {
    start_ = 0;
  }


  //}
}
