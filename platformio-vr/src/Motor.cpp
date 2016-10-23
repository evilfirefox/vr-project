#include "Motor.h"

Motor::Motor() {
  pinMode(PIN_MOTOR_SWITCH, OUTPUT);
  pinMode(PIN_MOTOR_A, OUTPUT);
  pinMode(PIN_MOTOR_B, OUTPUT);
}

void Motor::start(uint8_t direction) {
  digitalWrite(PIN_MOTOR_SWITCH, HIGH);
  if (direction == MOTOR_DIRECTION_FWD) {
    digitalWrite(PIN_MOTOR_A, HIGH);
    digitalWrite(PIN_MOTOR_B, LOW);
  } else {
    digitalWrite(PIN_MOTOR_A, LOW);
    digitalWrite(PIN_MOTOR_B, HIGH);
  }
}

void Motor::stop() {
  digitalWrite(PIN_MOTOR_SWITCH, LOW);
}
