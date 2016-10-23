#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>
#include <cstring>

class Command {
protected:
  uint8_t commandType;
  uint8_t size;
  uint8_t* data;

public:
  Command();
  Command(uint8_t);
  Command(uint8_t, uint8_t, uint8_t*);
  ~Command();

  uint8_t getCommandType();
  uint8_t* getData();
  Command* setCommandType(uint8_t);
  Command* setData(uint8_t*, uint8_t);
};

#endif
