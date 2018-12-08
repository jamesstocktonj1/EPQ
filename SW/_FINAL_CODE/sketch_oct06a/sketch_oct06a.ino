#include <Keyboard.h>

void setup() {
  Keyboard.begin();
  pinMode(7, OUTPUT);

  delay(1000);
  digitalWrite(7, HIGH);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  //delay(100);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("cmd.exe\n");
  digitalWrite(7, LOW);
  //Keyboard.press(KEY_RETURN);
  //Keyboard.release(KEY_RETURN);
}

void loop() {
  // put your main code here, to run repeatedly:

}

