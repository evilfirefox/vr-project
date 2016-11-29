#include "Motor.h"

Motor::Motor(DigitalIOWrapper* digitalIO) {
  this->digitalIO = digitalIO;
  this->digitalIO->pinMode(PIN_MOTOR_SWITCH, OUTPUT);
  this->digitalIO->pinMode(PIN_MOTOR_A, OUTPUT);
  this->digitalIO->pinMode(PIN_MOTOR_B, OUTPUT);
}

void Motor::start(uint8_t direction) {
  this->digitalIO->digitalWrite(PIN_MOTOR_SWITCH, HIGH);
  if (direction == MOTOR_DIRECTION_FWD) {
    this->digitalIO->digitalWrite(PIN_MOTOR_A, HIGH);
    this->digitalIO->digitalWrite(PIN_MOTOR_B, LOW);
  } else {
    this->digitalIO->digitalWrite(PIN_MOTOR_A, LOW);
    this->digitalIO->digitalWrite(PIN_MOTOR_B, HIGH);
  }
}

void Motor::stop() {
  this->digitalIO->digitalWrite(PIN_MOTOR_SWITCH, LOW);
}
