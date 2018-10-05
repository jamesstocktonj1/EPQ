//EPQ James Stockton

/*
 * 
 * This project will test the rotary encoder and menu interface 
 * 
 * Targets
 *  - Make the encoder select the 8 leds 
 *  - Make the leds flash whilst selecting then solid when encoder clicked
 * 
 * 
 */





#include<Encoder.h>


//declare the pin numbers of the leds
#define LED0 0
#define LED1 0
#define LED2 0
#define LED3 0
#define LED4 0
#define LED5 0
#define LED6 0
#define LED7 0
uint8_t LEDS[8] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7};

//declares the rotary encoder pins
#define ENC0 0
#define ENC1 2

Encoder myEnc(ENC0, ENC1);



//placement variable
long prePos = 0;
long curPos = 0;

uint8_t curLed = 0;

void setup() {
  while(!Serial);
  Serial.println("INIT");
  delay(100);
}

void loop() {
  

}



void checkEncoder(){
  prePos = curPos;
  curPos = myEnc.read() / 4;              //CHANGE TO BIT SHIFT (>> 2)

  if(curPos != prePos){
    
  }
}

void updateLEDs(){
  for(int i=0; i<8; i++){
    digitalWrite(LEDS[i], (bool)curLed == i);
  }
}
