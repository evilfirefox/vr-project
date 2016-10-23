#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <stdint.h>
#include "Command.h"

class CommandHandler {
public:
  virtual void process(Command*);
};

#endif
