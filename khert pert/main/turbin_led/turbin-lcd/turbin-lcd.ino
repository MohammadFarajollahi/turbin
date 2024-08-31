#include <AccelStepper.h>
AccelStepper stepper1(1, 5, A6);  // (Type of driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 3, A7);  // (Type of driver: with 2 pins, STEP, DIR)

//*******steper_motor******
#include <SpeedyStepper.h>
const int MOTOR_STEP_PIN = 3;
const int MOTOR_DIRECTION_PIN = 2;
const int enable_motor1 = 4;
SpeedyStepper stepper;


int count_menu;
int exit_menu;
float m_move = 20;
float steps = 20;
float accel = 100;
int speeds = 200;
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

int rele = 8;
int led = -1;

int led_g = A3;
int led_y = A4;
int led_r = A5;
//******lcd**************
#include <Adafruit_GFX.h>  // Core graphics library
#include "Adafruit_ST7796S_kbv.h"
#include <SPI.h>
#define TFT_RST -1
#define TFT_DC 9
#define TFT_CS 10
Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, TFT_RST);

int adc_button;
int left_main;
int right_main;
int down_fak;
int up_fak;
int fak_volom;
int main_volom;
int left_;
int right_;
int dir2 = 7;
int dir1 = 2;
int start_;
int menu_count;
int change = 1;
int full_move = 5125;
int start_welding;
void setup() {
  Serial.begin(9600);

  stepper1.setMaxSpeed(20000);
  stepper2.setMaxSpeed(20000);
  //********STEPER MOTOR******
  pinMode(rele, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_r, OUTPUT);
  //*****steper1*****
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);
  pinMode(enable_motor1, OUTPUT);
  //digitalWrite(enable_motor1, HIGH);
  stepper.setStepsPerMillimeter(steps * 1);
  stepper.setSpeedInMillimetersPerSecond(speeds);
  stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);
  stepper.connectToPins(MOTOR_STEP_PIN, MOTOR_DIRECTION_PIN);

  //*****steper2*****



  steps = 25;
  accel = 5000;
  speeds = 1000;

  stepper.setStepsPerMillimeter(steps * 1);
  stepper.setSpeedInMillimetersPerSecond(speeds);
  stepper.setAccelerationInMillimetersPerSecondPerSecond(accel);
  digitalWrite(enable_motor1, LOW);



  //*********LCD*********
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ST7796S_BLACK);
}

void loop() {
  button();
  volom();
  lcd_show();
  manual();
  auto_();
}

void manual() {

  //****************fak control**************
  if (up_fak == 1) {
    stepper1.setSpeed(speeds);
    digitalWrite(dir2, HIGH);
    while (1) {
      stepper1.runSpeed();
      button();
      if (up_fak == 0) break;
    }
  }


  if (down_fak == 1) {
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
    stepper2.setSpeed(main_volom);
    digitalWrite(dir1, HIGH);
    while (1) {
      stepper2.runSpeed();
      button();
      if (right_main == 0) break;
    }
  }


  if (left_main == 1) {
    stepper1.setSpeed(main_volom);
    digitalWrite(dir1, LOW);
    while (1) {
      stepper2.runSpeed();
      button();
      if (left_main == 0) break;
    }
  }
}
