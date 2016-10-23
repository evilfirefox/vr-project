#include "RadioCommandFactory.h"

RadioCommandFactory::RadioCommandFactory() {
}

Command* RadioCommandFactory::createCommand(uint8_t* rawData, uint8_t size) {
  uint8_t type = *rawData;
  uint8_t dataSize =size - 1;
  uint8_t* data = (uint8_t*) malloc(sizeof(uint8_t) * dataSize);
  memcpy(data, (rawData+1), dataSize);
  Command* result = new Command(type, dataSize, data);
  return result;
}
