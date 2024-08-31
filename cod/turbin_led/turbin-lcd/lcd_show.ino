int count_lcd;
void lcd_show() {
  ++count_lcd;
  if (count_lcd >= 0) {
    count_lcd = 0;



    //**************menu**************
    if (change == 1) {
      delay(500);
      change = 0;
      if (menu_count == 0) {

        digitalWrite(led_g, HIGH);
        digitalWrite(led_y, LOW);
        digitalWrite(led_r, LOW);
      }

      if (menu_count == 1) {


        digitalWrite(led_g, LOW);
        digitalWrite(led_y, HIGH);
        digitalWrite(led_r, LOW);
      }

      if (menu_count == 2) {

        digitalWrite(led_g, LOW);
        digitalWrite(led_y, LOW);
        digitalWrite(led_r, HIGH);
      }

      up_fak = 0;
      down_fak = 0;
      right_main = 0;
      left_main = 0;
      left_ = 0;
      right_ = 0;
      start_ = 0;
      start_welding = 0;
      start_1 = 0;
      start_welding1 = 0;

      start_1 = 0;
      up_fak1 = 0;
      down_fak1 = 0;
      right_main1 = 0;
      left_main1 = 0;
      left_1 = 0;
      right_1 = 0;
      start_welding1 = 0;
    }
  }
}
