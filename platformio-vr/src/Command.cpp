#include "Command.h"

Command::Command() {
  this->size = 0;
}

Command::Command(uint8_t commandType) {
  this->commandType = commandType;
  this->size = 0;
}

Command::Command(uint8_t commandType, uint8_t dataSize, uint8_t* data) {
  this->commandType = commandType;
  this->size = dataSize;
  memcpy((void*) &this->data, &data, sizeof(data));
}

Command::~Command() {
  delete this->data;
}

uint8_t Command::getCommandType() {
  return this->commandType;
}

uint8_t* Command::getData() {
  return this->data;
}

Command* Command::setCommandType(uint8_t commandType) {
  this->commandType = commandType;
  return this;
}

Command* Command::setData(uint8_t *data, uint8_t dataSize) {
  this->size = dataSize;
  memcpy((void*) &this->data, &data, sizeof(data));
  return this;
}

uint8_t Command::getSize() {
  return this->size;
}
