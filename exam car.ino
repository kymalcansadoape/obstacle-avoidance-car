int centerIR;
int leftIR;
int rightIR;

int leftFlag;
int centerFlag;
int rightFlag;

int leftWheelForward8 = 8;
int rightWheelForward11 = 11;
int leftWheelBackward9 = 9;
int rightWheelBackward10 = 10;

int wheelSpeed = 80;

//Declare all the functions being used here:
void deviateRight();
void deviateLeft();
void forward();
void reverse();

void setup() {
  pinMode(leftWheelForward8, OUTPUT);
  pinMode(leftWheelBackward9, OUTPUT);
  pinMode(rightWheelBackward10, OUTPUT);
  pinMode(rightWheelForward11, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  centerIR = analogRead(A0);
  leftIR = analogRead(A1);
  rightIR = analogRead(A2);

  if (leftIR < 200) {
    leftFlag = 1;
  } else {
    leftFlag = 0;
  }

  if (rightIR < 200) {
    rightFlag = 1;
  } else {
    rightFlag = 0;
  }

  if (centerIR < 200) {
    centerFlag = 1;
  } else {
    centerFlag = 0;
  }

  if ((leftFlag == 1) || (rightFlag == 1) || (centerFlag == 1)) {

    if (centerFlag == 1) {

      if (leftFlag == 1) {
        deviateRight();
      } 
      else if (rightFlag == 1) {
        deviateLeft();
      } else {
        deviateLeft();
      }

    } 
    else if (leftFlag == 1) {
      deviateRight();
    } 
    else if (rightFlag == 1) {
      deviateLeft();
    } 
    else {
      deviateLeft();
    }
  } 
  else {
    forward();
  }
}

//Function definitions go here:
void reverse() {
  Serial.println("Backing up");
  digitalWrite(leftWheelBackward9, LOW);
  analogWrite(leftWheelForward8, wheelSpeed);
  analogWrite(rightWheelForward11, wheelSpeed);
  digitalWrite(rightWheelBackward10, LOW);
  delay(1000);
}

void deviateRight() {
  Serial.println("Right");
  reverse();
  digitalWrite(leftWheelForward8, LOW);
  digitalWrite(leftWheelBackward9, LOW);
  digitalWrite(rightWheelForward11, LOW);
  analogWrite(rightWheelBackward10, 350);
  delay(300);
}

void deviateLeft() {
  Serial.println("Left");
  reverse();
  analogWrite(leftWheelBackward9, 350);
  digitalWrite(leftWheelForward8, LOW);
  digitalWrite(rightWheelForward11, LOW);
  digitalWrite(rightWheelBackward10, LOW);
  delay(300);
}

void forward() {
  Serial.println("Forward");
  analogWrite(leftWheelBackward9, wheelSpeed);
  digitalWrite(leftWheelForward8, LOW);
  digitalWrite(rightWheelForward11, LOW);
  analogWrite(rightWheelBackward10, wheelSpeed);
}