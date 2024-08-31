#include <SpeedyStepper.h>

//*******steper_motor******
const int MOTOR_STEP_PIN = 3;
const int MOTOR_DIRECTION_PIN = 2;
const int enable_motor1 = 4;
SpeedyStepper stepper;

const int MOTOR_STEP_PIN2 = 5;
const int MOTOR_DIRECTION_PIN2 = 7;

SpeedyStepper stepper2;


//********menu_control*********
String cmnd;
int count_menu;
int exit_menu;
float m_move = 20;
float steps = 20;
float accel = 100;
float speeds = 200;
float m_move2 = 20;
float steps2 = 20;
float accel2 = 100;
float speeds2 = 200;
float m_move3 = 20;
float steps3 = 20;
float accel3 = 100;
float speeds3 = 200;
int m_run = 0;
int m_rotate = 0;
String string_steps;
String string_accel;
String string_speeds;

String string_steps2;
String string_accel2;
String string_speeds2;

String string_steps3;
String string_accel3;
String string_speeds3;

//********input data******
String data;
String step_move_data;
String lcd_char;
bool stopFlag = false;
int step_speed1;
int step_speed2;
int step_speed3;


int step_step1;
int step_step2;
int step_step3;


int analog_read1;
int analog_read2;
int analog_read3;
int analog_read4;
int analog_read5;
int analog_read6;

int volom1 = A0;
int volom2 = A1;
int volom3 = A2;
int volom4 = A3;
int volom5 = A4;
int volom6 = A5;

int namayesh;
int sanie;
int daqiqe;
int saat;

int rele = A1;
int led = A0;

int full_move = 5125;

void setup() {
  Serial.begin(115200);

  Serial.println("wait...");
  pinMode(rele, OUTPUT);
  pinMode(led, OUTPUT);

  //*****steper1*****
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);
  pinMode(enable_motor1, OUTPUT);
  //digitalWrite(enable_motor1, HIGH);
  stepper.setStepsPerMillimeter(steps * 1);
  stepper.setSpeedInMillimetersPerSecond(speeds);
  stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);

  //*****steper2*****
  stepper2.connectToPins(MOTOR_STEP_PIN2, MOTOR_DIRECTION_PIN2);

  //digitalWrite(enable_motor1, HIGH);
  stepper2.setStepsPerMillimeter(steps2 * 1);
  stepper2.setSpeedInMillimetersPerSecond(speeds2);
  stepper2.setAccelerationInMillimetersPerSecondPerSecond(accel2);
  stepper2.connectToPins(MOTOR_STEP_PIN2, MOTOR_DIRECTION_PIN2);

  digitalWrite(led, HIGH);
  for (int i = 0 ; i <= 20 ; i++) {
    digitalWrite(led, !digitalRead(led));

    delay(30);
  }
  digitalWrite(led, LOW);


  steps = 25;
  accel = 5000;
  speeds = 1000;

  stepper.setStepsPerMillimeter(steps * 1);
  stepper.setSpeedInMillimetersPerSecond(speeds);
  stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);
  digitalWrite(enable_motor1, LOW);

  steps2 = 25;
  accel2 = 5000;
  speeds2 = 500;
  stepper2.setStepsPerMillimeter(steps2 * 1);
  stepper2.setSpeedInMillimetersPerSecond(speeds2);
  stepper2.setAccelerationInMillimetersPerSecondPerSecond(accel2);
}

void loop() {
  uart_input();
}


///**********************input_uart**********************
void uart_input() {
  while (Serial.available() > 0) {
    cmnd = Serial.readString();
    uart_text();
  }
}


void uart_text() {

  data = cmnd.substring(0, 2);


  //********************start program****************
  if (data == "s1") {
    Serial.println("start Welding");
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.moveRelativeInMillimeters(full_move);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);
  }

  if (data == "s4") {

    float move1 = full_move / 4;
    float move2 = full_move / 2;
    int move_speed = 1000;
    int weld_speed = 20; //8
    int weld_delay = 1000;
    int khal_move = 40;



    Serial.println("start welding");
    ///////////////////////////////////////////////////////////////////////////1
    Serial.println("level1");
    Serial.println("welding...");
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.setSpeedInMillimetersPerSecond(weld_speed);
    stepper.moveRelativeInMillimeters(khal_move);
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
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);



  }

  //*********6khal**********
  //*********6khal**********
  //*********6khal**********
  if (data == "s6") {

    float move1 = full_move / 6;
    float move2 = full_move / 2;
    int move_speed = 1000;
    int weld_speed = 20; //20
    int weld_delay = 1000;
    int khal_move = 40;



    Serial.println("start welding");
    //////////////////////////////////////////////////////1
    Serial.println("level1");
    Serial.println("welding...");
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.setSpeedInMillimetersPerSecond(weld_speed);
    stepper.moveRelativeInMillimeters(khal_move);
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
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);

    //////////////////////////////////////////////////////3
    Serial.println("level3");
    Serial.println("moving...");
    stepper.setSpeedInMillimetersPerSecond(move_speed);
    delay(50);
    float moving = move2 + move1;
    moving = moving - khal_move;
    stepper.moveRelativeInMillimeters(moving);
    delay(50);
    Serial.println("welding...");
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.setSpeedInMillimetersPerSecond(weld_speed);
    stepper.moveRelativeInMillimeters(khal_move);
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
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);

    //////////////////////////////////////////////////////////5
    Serial.println("level5");
    Serial.println("moving...");
    stepper.setSpeedInMillimetersPerSecond(move_speed);
    delay(50);
    moving = move2 + move1;
    moving = moving - khal_move;
    stepper.moveRelativeInMillimeters(moving);
    delay(50);
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
    delay(50);
    stepper.moveRelativeInMillimeters(move2 - khal_move);
    delay(50);
    Serial.println("welding...");
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.setSpeedInMillimetersPerSecond(weld_speed);
    stepper.moveRelativeInMillimeters(khal_move);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);

  }


  //*********8khal**********
  //*********8khal**********
  //*********8khal**********
  if (data == "s8") {
    Serial.println("8khal");
    float move1 = full_move / 8;
    float move2 = full_move / 2;
    int move_speed = 1000;
    int weld_speed = 20; //20
    int weld_delay = 1000;
    int khal_move = 40;



    Serial.println("start welding");
    //////////////////////////////////////////////////////1
    Serial.println("level1");
    Serial.println("welding...");
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.setSpeedInMillimetersPerSecond(weld_speed);
    stepper.moveRelativeInMillimeters(khal_move);
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
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);

  }


  if (data == "xt") {
    Serial.println("full move");
    float move1 = full_move  + 45;
    int move_speed = 1000;
    int weld_speed = 20; //20

    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.setSpeedInMillimetersPerSecond(weld_speed);
    stepper.moveRelativeInMillimeters(move1);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);

  }


  if (data == "on") {
    Serial.println("rele on");
    digitalWrite(rele, HIGH);
    delay(1000);
    digitalWrite(rele, LOW);
  }

  data = cmnd.substring(0, 2);
  if (data == "of") {
    Serial.println("rele off");
    digitalWrite(rele, LOW);
  }

  //*****************motor1*******************
  //*****manual move******
  data = cmnd.substring(0, 2);
  if (data == "mu") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "move Right:" + step_move_data + "mm";

    Serial.println(lcd_char);

    digitalWrite(led, HIGH);
    stepper.moveRelativeInMillimeters(m_move);
    digitalWrite(led, LOW);
  }

  if (data == "md") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "move Left:" + step_move_data;
    Serial.println(lcd_char);
    digitalWrite(led, HIGH);
    stepper.moveRelativeInMillimeters(-m_move);
    digitalWrite(led, LOW);
  }

  //******calibration*******
//  if (data == "st") {
//    string_steps = cmnd.substring(3, 10);
//    steps = string_steps.toFloat();
//    lcd_char = "Step calib:" + string_steps;
//    Serial.println(lcd_char);
//    stepper.setStepsPerMillimeter(steps * 1);
//  }

  if (data == "ac") {
    string_accel = cmnd.substring(3, 10);
    accel = string_accel.toFloat();
    lcd_char = "acc calib:" + string_accel;
    Serial.println(lcd_char);
    stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);
  }

  if (data == "sp") {
    string_speeds = cmnd.substring(3, 10);
    speeds = string_speeds.toFloat();
    lcd_char = "speed:" + string_speeds;
    Serial.println(lcd_char);
    stepper.setSpeedInMillimetersPerSecond(speeds);
  }


  //*****************motor2*******************

  //*****manual move******
  data = cmnd.substring(0, 2);
  if (data == "yu") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "move up:" + step_move_data + "mm";

    Serial.println(lcd_char);

    digitalWrite(led, HIGH);
    stepper2.moveRelativeInMillimeters(m_move);
    digitalWrite(led, LOW);
  }

  if (data == "yd") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "move down:" + step_move_data;
    Serial.println(lcd_char);
    digitalWrite(led, HIGH);
    stepper2.moveRelativeInMillimeters(-m_move);
    digitalWrite(led, LOW);
  }

  if (data == "yp") {
    string_speeds = cmnd.substring(3, 10);
    speeds = string_speeds.toFloat();
    lcd_char = "speed:" + string_speeds;
    Serial.println(lcd_char);
    stepper2.setSpeedInMillimetersPerSecond(speeds);
  }

  //*************move_test***************
  if (data == "xu") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "test right:" + step_move_data + "mm";
    Serial.println(lcd_char);
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.moveRelativeInMillimeters(m_move);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);
  }

  if (data == "xd") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "test left:" + step_move_data + "mm";
    Serial.println(lcd_char);
    digitalWrite(rele, HIGH);
    digitalWrite(led, HIGH);
    stepper.moveRelativeInMillimeters(-m_move);
    digitalWrite(led, LOW);
    digitalWrite(rele, LOW);
  }

}



