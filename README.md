# Autonomous Obstacle Avoidance Vehicle

An Arduino-based robotic car that drives forward, detects obstacles with an ultrasonic sensor, scans left and right using a servo, and turns toward the clearer path on its own.

Built as a team project (group of 8) for the Engineering Physics course at VIT Chennai.

## How it works
1. The car moves forward while the HC-SR04 ultrasonic sensor keeps measuring distance.
2. If an obstacle is closer than 20 cm, the car stops.
3. The servo turns the sensor to the left (0°), then to the right (180°), and reads the distance each time.
4. The sensor returns to the centre. The car turns toward the side with more free space and moves forward again.

## Components
- Arduino Uno
- HC-SR04 ultrasonic sensor
- Servo motor
- Motor driver and 4 DC motors with chassis
- Battery and connecting wires

## Pin connections
| Part | Arduino pin |
|---|---|
| Ultrasonic TRIG | 9 |
| Ultrasonic ECHO | 10 |
| Servo signal | 5 |
| Left motor | 3 |
| Right motor | 4 |

## Libraries
- `Servo` (built into the Arduino IDE)
- `NewPing` (install from Library Manager)

## Run it
1. Install the Arduino IDE and the NewPing library.
2. Open `obstacle-avoidance-vehicle.ino`, select your board, and upload.

## Possible improvements
- Reverse when both sides are blocked
- PWM speed control
- Handle "no echo" readings (0 cm) as open space
