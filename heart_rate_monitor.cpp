#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
#include <BluetoothSerial.h>

MAX30105 particleSensor;
BluetoothSerial SerialBT;

long lastBeat = 0;
float beatsPerMinute = 0;
int beatAvg = 0;

void setup() {
  Serial.begin(115200);          // For debug if needed
  SerialBT.begin("ESP32-BPM-Logger");  // Appears on phone

  Wire.begin(21, 22);  // SDA = D21, SCL = D22

  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("MAX30102 not found. Check wiring.");
    while (1);
  }

  particleSensor.setup(); // Default settings
  particleSensor.setPulseAmplitudeRed(0x0A);   // Weak red
  particleSensor.setPulseAmplitudeGreen(0);    // Disable green

  // CSV Header
  SerialBT.println("Timestamp(ms),BPM");
  Serial.println("Timestamp(ms),BPM");
}

void loop() {
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue)) {
    long now = millis();
    long delta = now - lastBeat;
    lastBeat = now;

    beatsPerMinute = 60000.0 / delta;
    beatAvg = (beatAvg * 3 + beatsPerMinute) / 4;

    // Format: timestamp, bpm
    String line = String(now) + "," + String(beatAvg);

    SerialBT.println(line);     // Send to phone
    Serial.println(line);       // Also show on Serial Monitor
  }

  delay(20);
}
