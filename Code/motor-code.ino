// Motor A control pins
const int PWMA = 20;  // Speed control
const int AIN1 = 17;  // Direction control 1
const int AIN2 = 16;  // Direction control 2
const int STBY = 21;  // Standby pin

// Motor speeds (0-255)
const int MOTOR_SPEED = 200;  // You can adjust this value

void setup() {
  // Set all the motor control pins as outputs
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(115200);
  
  // Take the motor driver out of standby
  digitalWrite(STBY, HIGH);
}

void loop() {
  // Move motor forward
  Serial.println("Moving Forward");
  moveMotor(MOTOR_SPEED);
  delay(2000);  // Run for 2 seconds
  
  // Stop motor
  Serial.println("Stopping");
  stopMotor();
  delay(1000);  // Wait for 1 second
  
  // Move motor backward
  Serial.println("Moving Backward");
  moveMotor(-MOTOR_SPEED);
  delay(2000);  // Run for 2 seconds
  
  // Stop motor
  Serial.println("Stopping");
  stopMotor();
  delay(1000);  // Wait for 1 second
}

void moveMotor(int speed) {
  if (speed >= 0) {
    // Forward
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else {
    // Backward
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    speed = -speed;  // Make speed positive
  }
  
  // Set the speed (0-255)
  analogWrite(PWMA, speed);
}

void stopMotor() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
}