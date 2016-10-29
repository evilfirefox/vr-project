#include <stdint.h>
#include <RH_ASK.h>

#define SERIAL_BAUDRATE 9600
#define RADIO_BAUDRATE 9600
#define PIN_RX 11
#define PIN_TX 12
#define BUFFER_SIZE 8

RH_ASK radio = RH_ASK(RADIO_BAUDRATE, PIN_RX, PIN_TX);
uint8_t startCommand[BUFFER_SIZE] = {1, 1, 0, 0, 0, 0, 0, 0};
uint8_t stopCommand[BUFFER_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t reverseCommand[BUFFER_SIZE] = {1, 0, 0, 0, 0, 0, 0, 0};
uint8_t size = sizeof(startCommand);
bool status = false;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(PIN_RX, INPUT);
  pinMode(PIN_TX, OUTPUT);
  radio.init();
}

void loop() {
  sendCommand(startCommand);
  sendCommand(stopCommand);
  sendCommand(reverseCommand);
  sendCommand(stopCommand);
}

void sendCommand(uint8_t* command) {
  status = radio.send(command, size);
  Serial.print("sent with status: ");
  Serial.println(status);
  delay(1000);
}
