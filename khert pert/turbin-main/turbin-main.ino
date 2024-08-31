//********lcd*****************
//********lcd*****************
#include <Adafruit_GFX.h>    // include Core graphics library
#include <Adafruit_ST7735.h> // include Hardware-specific library
#include <SPI.h>
#define TFT_CS     47
#define TFT_RST    49  // you can also connect this to the Arduino reset                      
#define TFT_DC     48  // in which case, set this #define pin to -1!
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
//#define TFT_SCLK 6   // set these to be whatever pins you like!
//#define TFT_MOSI 7  // set these to be whatever pins you like!
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
//#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>

#include <SpeedyStepper.h>
#include <LiquidCrystal.h>

//******lcd*******
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);
String cmnd;

//*******steper_motor******
const int MOTOR_STEP_PIN = 45;
const int MOTOR_DIRECTION_PIN = 28;
const int enable_motor1 = 29;
SpeedyStepper stepper;

const int MOTOR_STEP_PIN2 = 44;
const int MOTOR_DIRECTION_PIN2 = 36;
const int enable_motor2 = 38;
SpeedyStepper stepper2;

const int MOTOR_STEP_PIN3 = 46;
const int MOTOR_DIRECTION_PIN3 = 40;
const int enable_motor3 = 42;
SpeedyStepper stepper3;

//********input button*********
int k1 = 30;
int k2 = 31;
int k3 = 32;
int k4 = 33;
int k5 = 41;
int k6 = 43;

//*******led********
int led_red = 34;
int led_green = 35;

//********menu_control*********
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

int rele = A7;
void setup() {
  Serial.begin(115200);

  Serial.println("wait...");

  //************lcd-tft********
  //////lcd_tft/////////
  tft.setFont(&FreeSerif9pt7b);
  //tft.setFont(&FreeMonoBoldOblique12pt7b);
  tft.setFont();
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_GREEN);
  tft.setCursor(10, 10);
  tft.setTextSize(1);
  tft.setRotation(tft.getRotation() + 1);
  tft.println("**Turbin Welding**");
  Serial.println("**Turbin Welding**");
  Serial.println("Start program");


  //*****input button******
  pinMode(k1, INPUT);
  pinMode(k2, INPUT);
  pinMode(k3, INPUT);
  pinMode(k4, INPUT);
  pinMode(k5, INPUT);
  pinMode(k6, INPUT);
  pinMode(rele, OUTPUT);
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
  pinMode(enable_motor2, OUTPUT);
  //digitalWrite(enable_motor1, HIGH);
  stepper2.setStepsPerMillimeter(steps2 * 1);
  stepper2.setSpeedInMillimetersPerSecond(speeds2);
  stepper2.setAccelerationInMillimetersPerSecondPerSecond(accel2);
  stepper2.connectToPins(MOTOR_STEP_PIN2, MOTOR_DIRECTION_PIN2);

  //*****steper3*****
  stepper3.connectToPins(MOTOR_STEP_PIN3, MOTOR_DIRECTION_PIN3);
  pinMode(enable_motor3, OUTPUT);
  //digitalWrite(enable_motor1, HIGH);
  stepper3.setStepsPerMillimeter(steps3 * 1);
  stepper3.setSpeedInMillimetersPerSecond(speeds3);
  stepper3.setAccelerationInMillimetersPerSecondPerSecond(accel3);
  stepper3.connectToPins(MOTOR_STEP_PIN3, MOTOR_DIRECTION_PIN3);
  //********led*********
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  digitalWrite(led_red, HIGH);
  for (int i = 0 ; i <= 20 ; i++) {
    digitalWrite(led_red, !digitalRead(led_red));
    digitalWrite(led_green, !digitalRead(led_green));
    delay(30);
  }
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, LOW);


  //  stepper.setSpeedInStepsPerSecond(5000);
  //  stepper.setAccelerationInStepsPerSecondPerSecond(5000);
  //
  //  stepper.setupMoveInSteps(10000);

  steps = 30;
  accel = 3000;
  speeds = 500;

  steps2 = 30;
  accel2 = 50;
  speeds2 = 500;

  steps3 = 30;
  accel3 = 50;
  speeds3 = 500;

  stepper.setStepsPerMillimeter(steps * 1);
  stepper.setSpeedInMillimetersPerSecond(speeds);
  stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);

  stepper2.setStepsPerMillimeter(steps2 * 1);
  stepper2.setSpeedInMillimetersPerSecond(speeds2);
  stepper2.setAccelerationInMillimetersPerSecondPerSecond(accel2);

  stepper3.setStepsPerMillimeter(steps3 * 1);
  stepper3.setSpeedInMillimetersPerSecond(speeds3);
  stepper3.setAccelerationInMillimetersPerSecondPerSecond(accel3);

  digitalWrite(led_red, HIGH);
}

void loop() {

  uart_input();
  manual();
  timer();
}


void timer() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  static int deciSeconds1 = 0;

  if (millis() >= timer) {
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    timer += 100;

    if (deciSeconds > 10) {
      deciSeconds = 0;
      ++sanie;
      if (sanie >= 59) {
        ++daqiqe;
        sanie = 0;
        if (daqiqe >= 59) {
          ++saat;
          daqiqe = 0;
        }
      }
    }

  }

}


///////////////*****manual**/*/////////////////
void  manual() {
  analog_read1 = analogRead(volom1);
  analog_read2 = analogRead(volom2);
  analog_read3 = analogRead(volom3);
  analog_read4 = analogRead(volom4);
  analog_read5 = analogRead(volom5);
  analog_read6 = analogRead(volom6);

  //********motor1*************
  step_speed1 = map(analog_read1 , 0 , 1024 , 1 , 100 );
  step_step1 = map(analog_read2 , 0 , 1024 , 0 , 1000 );
  speeds = step_speed1;
  accel = step_speed1;
  stepper.setSpeedInMillimetersPerSecond(speeds);

  if ((digitalRead(k1) == LOW)) {
    digitalWrite(led_green, HIGH);
    digitalWrite(rele, HIGH);
    stepper.moveRelativeInMillimeters(step_step1);
    digitalWrite(led_green, LOW);
    digitalWrite(rele, LOW);
  }

  if ((digitalRead(k2) == LOW)) {
    digitalWrite(led_green, HIGH);
     digitalWrite(rele, HIGH);
    stepper.moveRelativeInMillimeters(-step_step1);
    digitalWrite(led_green, LOW);
     digitalWrite(rele, LOW);
  }

  //********motor2*************
  step_speed2 = map(analog_read3 , 0 , 1024 , 0 , 5000 );
  step_step2 = map(analog_read4 , 0 , 1024 , 0 , 200 );
  speeds2 = step_speed2;
  accel2 = step_speed2;
  stepper2.setAccelerationInMillimetersPerSecondPerSecond(speeds2);

  if ((digitalRead(k3) == LOW)) {
    digitalWrite(led_green, HIGH);
    stepper2.moveRelativeInMillimeters(step_step2);
    digitalWrite(led_green, LOW);
  }

  if ((digitalRead(k4) == LOW)) {
    digitalWrite(led_green, HIGH);
    stepper2.moveRelativeInMillimeters(-step_step2);
    digitalWrite(led_green, LOW);
  }

  //********motor3*************
  step_speed3 = map(analog_read5 , 0 , 1024 , 0 , 5000 );
  step_step3 = map(analog_read6 , 0 , 1024 , 0 , 100 );
  speeds3 = step_speed3;
  accel3 = step_speed3;
  stepper3.setAccelerationInMillimetersPerSecondPerSecond(speeds3);

  if ((digitalRead(k5) == LOW)) {
    digitalWrite(led_green, HIGH);
    stepper3.moveRelativeInMillimeters(step_step3);
    digitalWrite(led_green, LOW);
  }

  if ((digitalRead(k6) == LOW)) {
    digitalWrite(led_green, HIGH);
    stepper3.moveRelativeInMillimeters(-step_step3);
    digitalWrite(led_green, LOW);
  }


  ++namayesh;
  if (namayesh >= 100) {
    namayesh = 0;
    tft.setTextColor(ST7735_WHITE);
    tft.setCursor(10, 20);
    tft.print("MOTOR1:");

    tft.setTextColor(ST7735_RED);
    tft.setCursor(10, 50);
    tft.print("MOTOR2:");

    tft.setTextColor(ST7735_YELLOW);
    tft.setCursor(10, 80);
    tft.print("MOTOR3:");


    tft.setTextColor(ST7735_WHITE);
    tft.fillRoundRect(0, 29, 160, 17, 1, ST7735_BLACK);
    tft.setCursor(10, 30);
    String text = "spd1:" + String(step_speed1) + " Step1:" + String(step_step1);
    tft.print(text);

    tft.setTextColor(ST7735_RED);
    tft.fillRoundRect(0, 59, 160, 17, 1, ST7735_BLACK);
    tft.setCursor(10, 60);
    text = "spd2:" + String(step_speed2) + " Step2:" + String(step_step2);
    tft.print(text);

    tft.setTextColor(ST7735_YELLOW);
    tft.fillRoundRect(0, 89, 160, 17, 1, ST7735_BLACK);
    tft.setCursor(10, 90);
    text = "spd3:" + String(step_speed3) + " Step3:" + String(step_step3);
    tft.print(text);

    tft.setTextColor(ST7735_GREEN);
    tft.fillRoundRect(0, 109, 160, 17, 1, ST7735_BLACK);
    tft.setCursor(10, 110);
    text = "TIME:" + String(saat) + ":" + String(daqiqe) + ":" + String(sanie);
    tft.print(text);
  }
}

///**********************input_uart**********************
void uart_input() {
  while (Serial.available() > 0) {
    cmnd = Serial.readString();
    lcd_print();
    uart_text();
  }
}


void uart_text() {
  //*****manual move******
  data = cmnd.substring(0, 2);
  if (data == "mu") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "move up:" + step_move_data;
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 1);
    lcd.print(lcd_char);
    Serial.println(lcd_char);
    digitalWrite(enable_motor1, LOW);
    stepper.moveToPositionInMillimeters(m_move);
    digitalWrite(enable_motor1, HIGH);
  }

  if (data == "md") {
    step_move_data = cmnd.substring(3, 10);
    m_move = step_move_data.toFloat();
    lcd_char = "move down:" + step_move_data;
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 1);
    lcd.print(lcd_char);
    Serial.println(lcd_char);
    digitalWrite(enable_motor1, LOW);
    stepper.moveToPositionInMillimeters(-m_move);
    digitalWrite(enable_motor1, HIGH);
  }

  //******calibration*******
  if (data == "st") {
    string_steps = cmnd.substring(3, 10);
    steps = string_steps.toFloat();
    lcd_char = "Step calib:" + string_steps;
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 1);
    lcd.print(lcd_char);
    Serial.println(lcd_char);
    stepper.setStepsPerMillimeter(25 * 1);
  }

  if (data == "ac") {
    string_accel = cmnd.substring(3, 10);
    accel = string_accel.toFloat();
    lcd_char = "acc calib:" + string_accel;
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 1);
    lcd.print(lcd_char);
    Serial.println(lcd_char);
    stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);
  }

  if (data == "sp") {
    string_speeds = cmnd.substring(3, 10);
    speeds = string_speeds.toFloat();
    lcd_char = "speed:" + string_speeds;
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 1);
    lcd.print(lcd_char);
    Serial.println(lcd_char);
    stepper.setSpeedInMillimetersPerSecond(speeds);
  }

}

//*******lcd_print********
void lcd_print() {
  lcd.setCursor(0, 3);
  lcd.print("                    ");
  lcd.setCursor(0, 3);
  lcd.print(cmnd);
}

//*****************button*************
void button_input() {
  if (digitalRead(k1) == 0)menu();
}

//**************menu***************
void menu() {
  lcd.clear();
  delay (200);
  count_menu = 0;
  exit_menu = 0;
  while (1) {
    if (exit_menu == 1) {
      lcd.begin(20, 4);
      break;
    }
    button_menu();
    if (count_menu > 3)count_menu = 0;
    if (count_menu < 0)count_menu = 0;
    lcd.setCursor(15, count_menu);
    lcd.print("<==");
    lcd.setCursor(0, 0);
    lcd.print("Steper control");
    lcd.setCursor(0, 1);
    lcd.print("sensor");
    lcd.setCursor(0, 2);
    lcd.print("Serial input");
    lcd.setCursor(0, 3);
    lcd.print("bottom motor");
    if (digitalRead(k1) == 0 ) {
      if (count_menu == 0)step_menu();
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    ***CNC CUT***");
  lcd.setCursor(0, 3);
  lcd.print("WAIT FOR DATA...");
  delay (200);
}
//****button_menu*****
void button_menu() {
  if (digitalRead(k2) == 0 )exit_menu = 1;
  if (digitalRead(k3) == 0 ) {
    --count_menu;
    lcd.begin(20, 4);
    lcd.clear();
    delay(250);
  }
  if (digitalRead(k4) == 0 ) {
    ++count_menu;
    lcd.begin(20, 4);
    lcd.clear();
    delay(250);
  }
}

//**********steper control*********
void step_menu() {
  lcd.clear();
  delay (200);
  count_menu = 0;
  exit_menu = 0;
  while (1) {
    if (exit_menu == 1) {
      count_menu = 0;
      exit_menu = 0;
      lcd.begin(20, 4);
      menu();
      break;
    }
    button_menu();
    if (count_menu > 3)count_menu = 0;
    if (count_menu < 0)count_menu = 0;
    lcd.setCursor(15, count_menu);
    lcd.print("<==");
    lcd.setCursor(0, 0);
    lcd.print("Step movment");
    lcd.setCursor(0, 1);
    lcd.print("pulse degree");
    lcd.setCursor(0, 2);
    lcd.print("step speed");
    lcd.setCursor(0, 3);
    lcd.print("save setting");
    if (digitalRead(k1) == 0 ) {
      if (count_menu == 0)Step_movment();
    }
  }


}

//**********Step movment()*****************
void Step_movment() {
  lcd.clear();
  delay (200);
  count_menu = 0;
  exit_menu = 0;
  digitalWrite(enable_motor1, LOW);
  while (1) {
    if (exit_menu == 1) {
      count_menu = 0;
      exit_menu = 0;
      digitalWrite(enable_motor1, HIGH);
      lcd.begin(20, 4);
      step_menu();
      break;
    }

    button_menu();
    if (count_menu > 4)count_menu = 0;
    if (count_menu < 0)count_menu = 0;
    if (count_menu <= 2) {
      lcd.setCursor(19, count_menu);
      lcd.print("<");
    }
    if (count_menu == 3) {
      lcd.setCursor(11, count_menu);
      lcd.print("<");
    }

    if (count_menu == 4) {
      lcd.setCursor(19, count_menu);
      lcd.print("<");
    }

    //*********set***************
    if (digitalRead(k1) == 0 ) {
      //***stop_start***
      if (count_menu == 0 ) {
        //stepper.moveRelativeInSteps(200);
        if (m_rotate == 0) {
          stepper.moveToPositionInMillimeters(m_move);
          m_move = m_move + 10;
        }
        if (m_rotate == 1) {
          stepper.moveToPositionInMillimeters(-m_move);
          m_move = m_move - 10;
        }

        if (m_move < 0)m_move = 0;
        delay(50);
      }

      //***move control****
      if (count_menu == 1 ) {
        while (1) {
          if (digitalRead(k2) == 0 ) {
            lcd.clear();
            delay(250);
            break;
          }
          if (digitalRead(k3) == 0 ) {
            ++m_move;
            delay(100);
          }

          if (digitalRead(k4) == 0 ) {
            --m_move;
            delay(100);
          }

          if (m_move < 0)m_move = 0;
          String MOVE = "MOVE:" + String(m_move) + " mm <> " ;
          lcd.setCursor(0, 1);
          lcd.print(MOVE);
        }

      }

      //***accel control****
      if (count_menu == 2 ) {
        while (1) {
          if (digitalRead(k2) == 0 ) {
            lcd.clear();
            delay(250);
            break;
          }
          if (digitalRead(k3) == 0 ) {
            accel = accel + 1;
            delay(50);
          }

          if (digitalRead(k4) == 0 ) {
            accel = accel - 1;
            delay(50);
          }

          if (accel < 0)accel = 0;
          String ACCEL = "ACCEL:" + String(accel) + " m2/s<>" ;
          lcd.setCursor(0, 2);
          lcd.print(ACCEL);
        }

      }

      //***step control****
      if (count_menu == 3 ) {
        while (1) {
          if (digitalRead(k2) == 0 ) {
            lcd.clear();
            delay(250);
            break;
          }
          if (digitalRead(k3) == 0 ) {
            steps = steps + 1;
            delay(100);
          }

          if (digitalRead(k4) == 0 ) {
            steps = steps - 1;
            delay(100);
          }

          if (steps < 0)steps = 0;
          String STEP = "STEP:" + String(steps) + " <> ";
          lcd.setCursor(0, 3);
          lcd.print(STEP);
        }

      }

      if (count_menu == 4 && m_rotate == 0 ) {
        m_rotate = 1;
        delay(250);
      } else {
        m_rotate = 0;
        delay(250);
      }


    }
    //*********set***************

    String MOVE = "MOVE:" + String(m_move) + " mm" ;
    String ACCEL = "ACCEL:" + String(accel) + " m2/s" ;
    String STEP = "STEP:" + String(steps) ;
    lcd.setCursor(0, 0);
    lcd.print("MOTOR RUN");
    lcd.setCursor(0, 1);
    lcd.print(MOVE);
    lcd.setCursor(0, 2);
    lcd.print(ACCEL);
    lcd.setCursor(0, 3);
    lcd.print(STEP);
    lcd.setCursor(12, 3);
    if (m_rotate == 0)lcd.print("FORWARD");
    if (m_rotate == 1)lcd.print("BAKWARD");


    //stepper.setSpeedInStepsPerSecond(steps);
    //stepper.setAccelerationInStepsPerSecondPerSecond(accel);

    stepper.setStepsPerMillimeter(steps * 1);
    stepper.setSpeedInMillimetersPerSecond(speeds);
    stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);
  }
}

