#ifndef DIGITAL_IO_WRAPPER_H
#define DIGITAL_IO_WRAPPER_H

#include <Arduino.h>

class AbstractDigitalIOWrapper {
public:
  virtual void pinMode(uint8_t, uint8_t);
  virtual void digitalWrite(uint8_t, uint8_t);
  virtual int digitalRead(uint8_t);
};

class DigitalIOWrapper : public AbstractDigitalIOWrapper {
public:
  void pinMode(uint8_t, uint8_t);
  void digitalWrite(uint8_t, uint8_t);
  int digitalRead(uint8_t);
};

#endif
