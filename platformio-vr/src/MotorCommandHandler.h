#ifndef MOTOR_COMMAND_HANDLER_H
#define MOTOR_COMMAND_HANDLER_H

#define COMMAND_MOTOR_START 0
#define COMMAND_MOTOR_STOP 1

#include "Command.h"
#include "CommandHandler.h"
#include "Motor.h"

class MotorCommandHandler : protected CommandHandler {
protected:
  Motor* motor;

public:
  MotorCommandHandler(Motor*);
  ~MotorCommandHandler();
  Motor* getMotor();
  MotorCommandHandler* setMotor(Motor*);
  virtual void process(Command*);
};

#endif
