#include <DHT.h>

/* -------- DHT SETTINGS -------- */


/* -------- DHT SETTINGS -------- */
#define DHTPIN 13   // D7 - safe and free
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

/* -------- L298N PINS -------- */
#define ENA 5           // Was D1
#define IN1 4           // Was D2
#define IN2 0           // Was D3

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Initialize motor state (Forward)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Start with fan off

  Serial.println("Smart HVAC System Started");
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read temperature!");
    delay(2000);
    return;
  }

  int speed;

  /* --- Improved Speed Logic --- */
  if (temp < 22) {
    speed = 0;       // Turn OFF if it's already cool
  } 
  else if (temp < 26) {
    speed = 550;     // Low (Adjusted higher so the motor actually spins)
  } 
  else if (temp < 30) {
    speed = 800;     // Medium
  } 
  else {
    speed = 1023;    // Full Power
  }

  analogWrite(ENA, speed);

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("°C | PWM Duty: ");
  Serial.println(speed);

  delay(2000); // Wait 2 seconds between readings
}
