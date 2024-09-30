//Run this code in Procesing IDE


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int[] distances = new int[6];  // Store distances from sensors
int maxDistance = 300;  // Max distance range of the sensors
float radarAngle = PI;  // Starting angle for half-circle radar sweep (PI for 180 degrees)
color[] colors = {color(255, 0, 0), color(0, 255, 0)};  // Red for close, green for far

void setup() {
  size(600, 600);  // Window size
  myPort = new Serial(this, "COM5", 9600);  // Set the correct COM port for your Arduino
  myPort.bufferUntil('\n');  // Read serial data until newline character
  smooth();  // Enable anti-aliasing for smoother graphics
}

void draw() {
  background(0);  // Black background for better contrast
  translate(width / 2, height);  // Move the origin to the bottom center of the screen
  
  // Draw half-circle range arcs for visual reference
  stroke(100);
  noFill();
  arc(0, 0, 600, 600, PI, TWO_PI);  // Outer range (300 cm)
  arc(0, 0, 400, 400, PI, TWO_PI);  // Mid range (200 cm)
  arc(0, 0, 200, 200, PI, TWO_PI);  // Close range (100 cm)
  
  // Radar sweep line
  stroke(0, 255, 0, 150);  // Green radar line with transparency
  strokeWeight(2);
  line(0, 0, 300 * cos(radarAngle), 300 * sin(radarAngle));  // Radar sweep line

  // Show sensor data as blips on the half-circle radar
  for (int i = 0; i < 6; i++) {
    float angle = map(i, 0, 5, PI, TWO_PI);  // Map the sensor positions along a half-circle (180 degrees)
    
    // Only draw detected points if valid
    if (distances[i] != -1) {
      float r = map(distances[i], 0, maxDistance, 0, 300);  // Scale the distance to fit the radar size
      color blipColor = lerpColor(colors[0], colors[1], map(distances[i], 0, maxDistance, 0, 1));  // Gradient from red to green
      fill(blipColor, 200);  // Semi-transparent blips
      noStroke();
      
      // Draw the object blip on the half-circle radar
      float x = r * cos(angle);
      float y = r * sin(angle);
      ellipse(x, y, 10 + (r / 30), 10 + (r / 30));  // Size increases with distance for better visibility
    }
  }
  
  // Sweep the radar line across the half-circle
  radarAngle += 0.02;  // Adjust speed of the radar sweep
  if (radarAngle > TWO_PI) {
    radarAngle = PI;  // Reset the radar sweep after completing the half-circle
  }
  
  // Delay to control the speed of the radar sweep
  delay(20);
}

void serialEvent(Serial myPort) {
  String data = myPort.readStringUntil('\n');
  if (data != null) {
    data = trim(data);
    String[] values = split(data, ',');
    if (values.length == 6) {
      for (int i = 0; i < values.length; i++) {
        distances[i] = int(values[i]);
      }
    }
  }
}
