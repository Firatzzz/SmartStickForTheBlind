#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 4
#define MIN_DISTANCE_VERY_CLOSE 10 // Jarak sangat dekat (misalnya 10 cm)
#define MIN_DISTANCE_CLOSE 30      // Jarak dekat (misalnya 30 cm)
#define MIN_DISTANCE_FAR 60        // Jarak jauh (misalnya 60 cm)

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  
  if (distance < MIN_DISTANCE_VERY_CLOSE) {
    tone(BUZZER_PIN, 4000); // Bunyi buzzer sangat cepat
  } else if (distance < MIN_DISTANCE_CLOSE) {
    tone(BUZZER_PIN, 2000); // Bunyi buzzer sedang
  } else if (distance < MIN_DISTANCE_FAR) {
    tone(BUZZER_PIN, 1000); // Bunyi buzzer pelan
  } else {
    noTone(BUZZER_PIN); // Matikan buzzer
  }
  
  delay(100);
}
