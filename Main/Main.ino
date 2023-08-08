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

    String a = readString();

    if(a=="test"){
      test();
    }

    else if(a=='S'){
      stop();
    }

    else if(a=='F'){
      forward(getSpeed());
    }

    else if(a=='B'){
      backward(getSpeed());
    }

    else if(a=='L'){
      turnLeft(getSpeed());
    }

    else if(a=='R'){
      turnRight(getSpeed());
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

//gets speed from next 2 charcter inputs
double getSpeed(){
  BT.println("enter speed");
  int digitOne =0;
  int digitTwo =0;
  int digit =1;

  while(true){
    if(BT.available()){
      if(digit==1){
        char CdigitOne = BT.read();
        if(isDigit(CdigitOne)){
          digitOne = int(CdigitOne)-48;
        }
        else{
          return 0;
        } 
        BT.println(digitOne);
      }

      if(digit==2){
        char CdigitTwo = BT.read();
        if(isDigit(CdigitTwo)){
          digitTwo = int(CdigitTwo)-48;
        }
        else{
          return 0;
        } 
        BT.println(digitTwo);

      }

      digit++;
      if(digit>2){
        break;
      }

    }
  }
  BT.println(digitOne*10 +digitTwo);
  return (digitOne*10 +digitTwo);
}

