//EPQ James Stockton



/*
 * 
 * This project explores potentiometer control with a homemade library
 * 
 * 
 * Targets
 *  - Make it object oriented
 *  - (other targets discussed in PotentiometerTest_not_library)
 * 
 */

#define PIN A3


Potentiometer pot(PIN);



void setup() {
  while(!Serial);       //this waits for the usb serial port which will be used for debuging

  delay(100);
  Serial.println("INIT");     //tells the program that it has started well
}

void loop() {
  if(pot.hasChanged()){
    Serial.println(pot.getVal());     //if the pot has changed then it prints the new value
  }
  delay(50);          //slight delay 
}
