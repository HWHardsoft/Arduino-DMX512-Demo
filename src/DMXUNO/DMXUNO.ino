/*
 * DMX Fade demo for Arduino UNO and RS485 Shield
 *
 * by Zihatec, 2026  
 *
 * This sketch fades the colors red, green and blue 
 *
 * DIP switch setting:
 *  S1: OFF - ON - ON - OFF
 *  S2: OFF - OFF - ON - ON
 *  S3: ON - OFF - ON - ON
 * 
 * Jumper setting for UNO R3 and R4:
 *  JP1: 5V
 *  JP2 - JP4: 
 *  0 ...
 *  1 xx.
 *  2 ...
 *  3 ...
 *  4 ...
 *  5 ...
 *  6 ..
 *  7 .. 
*/

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) 
   #define NO_DEBUG_UART
#endif

#include <ArduinoRS485.h> // the ArduinoDMX library depends on ArduinoRS485
#include <ArduinoDMX.h>


const int universeSize = 16;
int iCOL = 1; // color register pointer
int iDIM;     // dimming

void setup() {
  //Serial.begin(9600);
  //while (!Serial);

  // initialize the DMX library with the universe size
  if (!DMX.begin(universeSize)) {
    #if !defined(NO_DEBUG_UART)
    Serial.println("Failed to initialize DMX!");
    #endif
    while (1); // wait for ever
  }
  DMX.beginTransmission();
  DMX.write(1, 255);  // Dimming 255%
  DMX.write(2, 0);    // Red 0%
  DMX.write(3, 0);    // Green 0%
  DMX.write(4, 0);    // Blue 0%
  DMX.write(5, 1);    // CH1 - CH4 valid, Strobe off
  DMX.write(6, 0);    // Light off
  DMX.endTransmission();
  #if !defined(NO_DEBUG_UART)
  Serial.println("DMX Demo for Arduino UNO R4");
  #endif
}

void loop() {
  // set color
  iCOL++;
  if (iCOL > 4) iCOL = 2;   

  #if !defined(NO_DEBUG_UART)
  Serial.print("fading lights of channel: "); Serial.println(iCOL);
  #endif
  
  //fade in
  for (iDIM=0; iDIM < 255; iDIM++) {
    DMX.beginTransmission();
    DMX.write(iCOL, iDIM); // dimming
    DMX.endTransmission();
    delay(10);
  }

  delay(100);
  
  //fade out
  for (iDIM=255; iDIM > 0; iDIM--) {
    DMX.beginTransmission();
    DMX.write(iCOL, iDIM); // dimming
    DMX.endTransmission();
    delay(10);
  }

  delay(100);
  
}

