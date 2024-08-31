

void volom() {

  fak_volom = analogRead(A1);
  main_volom = analogRead(A2);
  

  speeds = map(fak_volom, 0, 1023, 0, 6000);
  main_volom = map(main_volom, 0, 1023, 0, 6000);
}