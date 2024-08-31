int count_lcd;
void lcd_show() {
  ++count_lcd;
  if (count_lcd >= 1000) {
    count_lcd = 0;

    tft.setTextColor(ST7796S_RED);
    tft.setTextSize(2);
    tft.setCursor(0, 300);
    tft.println("Turbin welding        ***Firozjaei***");

    String ss;
    tft.setTextColor(ST7796S_GREEN);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    ss = "MOTOR1 Speed:" + String(speeds);
    tft.fillRoundRect(150, 0, 100, 20, 2, ST7796S_BLACK);
    tft.println(ss);

    tft.setCursor(0, 40);
    ss = "MOTOR2 Speed:" + String(main_volom);
    tft.fillRoundRect(150, 40, 100, 20, 2, ST7796S_BLACK);
    tft.println(ss);

    //***************button*************
    tft.setTextColor(ST7796S_WHITE);
    tft.setTextSize(1);
    tft.setCursor(400, 0);
    ss = "BUTTON:" + String(adc_button);
    tft.fillRoundRect(420, 0, 80, 10, 2, ST7796S_BLACK);
    tft.println(ss);

    //**************menu**************
    if (change == 1) {
      change = 0;
      if (menu_count == 0) {
        tft.setTextColor(ST7796S_RED);
        tft.setTextSize(2);
        tft.setCursor(0, 80);
        ss = "4 POINT";
        tft.fillRoundRect(0, 78, 85, 18, 2, ST7796S_WHITE);
        tft.println(ss);

        tft.setTextColor(ST7796S_CYAN);
        tft.setCursor(0, 100);
        ss = "6 POINT";
        tft.println(ss);

        tft.setTextColor(ST7796S_CYAN);
        tft.setCursor(0, 120);
        ss = "8 POINT";
        tft.println(ss);
        digitalWrite(led_g, HIGH);
        digitalWrite(led_y, LOW);
        digitalWrite(led_r, LOW);
      }

      if (menu_count == 1) {
        tft.setTextColor(ST7796S_RED);
        tft.setTextSize(2);
        tft.setCursor(0, 100);
        ss = "6 POINT";
        tft.fillRoundRect(0, 98, 85, 18, 2, ST7796S_WHITE);
        tft.println(ss);

        tft.setTextColor(ST7796S_CYAN);
        tft.setCursor(0, 80);
        ss = "4 POINT";
        tft.println(ss);

        tft.setTextColor(ST7796S_CYAN);
        tft.setCursor(0, 120);
        ss = "8 POINT";
        tft.println(ss);
        digitalWrite(led_g, LOW);
        digitalWrite(led_y, HIGH);
        digitalWrite(led_r, LOW);
      }

      if (menu_count == 2) {
        tft.setTextColor(ST7796S_RED);
        tft.setTextSize(2);
        tft.setCursor(0, 120);
        ss = "8 POINT";
        tft.fillRoundRect(0, 118, 85, 18, 2, ST7796S_WHITE);
        tft.println(ss);

        tft.setTextColor(ST7796S_CYAN);
        tft.setCursor(0, 100);
        ss = "6 POINT";
        tft.println(ss);

        tft.setTextColor(ST7796S_CYAN);
        tft.setCursor(0, 80);
        ss = "4 POINT";
        tft.println(ss);
        digitalWrite(led_g, LOW);
        digitalWrite(led_y, LOW);
        digitalWrite(led_r, HIGH);
      }
    }
  }
}