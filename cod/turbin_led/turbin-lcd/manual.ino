
void manual() {

  //****************fak control**************
  if (up_fak == 1) {
    Serial.println("fak paein");
    stepper1.setSpeed(speeds);
    digitalWrite(dir2, HIGH);
    while (1) {
      stepper1.runSpeed();
      button();
      if (up_fak == 0) break;
    }
  }


  if (down_fak == 1) {
     Serial.println("fak bala");
    stepper1.setSpeed(speeds);
    digitalWrite(dir2, LOW);
    while (1) {
      stepper1.runSpeed();
      button();
      if (down_fak == 0) break;
    }
  }

  //********************main_control**********
  if (right_main == 1) {
     Serial.println("main rast");
    stepper2.setSpeed(main_volom);
    digitalWrite(dir1, HIGH);
    while (1) {
      stepper2.runSpeed();
      button();
      if (right_main == 0) break;
    }
  }


  if (left_main == 1) {
     Serial.println("main chap");
    stepper1.setSpeed(main_volom);
    digitalWrite(dir1, LOW);
    while (1) {
      stepper2.runSpeed();
      button();
      if (left_main == 0) break;
    }
  }
}
