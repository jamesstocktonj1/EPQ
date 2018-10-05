//EPQ James Stockton


/*
 * 
 */



#include <MIDIUSB.h>            //library for midi over usb on the 32u4 chip
#include "Potentiometer.h"      //own library 


#define PIN A4
#define CC_num 25

Potentiometer pot(PIN);


void setup() {
}

void loop() {
  if(pot.hasChanged()){                               //sees whether the potentiometer has changed (true / false)
    controlChange(0, CC_num, pot.getVal());           //if it has changed then the midi message will be sent
    MidiUSB.flush();                                  //this sends the midi data out via usb
  }
  delay(25);
}



void controlChange(byte channel, byte number, byte value){      //this function converts the three numbers into 4 bytes according to the midi protocol (more info in 5.3.1)
  midiEventPacket_t CC = {0x0B, 0xB0 | channel, number, value};
  MidiUSB.sendMIDI(CC);
}

