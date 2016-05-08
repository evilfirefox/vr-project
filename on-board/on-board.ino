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
  configureEngine();
}

void loop() {
}

void configureEngine() {
  pinMode(PIN_ENGINE_SWITCH, OUTPUT);
  pinMode(PIN_ENGINE_POSITIVE, OUTPUT);
  pinMode(PIN_ENGINE_NEGATIVE, OUTPUT);
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

