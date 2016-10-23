#ifndef UNIT_PERIPHERALS_CONTAINER_H
#define UNIT_PERIPHERALS_CONTAINER_H

#include "Motor.h"

class UnitPeripheralsContainer {
protected:
  Motor* motor;

public:
  UnitPeripheralsContainer();
  ~UnitPeripheralsContainer();
  UnitPeripheralsContainer* setMotor(Motor*);
  Motor* getMotor();
};

#endif
