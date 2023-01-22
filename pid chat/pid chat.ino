#include <PID_v1.h>

// IR sensor pins
const int irSensor1 = A0;
const int irSensor2 = A1;
const int irSensor3 = A2;
const int irSensor4 = A3;
const int irSensor5 = A4;

// Motor pins
const int motor1 = 9;
const int motor2 = 10;

// PID variables
double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, 2, 5, 0.1, DIRECT);

void setup() {
// Set IR sensor pins as inputs
pinMode(irSensor1, INPUT);
pinMode(irSensor2, INPUT);
pinMode(irSensor3, INPUT);
pinMode(irSensor4, INPUT);
pinMode(irSensor5, INPUT);

// Set motor pins as outputs
pinMode(motor1, OUTPUT);
pinMode(motor2, OUTPUT);

// Set PID parameters
myPID.SetMode(AUTOMATIC);
myPID.SetSampleTime(10);
myPID.SetOutputLimits(-255, 255);

// Start PID
myPID.SetTunings(2, 5, 0.1);
myPID.SetControllerDirection(DIRECT);
myPID.SetSampleTime(10);
}

void loop() {
// Read IR sensor values
int ir1 = analogRead(irSensor1);
int ir2 = analogRead(irSensor2);
int ir3 = analogRead(irSensor3);
int ir4 = analogRead(irSensor4);
int ir5 = analogRead(irSensor5);

// Calculate error
Input = (ir1 + ir2 + ir3 + ir4 + ir5) / 5;
Setpoint = 512;
myPID.Compute();

// Control motors
analogWrite(motor1, Output);
analogWrite(motor2, Output);
}