#ifndef COMMAND_HANDLER_FACTORY_H
#define COMMAND_HANDLER_FACTORY_H

#define TYPE_COMMAND_MOTOR 0

#include <stdint.h>
#include <map>
#include "UnitPeripheralsContainer.h"
#include "CommandHandler.h"
#include "MotorCommandHandler.h"

typedef std::map<uint8_t, CommandHandler*> ChMap;
typedef std::map<uint8_t, CommandHandler*>::iterator ChMapIterator;

class CommandHandlerFactory {
protected:
  UnitPeripheralsContainer* unit;
  ChMap factoryMap;

public:
  CommandHandlerFactory(UnitPeripheralsContainer*);
  ~CommandHandlerFactory();
  CommandHandler* createCommandHandler(Command*);
  CommandHandler* createCommandHandler(uint8_t);
};

#endif
