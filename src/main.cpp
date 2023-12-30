#include <Arduino.h>

#define ON HIGH
#define OFF LOW

const int FORWARD = 0;
const int REVERSE = 1;

// Arduinao (Output) Digital PWM Pins to Motor Driver
const int MOTOR_FORWARD = 5;
const int MOTOR_REVERSE = 6;
const int MOTOR_SPEED = 3;

// Arduino Analog Input Pins from IR proximity sensors
const uint8_t TERMINUS_1 = A0;
const uint8_t TERMINUS_2 = A1;
const uint8_t MID_STATION_1 = A2;

const uint8_t POTENTIOMETER = A2;

/** Cutoff for IR proximity filter */
const int SENSOR_THRESHOLD = 500;

int trainSpeed;
int trainDirection;

void setup()
{
  Serial.begin(9600);
  pinMode(MOTOR_FORWARD, OUTPUT);
  pinMode(MOTOR_REVERSE, OUTPUT);
  pinMode(MOTOR_SPEED, OUTPUT);
}

void loop()
{
  int terminus1 = analogRead(TERMINUS_1);
  int terminus2 = analogRead(TERMINUS_2);
  int midStation1 = analogRead(MID_STATION_1);
  int potValue = analogRead(POTENTIOMETER);

  trainSpeed = map(potValue, 0, 1023, 0, 255);
  analogWrite(MOTOR_SPEED, trainSpeed);
  Serial.println(trainDirection);
  Serial.println(trainSpeed);
  delay(200);

  if (terminus1 < SENSOR_THRESHOLD)
  {
    digitalWrite(MOTOR_FORWARD, OFF);
    digitalWrite(MOTOR_REVERSE, OFF);
    trainDirection = FORWARD;
    delay(5000);
    digitalWrite(MOTOR_FORWARD, ON);
    digitalWrite(MOTOR_REVERSE, OFF);

    delay(1500);
  }
  if (terminus2 < SENSOR_THRESHOLD)
  {
    digitalWrite(MOTOR_FORWARD, OFF);
    digitalWrite(MOTOR_REVERSE, OFF);
    trainDirection = REVERSE;
    delay(5000);
    digitalWrite(MOTOR_FORWARD, OFF);
    digitalWrite(MOTOR_REVERSE, ON);

    delay(1500);
  }

  if ((midStation1 < SENSOR_THRESHOLD) && (trainDirection == REVERSE))
  {
    digitalWrite(MOTOR_FORWARD, OFF);
    digitalWrite(MOTOR_REVERSE, OFF);
    delay(5000);
    digitalWrite(MOTOR_FORWARD, OFF);
    digitalWrite(MOTOR_REVERSE, ON);
    delay(1500);
  }
  if ((midStation1 < SENSOR_THRESHOLD) && (trainDirection == FORWARD))
  {
    digitalWrite(MOTOR_FORWARD, OFF);
    digitalWrite(MOTOR_REVERSE, OFF);
    delay(5000);
    digitalWrite(MOTOR_FORWARD, ON);
    digitalWrite(MOTOR_REVERSE, OFF);
    delay(1500);
  }
}
