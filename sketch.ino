const int SENSOR_PIN = 34;   // potentiometer (stand-in for MQ-6)
const int BUZZER     = 25;
const int RED_LED    = 26;   // ALERT
const int AMBER_LED  = 27;   // WARN
const int GREEN_LED  = 14;   // OK

const int WARN_LEVEL   = 2000;  // placeholder threshold
const int ALERT_LEVEL  = 3000;  // placeholder threshold

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(AMBER_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  int reading = analogRead(SENSOR_PIN);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(AMBER_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  if (reading >= ALERT_LEVEL) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    Serial.println("ALERT " + String(reading));
  } else if (reading >= WARN_LEVEL) {
    digitalWrite(AMBER_LED, HIGH);
    Serial.println("WARN " + String(reading));
  } else {
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("OK " + String(reading));
  }

  delay(500);
}
