// **** SERIAL RELAY ****
// By Steen Eiler Jørgensen
//
// This program is designed to relay data from an APC220 on pins 8-13
// (just plug the APC220 directly into the Arduino) to the serial USB
// connection and the other way as well.
//
// The APC220 is accessed via softwareserial, and the received data is
// transmitted on the hardware serial.

#include <SoftwareSerial.h>

// SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
SoftwareSerial apc220(10,11);

void setup() {
  Serial.begin(9600);
  apc220.begin(9600);
  
  pinMode( 8, OUTPUT); // SET
  pinMode( 9, OUTPUT); // AUX
  pinMode(10, INPUT ); // RX
  pinMode(11, OUTPUT); // TX
  pinMode(12, OUTPUT); // EN
  pinMode(13, OUTPUT); // VCC

  digitalWrite( 8, HIGH);  // SET - high to disable setup mode
  digitalWrite( 9, LOW );  // AUX
  digitalWrite(12, HIGH);  // EN  - high to enable radio
  digitalWrite(13, HIGH);  // VCC - supply voltage
}

void loop() {
  if( apc220.available()>0 ) {
    Serial.write( apc220.read() );
  }
  if( Serial.available()>0 ) {
    apc220.write( Serial.read() );
  }
}
