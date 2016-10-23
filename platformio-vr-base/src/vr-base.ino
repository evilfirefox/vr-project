#include <stdint.h>
#include <RH_ASK.h>

#define SERIAL_BAUDRATE 9600
#define RADIO_BAUDRATE 2000
#define PIN_RX 11
#define PIN_TX 12
#define BUFFER_SIZE 8

RH_ASK radio = RH_ASK(RADIO_BAUDRATE, PIN_RX, PIN_TX);
uint8_t data[BUFFER_SIZE] = {1,2,3,4,5,'A','B','C'};
uint8_t size = sizeof(data);
bool status = false;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(PIN_RX, INPUT);
  pinMode(PIN_TX, OUTPUT);
  radio.init();
}

void loop() {
  status = radio.send(data, size);
  Serial.println(status);
  delay(1000);
}
