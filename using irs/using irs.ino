// Constants for the IR sensor pins
const int IR_SENSOR_1 = A0;
const int IR_SENSOR_2 = A1;
const int IR_SENSOR_3 = A2;
const int IR_SENSOR_4 = A3;
const int IR_SENSOR_5 = A4;
#define LOW 1
#define HIGH 0

// Constants for the motor pins
const int LEFT_MOTOR_SPEED = 9;
const int LEFT_MOTOR_DIRECTION = 8;
const int RIGHT_MOTOR_SPEED = 10;
const int RIGHT_MOTOR_DIRECTION = 11;

void setup() {
  // Set all sensor pins to be input pins
  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);
  pinMode(IR_SENSOR_3, INPUT);
  pinMode(IR_SENSOR_4, INPUT);
  pinMode(IR_SENSOR_5, INPUT);

  // Set all motor pins to be output pins
  pinMode(LEFT_MOTOR_SPEED, OUTPUT);
  pinMode(LEFT_MOTOR_DIRECTION, OUTPUT);
  pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
  pinMode(RIGHT_MOTOR_DIRECTION, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the values of all the sensors
  int sensor1 = digitalRead(IR_SENSOR_1);
  int sensor2 = digitalRead(IR_SENSOR_2);
  int sensor3 = digitalRead(IR_SENSOR_3);
  int sensor4 = digitalRead(IR_SENSOR_4);
  int sensor5 = digitalRead(IR_SENSOR_5);


  // Determine the position of the line based on the sensor values
  if (sensor1 == LOW && sensor2 == LOW && sensor3 == HIGH && sensor4 == LOW && sensor5 == LOW) {
    // The line is in the middle
    moveForward();
  } else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW) {
    // The line is not visible
    stop();
  } else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 ==HIGH && sensor5 == HIGH) { turnRight();}
    else if (sensor1 == LOW && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == HIGH) {turnFastRight();}
    else if (sensor1 == HIGH && sensor2 == HIGH && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW) {turnLeft();}
    else if (sensor1 == HIGH && sensor2 == LOW && sensor3 == LOW && sensor4 == LOW && sensor5 == LOW) {  turnFastLeft();}





//end of loop
}

void moveForward() {
Serial.println("forward") ; 
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, 127);
  analogWrite(RIGHT_MOTOR_SPEED, 127);
}
void moveFastForward() {
Serial.println("forward") ; 
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, 255);
  analogWrite(RIGHT_MOTOR_SPEED, 255);
}

void stop() {
  Serial.println("stop") ; 
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  analogWrite(LEFT_MOTOR_SPEED, 0);
  analogWrite(RIGHT_MOTOR_SPEED, 0);
}

void turnLeft() {
  Serial.println("left") ; 
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  analogWrite(LEFT_MOTOR_SPEED, 127);
  analogWrite(RIGHT_MOTOR_SPEED, 127);
}
void turnFastLeft() {
  Serial.println("Fastleft") ; 
  digitalWrite(LEFT_MOTOR_DIRECTION, HIGH);
  digitalWrite(RIGHT_MOTOR_DIRECTION, LOW);
  analogWrite(LEFT_MOTOR_SPEED, 255);
  analogWrite(RIGHT_MOTOR_SPEED, 255);
}
void turnRight() {
  Serial.println("right") ; 
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, 127);
  analogWrite(RIGHT_MOTOR_SPEED, 127);
}
void turnFastRight() {
  Serial.println("Fastright") ; 
  digitalWrite(LEFT_MOTOR_DIRECTION, LOW);
  digitalWrite(RIGHT_MOTOR_DIRECTION, HIGH);
  analogWrite(LEFT_MOTOR_SPEED, 255);
  analogWrite(RIGHT_MOTOR_SPEED, 255);
}

 
