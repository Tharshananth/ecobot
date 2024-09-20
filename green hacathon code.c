int MQ2pin = A0;   // Pin for MQ2 gas sensor
int tempPin = A1;  // Pin for Temperature sensor

void setup() {
  // Setup Serial Monitor
  Serial.begin(9600);

  // Setup pins for Motor 1
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  // Setup pins for Motor 2
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  // Setup pins for Motor 3
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // Read gas sensor value
  float sensorValue = getsensorValue(MQ2pin);  // Get the sensor value
  // Print gas sensor value
  Serial.print("Gas Sensor Value: ");
  Serial.println(sensorValue);

  // Check for smoke
  if(sensorValue >= 470) {
    Serial.println("SMOKE DETECTED!");
  }

  // CLOCKWISE for all motors (running indefinitely)
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);

  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);

  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);

  // Read and print temperature sensor value
  int celsius = getTempValue(tempPin); // Get temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" C");

  delay(1000);  // Wait 1 second before the next sensor readings
}

// Function to get gas sensor value
float getsensorValue(int pin) {
  return analogRead(pin);  // Return the analog value from the sensor
}

// Function to get temperature sensor value
int getTempValue(int pin) {
  // Read the temperature sensor value and map it to Celsius
  return map(((analogRead(pin) - 20) * 3.04), 0, 1023, -40, 125);
}
