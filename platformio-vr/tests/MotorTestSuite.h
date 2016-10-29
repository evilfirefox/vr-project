#ifndef MOTOR_TEST_SUITE_H
#define MOTOR_TEST_SUITE_H

#include <cxxtest/TestSuite.h>
#include <cxxtest/Mock.h>
#include "Motor.h"

CXXTEST_MOCK_GLOBAL(void, digitalWrite, )

class MotorTestSuite : public CxxTest::TestSuite {
public:
  void testStart() {
    DigitalIOWrapperMock mock = DigitalIOWrapperMock();
    Motor motor = Motor(&mock);
    motor.start(MOTOR_DIRECTION_FWD);
  }

  void testStop() {

  }
};

#endif
