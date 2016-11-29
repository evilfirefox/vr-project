#ifndef COMMAND_TEST_SUITE_H
#define COMMAND_TEST_SUITE_H

#define TEST_COMMAND_TYPE 33
#define TEST_DATA_SIZE 5

#include <cxxtest/TestSuite.h>
#include "Command.h"

class CommandTestSuite : public CxxTest::TestSuite {
public:
  void testCommandNoParam() {
    Command* c = new Command();

    TS_ASSERT_EQUALS(c->getSize(), 0);
  }

  void testCommandCommandType() {
    Command* c = new Command(TEST_COMMAND_TYPE);

    TS_ASSERT_EQUALS(c->getCommandType(), TEST_COMMAND_TYPE);
  }

  void testCommandComplete() {
    uint8_t testData[]  = {1, 2, 3, 4, 5};
    Command* c = new Command(TEST_COMMAND_TYPE, TEST_DATA_SIZE, testData);

    TS_ASSERT_EQUALS(c->getCommandType(), TEST_COMMAND_TYPE);
    TS_ASSERT_EQUALS(c->getSize(), TEST_DATA_SIZE);
    TS_ASSERT_SAME_DATA(c->getData(), testData, TEST_DATA_SIZE);
  }
};

#endif
