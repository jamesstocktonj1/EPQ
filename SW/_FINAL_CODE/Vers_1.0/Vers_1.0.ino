//EPQ James Stockton



/*
 * First Version of Final Code
 * 
 * 
 */


#include <MIDIUSB.h>
#include "Potentiometer.h"
#include <Encoder.h>


//Potentiometer setup
#define POT1_PIN A2
#define POT2_PIN A3
#define POT3_PIN A4
#define POT4_PIN A5

Potentiometer POT1(POT1_PIN);
Potentiometer POT2(POT2_PIN);
Potentiometer POT3(POT3_PIN);
Potentiometer POT4(POT4_PIN);

Potentiometer POTS[4] = {POT1, POT2, POT3, POT4};


//LEDs setup
int LED_PINS[8] = {13, 5, 10, 9, 8, 6, 12, 4};


//Encoder setup
#define PIN1 0
#define PIN2 2

Encoder ENCODER(PIN1, PIN2);




//MIDI message setup
int CC_vals[4] = {25, 26, 27, 28};
int CHANNEL_vals[4] = {0, 0, 0, 0};

void setup() {
  //analogReference(EXTERNAL);

}

void loop() {
  for(int i=0; i<4; i++){             //loops through each pot, checking if its change
    if(POTS[i].hasChanged()){
      controlChange(CHANNEL_vals[i], CC_vals[i], POTS[i].getVal());
      MidiUSB.flush();
    }
  }
  delay(25);
}



void controlChange(byte channel, byte number, byte value){      //this function converts the three numbers into 4 bytes according to the midi protocol (more info in 5.3.1)
  midiEventPacket_t CC = {0x0B, 0xB0 | channel, number, value};
  MidiUSB.sendMIDI(CC);
}
