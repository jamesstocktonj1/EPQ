void setup() {
  pinMode(13, OUTPUT);
  delay(1000);
}

void loop() {
  asm("sbi 0x08, 0x07");
  delay(1000);
  asm("cbi 0x08, 0x07");
  delay(1000);
}
