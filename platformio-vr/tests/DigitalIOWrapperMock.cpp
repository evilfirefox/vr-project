#include "DigitalIOWrapper.h"

class DigitalIOWrapperMock : public AbstractDigitalIOWrapper {
public:
  void pinMode(uint8_t, uint8_t);
  void digitalWrite(uint8_t, uint8_t);
  int digitalRead(uint8_t);
};

void DigitalIOWrapperMock::digitalWrite(uint8_t pin, uint8_t value) {

}
