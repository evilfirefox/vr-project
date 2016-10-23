#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include <Arduino.h>

#define PIN_MOTOR_SWITCH 2
#define PIN_MOTOR_A 3
#define PIN_MOTOR_B 4

#define MOTOR_DIRECTION_FWD 0
#define MOTOR_DIRECTION_REV 1

class Motor {
  public:
     Motor();
     void start(uint8_t);
     void stop();
};

#endif
