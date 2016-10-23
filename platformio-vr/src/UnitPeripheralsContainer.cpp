#include "UnitPeripheralsContainer.h"

UnitPeripheralsContainer::UnitPeripheralsContainer() {
}

UnitPeripheralsContainer::~UnitPeripheralsContainer() {
}

UnitPeripheralsContainer* UnitPeripheralsContainer::setMotor(Motor * motor) {
  this->motor = motor;
  return this;
}

Motor* UnitPeripheralsContainer::getMotor() {
  return this->motor;
}
