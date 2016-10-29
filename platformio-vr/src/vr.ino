#include <stdint.h>
#include <SPI.h>
#include <RH_ASK.h>
#include "UnitPeripheralsContainer.h"
#include "CommandHandlerFactory.h"
#include "RadioCommandFactory.h"

#define SERIAL_BAUDRATE 9600
#define RADIO_BAUDRATE 2000
#define PIN_RX 11
#define PIN_TX 12
#define BUFFER_SIZE 8

RH_ASK radio = RH_ASK(RADIO_BAUDRATE, PIN_RX, PIN_TX);
uint8_t buffer[BUFFER_SIZE];
uint8_t size = sizeof(buffer);

Motor motor = Motor();
UnitPeripheralsContainer container = UnitPeripheralsContainer();
RadioCommandFactory commandFactory = RadioCommandFactory();
CommandHandlerFactory handlerFactory = CommandHandlerFactory(&container);

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(PIN_RX, INPUT);
  pinMode(PIN_TX, OUTPUT);
  radio.init();
  radio.setModeRx();

  container.setMotor(&motor);
}

void loop() {
  if (radio.available()) {
    if (radio.recv(buffer, &size)) {
      Command* command = commandFactory.createCommand(buffer, size);
      uint8_t* d = command->getData();
      Serial.println(*d, BIN);
      CommandHandler* handler = handlerFactory.createCommandHandler(command);
      handler->process(command);
    }
  }
}
