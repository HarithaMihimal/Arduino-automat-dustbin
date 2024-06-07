
// Haritha Mihimal Wilwala Arachchi.

#define trigerPin 2    // Define the trigger pin for the ultrasonic sensor
#define echoPin 3      // Define the echo pin for the ultrasonic sensor
#include <Servo.h>     // Include the Servo library

Servo Servo_H;         // Create a Servo object

void setup() {
  Serial.begin(9600);            // Initialize serial communication at 9600 bits per second
  pinMode(trigerPin, OUTPUT);    // Set the trigger pin as an output
  pinMode(echoPin, INPUT);       // Set the echo pin as an input
  Servo_H.attach(13);            // Attach the Servo motor to pin 13
}

void loop() {
  long duration, distance;       // Variables to store the duration and distance
  
  // Send a 10 microsecond pulse to trigger the ultrasonic sensor
  digitalWrite(trigerPin, LOW);  
  delayMicroseconds(2);          
  digitalWrite(trigerPin, HIGH); 
  delayMicroseconds(10);         
  digitalWrite(trigerPin, LOW);  

  // Read the echo pin and calculate the distance based on the duration
  duration = pulseIn(echoPin, HIGH);          
  distance = (duration / 2) / 29.1;  // Convert duration to distance in cm
  
  // If the distance is less than 30 cm, set the servo to 120 degrees
  if (distance < 30) {
    Servo_H.write(120);  // Turn the servo to 120 degrees
  } 
  // If the distance is 30 cm or more, set the servo to 0 degrees
  else {
    Servo_H.write(0);    // Turn the servo back to 0 degrees
  }
  
  delay(600);  // Wait for 600 milliseconds before taking another reading
}
