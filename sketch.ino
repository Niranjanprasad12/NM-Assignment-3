// Define pins for the ultrasonic sensor
const int trigPin = 2;
const int echoPin = 3;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the trigger pin as output and the echo pin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Wait for the sensor to settle
  delay(100);
}

void loop() {
  // Send a trigger pulse to the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse duration and calculate the distance
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance < 100) {
    Serial.println("The distance is reduced below 100 cms uploading it to the cloud");
  }

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for a short period before taking another measurement
  delay(500);
}
