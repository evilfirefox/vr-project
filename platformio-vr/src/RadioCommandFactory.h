#ifndef RADIO_COMMAND_FACTORY_H
#define RADIO_COMMAND_FACTORY_H

#include <cstdlib>
#include <stdint.h>
#include "CommandFactory.h"
#include "Command.h"

class RadioCommandFactory : protected CommandFactory {
public:
  RadioCommandFactory();
  Command* createCommand(uint8_t*, uint8_t);
};

#endif
