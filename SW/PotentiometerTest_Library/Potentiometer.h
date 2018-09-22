//EPQ James Stockton




#ifndef Potentiometer_h
#define Potentiometer_h

#include "Arduino.h"



class Potentiometer {     
  int preVal = 0;
  int curVal = 0;
  uint8_t PIN;
  
  public:
    Potentiometer(uint8_t pinNum){
      PIN = pinNum;
    }

    inline bool hasChanged(){
      preVal = curVal;            //sets the previous value, making way for reading the current value
      curVal = analogRead(PIN);   //reads current value

      return (preVal >> 3) != (curVal >> 3);        // Val >> 4 performs a bitshift, converting 0-1023 to 0-127
                                                    // the != compares the new and the old value so return true if they are different
    }

    inline uint8_t getVal(){
      return curVal >> 3;         //convert the 0-1023 value to 0-127 the value midi wants
    }
};

#endif
