#include <stdint.h>
#include <SPI.h>
#include <RH_ASK.h>
#include "Motor.h"

#define SERIAL_BAUDRATE 9600
#define RADIO_BAUDRATE 2000
#define PIN_RX 11
#define PIN_TX 12
#define BUFFER_SIZE 8

RH_ASK radio = RH_ASK(RADIO_BAUDRATE, PIN_RX, PIN_TX);
uint8_t buffer[BUFFER_SIZE];
uint8_t size =  sizeof(buffer);
Motor motor = Motor();

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(PIN_RX, INPUT);
  pinMode(PIN_TX, OUTPUT);
  radio.init();
  radio.setModeRx();
}

void loop() {
  /*if (radio.available()) {
    if (radio.recv(buffer, &size)) {
      Serial.println("recieved:");
      for (int i =0; i<size; i++){
        Serial.write(buffer, size);
      }
      Serial.println();
    } else {
      Serial.println('recieve failed');
    }
  }*/
  motor.start(MOTOR_DIRECTION_FWD);
  delay(2000);
  motor.stop();
  delay(2000);
  motor.start(MOTOR_DIRECTION_REV);
  delay(2000);
  motor.stop();
  delay(2000);
}
