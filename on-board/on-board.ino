#define LOG_BAUDRATE 9600

#define PIN_ENGINE_SWITCH 8
#define PIN_ENGINE_POSITIVE 9
#define PIN_ENGINE_NEGATIVE 10
#define PIN_GEARBOX_SWITCH 11

#define ENGINE_FORWARD HIGH
#define ENGINE_REVERSE LOW
#define ENGINE_RUN 1
#define ENGINE_STOP 0

void setup() {
  configureLogger();

}

void loop() {
}

void controlEngine(uint8_t status, uint8_t direction) {
  digitalWrite(PIN_ENGINE_SWITCH, (status ? HIGH : LOW));
  digitalWrite(PIN_ENGINE_POSITIVE, direction);
  digitalWrite(PIN_ENGINE_NEGATIVE, !direction); 
}

void configureLogger() {
  Serial.begin(LOG_BAUDRATE);
}

void logMessage(uint8_t severity, char *message) {
  Serial.print(severity);
  Serial.print(" : ");
  Serial.println(message);
}

