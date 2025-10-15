/*
 * SMART AIR QUALITY MONITOR - FULL ARDUINO CODE
 * Developed for Tinkercad/Arduino Uno, MQ135 sensor, LCD, LEDs, buzzer and button
 */

#include <LiquidCrystal.h>

// Pin Definitions
#define MQ135_PIN    A0          // MQ135 sensor analog input
#define BUTTON_PIN   2           // Manual reading button
#define BUZZER_PIN   3           // Buzzer
#define LED_GREEN    4           // Green LED
#define LED_BLUE   5           // BLUE LED
#define LED_RED      6           // Red LED

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Global Variables
int gasValue = 0;                // Raw sensor value
float airQualityPPM = 0.0;       // Converted PPM value
int buttonState = HIGH;
int lastButtonState = HIGH;
unsigned long lastReadTime = 0;
unsigned long alertStartTime = 0;
bool alertActive = false;

// Air Quality Thresholds
#define GOOD_LIMIT      500
#define MODERATE_LIMIT  650
#define POOR_LIMIT      800

void setup() {
  Serial.begin(9600);
  pinMode(MQ135_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  lcd.begin(16, 2);

  // Startup Message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality");
  lcd.setCursor(0, 1);
  lcd.print("Monitor v1.0");
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  delay(2000);

  // Sensor Warm-up
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor Warming");
  lcd.setCursor(0, 1);
  lcd.print("Please wait...");
  delay(5000); // 5 seconds for Tinkercad
  Serial.println("System Initialized");
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  // Manual Reading (button press detected)
  if (buttonState == LOW && lastButtonState == HIGH) {
    manualCheck();
    delay(300); // Debounce
  }

  // Automatic reading every 3 seconds
  if (millis() - lastReadTime >= 3000) {
    airQualityCheck();
    lastReadTime = millis();
  }

  manageAlerts();
  lastButtonState = buttonState;
  delay(50);
}

void airQualityCheck() {
  gasValue = analogRead(MQ135_PIN);
  airQualityPPM = mapGasToPPM(gasValue);
  updateLCD();
  updateLEDs();
  evaluateAlerts();
  logData();
}

void manualCheck() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Manual Check");
  lcd.setCursor(0, 1);
  lcd.print("Reading...");
  delay(1000);
  airQualityCheck();
  Serial.println("*** MANUAL READING TRIGGERED ***");
}

float mapGasToPPM(int rawValue) {
  float ppm = map(rawValue, 0, 1023, 50, 5000); // Simulation
  if (ppm < 50) ppm = 50;
  if (ppm > 5000) ppm = 5000;
  return ppm;
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PPM: ");
  lcd.print((int)airQualityPPM);
  lcd.setCursor(0, 1);
  lcd.print(getStatus());
}

String getStatus() {
  if (airQualityPPM < GOOD_LIMIT) {
    return "Status: GOOD";
  } else if (airQualityPPM < MODERATE_LIMIT) {
    return "Status: MODERATE";
  } else if (airQualityPPM < POOR_LIMIT) {
    return "Status: POOR";
  } else {
    return "Status: DANGER!";
  }
}

void updateLEDs() {
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
  
  if (airQualityPPM < GOOD_LIMIT) {
    digitalWrite(LED_GREEN, HIGH);
  } else if (airQualityPPM < MODERATE_LIMIT) {
    digitalWrite(LED_BLUE, HIGH);
  } else {
    digitalWrite(LED_RED, HIGH);
  }
}

void evaluateAlerts() {
  if (airQualityPPM >= POOR_LIMIT) {
    if (!alertActive) {
      alertActive = true;
      alertStartTime = millis();
      Serial.println("!!! ALERT: DANGEROUS AIR QUALITY !!!");
    }
  } else {
    alertActive = false;
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void manageAlerts() {
  if (alertActive) {
    unsigned long currentTime = millis();
    if (airQualityPPM >= POOR_LIMIT * 1.5) {
      digitalWrite(BUZZER_PIN, HIGH);
    } else if (airQualityPPM >= POOR_LIMIT) {
      if ((currentTime - alertStartTime) % 1000 < 500) {
        digitalWrite(BUZZER_PIN, HIGH);
      } else {
        digitalWrite(BUZZER_PIN, LOW);
      }
    }
  }
}

void logData() {
  Serial.print("Raw: ");
  Serial.print(gasValue);
  Serial.print(" | PPM: ");
  Serial.print((int)airQualityPPM);
  Serial.print(" | Status: ");
  Serial.print(getStatus());
  if (alertActive) {
    Serial.print(" | ALERT ACTIVE");
  }
  Serial.println();
}
