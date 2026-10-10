#include <Servo.h>
#include <NewPing.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200
#define LEFT_MOTOR 3
#define RIGHT_MOTOR 4

Servo servo;
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  servo.attach(5);              // Servo on pin 5
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  servo.write(90);              // Center servo
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();
  if (distance > 0 && distance < 20) {   // Obstacle detected
    stopMotors();
    servo.write(0);                      // Turn sensor left
    delay(1000);
    int leftDistance = sonar.ping_cm();
    servo.write(180);                    // Turn sensor right
    delay(1000);
    int rightDistance = sonar.ping_cm();
    servo.write(90);                     // Reset to center
    delay(1000);
    if (leftDistance > rightDistance) {
      turnLeft();
    } else {
      turnRight();
    }
  } else {
    moveForward();
  }
  delay(50);
}

void moveForward() {
  digitalWrite(LEFT_MOTOR, HIGH);
  digitalWrite(RIGHT_MOTOR, HIGH);
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR, LOW);
  digitalWrite(RIGHT_MOTOR, LOW);
}

void turnLeft() {
  stopMotors();
  digitalWrite(LEFT_MOTOR, LOW);
  digitalWrite(RIGHT_MOTOR, HIGH);
  delay(1000);                  // Adjust time for a 90-degree turn
  stopMotors();
}

void turnRight() {
  stopMotors();
  digitalWrite(LEFT_MOTOR, HIGH);
  digitalWrite(RIGHT_MOTOR, LOW);
  delay(1000);                  // Adjust time for a 90-degree turn
  stopMotors();
}
