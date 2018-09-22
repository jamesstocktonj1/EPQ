/*EPQ James Stockton
 *
 * This project explores potentiomter control
 * 
 * Targets
 *  - Make sure the potentiometer only outputs when the value changes
 *  - Make sure the potentiometer doesn't output rogue data / flicking between values
 *  - Make sure the value is changed from 10-bit (0-1023) to 8-bit (0-127) since midi uses 8-bit
 *  
 * Next Step
 *  - Convert this program into a library
 */



#define PIN A3      //pin number constant (the potentiometer pin)

int preVal = 0;     //stores previous value so it can detect a change
int curVal = 0;


void setup() {
  while(!Serial);       //this waits for the usb serial port which will be used for debuging

  delay(100);
  Serial.println("INIT");     //tells the program that it has started well

}

void loop() {
  if(potChanged()){
    Serial.println(potValue());     //if the pot has changed then it prints the new value
  }
  delay(50);          //slight delay 
}


//function return a true or false value of if the potentiometer has changed
bool potChanged(){
  preVal = curVal;            //sets the previous value, making way for reading the current value
  curVal = analogRead(PIN);   //reads current value
  
  return (preVal >> 3) != (curVal >> 3);        // Val >> 4 performs a bitshift, converting 0-1023 to 0-127
                                                // the != compares the new and the old value so return true if they are different
}

uint8_t potValue(){
  return curVal >> 3;         //convert the 0-1023 value to 0-127 the value midi wants
}

