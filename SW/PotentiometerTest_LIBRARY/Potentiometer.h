
#ifndef Potentiometer_h
#define Potentiometer_h

#include "Arduino.h"

class Potentiometer {
  uint8_t preVal = 0;
  uint8_t curVal = 0;
  uint8_t PIN;
  
  public:
    Potentiometer(uint8_t pin){

      uint8_t temp_val = analogRead(pin);
      preVal = temp_val;
      curVal = temp_val;
    }

    inline bool update(){
      preVal = curVal;
      curVal = analogRead(PIN);

      return (preVal%
    }

    inline uint8_t getVal(){
      
    }
};

#endif
