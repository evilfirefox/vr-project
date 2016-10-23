#include "MotorCommandHandler.h"

MotorCommandHandler::MotorCommandHandler(Motor* motor) {
  this->motor = motor;
}

MotorCommandHandler::~MotorCommandHandler() {
  delete this->motor;
}

Motor* MotorCommandHandler::getMotor() {
  return this->motor;
}

MotorCommandHandler* MotorCommandHandler::setMotor(Motor * motor) {
  this->motor = motor;
  return this;
}

void MotorCommandHandler::process(Command* command) {
  switch (command->getCommandType()) {
    case COMMAND_MOTOR_START: {
      uint8_t direction = *(command->getData());
      this->motor->start(direction);
      break;
    }
    default:
    case COMMAND_MOTOR_STOP:
      this->motor->stop();
      break;
  }
}
