#include <SoftwareSerial.h>;
SoftwareSerial BT(2, 3); 

# define leftOne 7
# define leftTwo 8
# define rightOne 9
# define rightTwo 10

#define leftSpeed 5
#define rightSpeed 6


void setup() {

  // sets up pins
  pinMode(leftOne, OUTPUT);
  pinMode(leftTwo, OUTPUT);
  pinMode(rightOne, OUTPUT);
  pinMode(rightTwo, OUTPUT);
  pinMode(leftSpeed, OUTPUT);
  pinMode(rightSpeed, OUTPUT);

  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  Serial.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");

}

void loop() {


    if (BT.available())
  // if text arrived in from BT serial...
  {

    String input = readString();
    char first = input.charAt(0);

    if(input=="test"){
      test();
    }

    else if(input== "stop"){
      stop();
    }
    // for directions uses a 3 char string to show direction and speed
    else if(first=='F'){
      forward(getSpeed(input));
    }

    else if(first=='B'){
      backward(getSpeed(input));
    }

    else if(first=='A'){
      turnLeft(getSpeed(input));
    }

    else if(first=='D'){
      turnRight(getSpeed(input));
    }

    // for left and right motor gets a 4 char string with a F or R on the last defining direction
    else if(first=='L'){
      leftMotor(getSpeed(input),input);
    }

    else if(first=='R'){
      rightMotor(getSpeed(input),input);
    }
  }

}

String readString(){

    String a = ""; // stores incoming character from other device
    char newChar;
      //reads text
    a = "";

    //looks for escape character
    while (true) {
      newChar = BT.read();

      if(int(newChar) == -1){
        break;
      }
      a = a+newChar;  // Append each character to the string
    }
    
    Serial.print("Received: ");
    Serial.println(a);

    return a;
}

double getSpeed(String input){

  double char1 = int(input.charAt(1))- int('0');
  double char2 = int(input.charAt(2))- int('0');

  return (char1*10 + char2);
}

void setSpeed(double speed){
  int normalizedSpeed = (speed/100)*255;
  analogWrite(leftSpeed,normalizedSpeed);
  analogWrite(rightSpeed,normalizedSpeed);
}

void forward(double speed){
  digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,HIGH);
  digitalWrite(rightTwo,LOW);

  setSpeed(speed);

}


void backward(double speed){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,HIGH);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);

  setSpeed(speed);
}

void turnLeft(double speed){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,HIGH);
  digitalWrite(rightOne,HIGH);
  digitalWrite(rightTwo,LOW);

  setSpeed(speed);
}


void turnRight(double speed){
  digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);

  setSpeed(speed);
}

void leftMotor(double speed, String input){

  if(input.charAt(3) == 'F'){
      digitalWrite(leftOne,HIGH);
      digitalWrite(leftTwo,LOW);
  }

  else{
      digitalWrite(leftOne,LOW);
      digitalWrite(leftTwo,HIGH);
  }

  int normalizedSpeed = (speed/100)*255;
  analogWrite(leftSpeed,normalizedSpeed);
}

void rightMotor(double speed, String input){

    if(input.charAt(3) == 'F'){
      digitalWrite(rightOne,HIGH);
      digitalWrite(rightTwo,LOW);
  }

  else{
      digitalWrite(rightOne,LOW);
      digitalWrite(rightTwo,HIGH);
  }

  int normalizedSpeed = (speed/100)*255;
  analogWrite(rightSpeed,normalizedSpeed);
}

void stop(){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,LOW);

  setSpeed(0);

}

//PWM of every motor
void test(){
  forward(0);
  goThroughSpeeds();

  backward(0);
  goThroughSpeeds();

  turnLeft(0);
  goThroughSpeeds();

  turnRight(0);
  goThroughSpeeds();

  stop();
}

//mainly for test methods
void goThroughSpeeds(){
  for (int i=0; i<100; i++){
    setSpeed(i);
    delay(50);
  }
}


