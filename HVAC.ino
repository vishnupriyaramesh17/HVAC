#include <DHT.h>

/* ---------- DHT CONFIG ---------- */
#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

/* ---------- FAN PWM CONFIG ---------- */
#define FAN_PIN 25
#define PWM_CHANNEL 0
#define PWM_FREQ 5000      // ✅ FIXED: suitable for 5V DC fan
#define PWM_RES 8          // 0–255

/* ---------- TEMP THRESHOLDS ---------- */
#define TEMP_MIN 25.0
#define TEMP_MAX 29.0

int getFanSpeed(float temp) {
  if (temp < TEMP_MIN) return 0;        // fan OFF
  if (temp > TEMP_MAX) return 255;      // full speed
  return map(temp, TEMP_MIN, TEMP_MAX, 80, 255);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(FAN_PIN, PWM_CHANNEL);

  Serial.println("Smart HVAC – 1 Fan (5V) System Started");
}

void loop() {
  delay(2000);

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("DHT read failed!");
    return;
  }

  int pwmValue = getFanSpeed(temp);
  ledcWrite(PWM_CHANNEL, pwmValue);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | Fan PWM: ");
  Serial.println(pwmValue);
}
