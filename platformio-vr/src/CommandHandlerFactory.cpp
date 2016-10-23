#include "CommandHandlerFactory.h"

CommandHandlerFactory::CommandHandlerFactory(UnitPeripheralsContainer* container) {
  this->unit = container;
  this->factoryMap[TYPE_COMMAND_MOTOR] = new MotorCommandHandler(this->unit->getMotor());
}

CommandHandlerFactory::~CommandHandlerFactory() {
}

CommandHandler* CommandHandlerFactory::createCommandHandler(Command * command) {
  return this->createCommandHandler(command->getCommandType());
}

CommandHandler* CommandHandlerFactory::createCommandHandler(uint8_t commandType) {
  ChMapIterator iterator = this->factoryMap.find(commandType);

  if (iterator == this->factoryMap.end()) {
    return 0;
  }

  return this->factoryMap[commandType];
}
