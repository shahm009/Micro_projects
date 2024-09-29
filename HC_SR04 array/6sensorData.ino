/*
This code is made for Ardunio Uno. Adjust pins accordingly For ESP or other boards.
*/
const int trigPin = 2;   // Shared Trig pin
const int echoPins[6] = {3, 4, 5, 6, 7, 8};  // Separate Echo pins for each sensor

long duration;
int distance[6];

void setup() {
  Serial.begin(9600);                    // Start Serial communication
  pinMode(trigPin, OUTPUT);              // Set the Trig pin as OUTPUT
  
  for (int i = 0; i < 6; i++) {
    pinMode(echoPins[i], INPUT);         // Set Echo pins as INPUT
  }
}

void loop() { 
  for (int i = 0; i < 6; i++) { // Loop through each sensor to read Echo pins
    // Send pulse from the shared Trig pin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
   
    duration = pulseIn(echoPins[i], HIGH);     // Read the Echo pin
   
    if (duration == 0) {   // Check if duration is valid
      distance[i] = -1;  // Set to -1 if no echo received
    } else {
      distance[i] = duration * 0.034 / 2;  // Calculate distance in cm
    }   
    // Small delay to prevent interference
    delay(50); // Adjust delay as necessary
  }
  
  Serial.print("Sensor Distances: "); // Print all distances in one line
  for (int i = 0; i < 6; i++) {
    if (distance[i] == -1) {
      Serial.print("No Echo "); // Indicate no echo received
    } else {
      Serial.print(distance[i]);
      Serial.print(" cm");
    } 
    if (i < 5) { // Avoid printing a comma after the last sensor
      Serial.print(", ");
    }
  }
  Serial.println(); // New line for next measurement
  delay(100); // Delay before starting next loop iteration
}
