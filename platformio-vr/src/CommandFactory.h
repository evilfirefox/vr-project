#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include <stdint.h>
#include "Command.h"

class CommandFactory {
public:
  virtual Command* createCommand(uint8_t*, uint8_t);
};

#endif
