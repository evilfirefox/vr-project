#include "DigitalIOWrapper.h"

void DigitalIOWrapper::pinMode(uint8_t pin, uint8_t mode) {
  pinMode(pin, mode);
}

void DigitalIOWrapper::digitalWrite(uint8_t pin, uint8_t value) {
  digitalWrite(pin, value);
}

int DigitalIOWrapper::digitalRead(uint8_t pin) {
  return digitalRead(pin);
}
