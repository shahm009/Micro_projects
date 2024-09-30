const int trigPin = 2;   // Shared Trig pin
const int echoPins[6] = {3, 4, 5, 6, 7, 8};  // Separate Echo pins for each sensor
long duration;          // Variable to store echo duration
int distance[6];        // Array to store distances from sensors
const int ledPin = 12;  // LED pin

void setup() {
  Serial.begin(9600);                    // Start Serial communication
  pinMode(trigPin, OUTPUT);               // Set the Trig pin as OUTPUT
  pinMode(ledPin, OUTPUT);                // Set LED pin as OUTPUT
  for (int i = 0; i < 6; i++) {
    pinMode(echoPins[i], INPUT);          // Set each Echo pin as INPUT
  }
}

void loop() {
  bool objectDetected = false;  // Track if any sensor detects an object within 10 cm

  for (int i = 0; i < 6; i++) {
    // Pulse each sensor individually
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read the echo pin for the current sensor
    duration = pulseIn(echoPins[i], HIGH);

    // If no echo received, mark it as no echo (-1)
    if (duration == 0) {
      distance[i] = -1;  // No echo
    } else {
      // Calculate distance in cm (duration * speed of sound (0.034) / 2)
      distance[i] = duration * 0.034 / 2;
    }

    // Check if object is within 10 cm and set flag
    if (distance[i] <= 10 && distance[i] != -1) {
      objectDetected = true;  // Object detected within 10 cm
    }
    
    // Send sensor distance to Processing via Serial
    if (i < 5) {
      Serial.print(distance[i]);   // Send value followed by a comma
      Serial.print(",");
    } else {
      Serial.println(distance[i]); // For the last sensor, send value followed by a newline
    }
  }

  // Control the LED based on object detection
  if (objectDetected) {
    digitalWrite(ledPin, HIGH);  // Turn LED on if any sensor detects an object within 10 cm
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED off if no objects are detected
  }

  // Small delay to prevent sensor interference
  delay(10);
}
