

void button() {
  adc_button = analogRead(A0);
  if (adc_button >= 50 && adc_button < 70) {
    up_fak = 1;
  } else if (adc_button >= 140 && adc_button < 160) {
    down_fak = 1;
  } else if (adc_button >= 290 && adc_button < 310) {
    right_main = 1;
  } else if (adc_button >= 360 && adc_button < 400) {
    left_main = 1;
  } else if (adc_button >= 430 && adc_button < 450) {
    left_ = 1;
  } else if (adc_button >= 475 && adc_button < 500) {
    right_ = 1;
  } else if (adc_button >= 500 && adc_button < 525) {
    start_welding = 1;
  } else if (adc_button >= 530 && adc_button < 560) {
    start_ = 1;
  } else {
    up_fak = 0;
    down_fak = 0;
    right_main = 0;
    left_main = 0;
    left_ = 0;
    right_ = 0;
    start_ = 0;
    start_welding = 0;
  }
}