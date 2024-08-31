
void auto_2() {

  //******************select menu*****************
  if (left_ == 1) {
    ++menu_count;
    if (menu_count >= 2) menu_count = 2;
    change = 1;

  }

  if (right_ == 1) {
    --menu_count;
    if (menu_count < 0) menu_count = 0;
    change = 1;
  }

  if (start_ == 1) {

    //************************************************************************4 point**************************************************************************
    //************************************************************************4 point**************************************************************************
    //************************************************************************4 point**************************************************************************
    if (menu_count == 0) {
      float move1 = full_move / 4;
      float move2 = full_move / 2;
      int move_speed = 1000;

      int weld_speed = 0;  //8
      int weld_delay = 800;
      int khal_move = 0;



      Serial.println("start welding");
      ///////////////////////////////////////////////////////////////////////////1
      Serial.println("level1");
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
      ///////////////////////////////////////////////////////////////////////////2
      Serial.println("level2");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      stepper.moveRelativeInMillimeters(move2 - khal_move);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
      //////////////////////////////////////////////////////////////////////////////3
      Serial.println("level3");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      stepper.moveRelativeInMillimeters(move1 - khal_move);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      /////////////////////////////////////////////////////////////////////////////////////4
      Serial.println("level4");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      stepper.moveRelativeInMillimeters(move2 - khal_move);
      delay(50);
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
    }


    //************************************************************************6 point**************************************************************************
    //************************************************************************6 point**************************************************************************
    //************************************************************************6 point**************************************************************************
    if (menu_count == 1) {
      float move1 = full_move / 6;
      float move2 = full_move / 2;
      int move_speed = 1000;

      int weld_speed = 0;  //20
      int weld_delay = 800;
      int khal_move = 0;


      Serial.println("start welding");
      //////////////////////////////////////////////////////1
      Serial.println("level1");
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
      //////////////////////////////////////////////////////2
      Serial.println("level2");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      stepper.moveRelativeInMillimeters(move2 - khal_move);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////3
      Serial.println("level3");
      Serial.println("moving...");
      float moving = move2 + move1;
      moving = moving - khal_move;
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      stepper.moveRelativeInMillimeters(moving);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      ///////////////////////////////////////////////////////////4
      Serial.println("level4");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      stepper.moveRelativeInMillimeters(move2 - khal_move);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
       delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////////5
      Serial.println("level5");
      Serial.println("moving...");
      moving = move2 + move1;
      moving = moving - khal_move;
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      stepper.moveRelativeInMillimeters(moving);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////////////6
      Serial.println("level6");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      stepper.moveRelativeInMillimeters(move2 - khal_move);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
    }

    //************************************************************************8 point**************************************************************************
    //************************************************************************8 point**************************************************************************
    //************************************************************************8 point**************************************************************************
    if (menu_count == 2) {
      Serial.println("8khal");
      float move1 = full_move / 8;
      float move2 = full_move / 2;
      int move_speed = 1000;
      
      int weld_speed = 0;  //20
      int weld_delay = 800;
      int khal_move = 0;



      Serial.println("start welding");
      //////////////////////////////////////////////////////1
      Serial.println("level1");
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
      //////////////////////////////////////////////////////2
      Serial.println("level2");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      stepper.moveRelativeInMillimeters(move2 - khal_move);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////3
      Serial.println("level3");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      float moving = move1 * 2;
      Serial.println(String(moving));


      moving = moving - khal_move;
      stepper.moveRelativeInMillimeters(moving);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      ///////////////////////////////////////////////////////////4
      Serial.println("level4");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      stepper.moveRelativeInMillimeters(move2 - khal_move);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////////5
      Serial.println("level5");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      moving = move1 * 3;
      Serial.println(String(moving));
      moving = moving - khal_move;
      stepper.moveRelativeInMillimeters(moving);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////////////6
      Serial.println("level6");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      moving = move1 * 4;
      Serial.println(String(moving));
      moving = moving - khal_move;
      stepper.moveRelativeInMillimeters(moving);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////////////7
      Serial.println("level6");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      moving = move1 * 2;
      Serial.println(String(moving));
      moving = moving - khal_move;
      stepper.moveRelativeInMillimeters(moving);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);

      //////////////////////////////////////////////////////////////8
      Serial.println("level6");
      Serial.println("moving...");
      stepper.setSpeedInMillimetersPerSecond(move_speed);
      delay(50);
      moving = move1 * 4;
      Serial.println(String(moving));
      moving = moving - khal_move;
      stepper.moveRelativeInMillimeters(moving);
      delay(50);
      Serial.println("welding...");
      digitalWrite(rele, HIGH);
      digitalWrite(led, HIGH);
      stepper.setSpeedInMillimetersPerSecond(weld_speed);
      stepper.moveRelativeInMillimeters(khal_move);
      delay(weld_delay);
      digitalWrite(led, LOW);
      digitalWrite(rele, LOW);
    }
  }

  if (start_welding == 1) {
    Serial.println("full move");
    float move1 = full_move + 45;
    int move_speed = 1000;
    int weld_speed = 20;  //20

    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.setSpeedInMillimetersPerSecond(weld_speed);
    stepper.moveRelativeInMillimeters(move1);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);
  }
}
