const int trigPin = 18;
const int echoPin = 19;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance;

  // Send a 10 microsecond pulse to trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin and calculate the distance
  duration = pulseIn(echoPin, HIGH);

  // The ultra-sonic sensor measures time in microseconds.
  // We want the distance measurement in cm.
  // We need to conver the speed of sound to cm/microsecond.

  // Speed of sound is 343 m/s -> 34,300 cm/s
  // There are 1,000,000 microseconds in 1 second
  // 34,300cm/s / 1,000,000 microseconds/s = 0.0343 cm/microsecond

  // Divide final answer by 2 since the time measured is the time it takes
  // for the sound to hit the object and bounce back. We just want the
  // distance to the object, not the distance to the object and back.
  distance = (duration * 0.0343) / 2; 

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Wait half a second before next reading
}
