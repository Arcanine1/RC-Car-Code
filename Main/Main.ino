#include <SoftwareSerial.h>;
SoftwareSerial BT(2, 3); 

# define leftOne 5
# define leftTwo 6
# define rightOne 7
# define rightTwo 8

#define leftSpeed A5
#define rightSpeed A6


void setup() {

  // sets up pins
  pinMode(leftOne, OUTPUT);
  pinMode(leftTwo, OUTPUT);
  pinMode(rightOne, OUTPUT);
  pinMode(rightTwo, OUTPUT);

  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");

}

char a; // stores incoming character from other device

void loop() {

    if (BT.available())
  // if text arrived in from BT serial...
  {

    a=(BT.read());
    if(a=='T'){
      test();
    }
    else{
      forward(10*int(a));
    }
   
  }

}



void forward(double speed){
  digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,HIGH);
  digitalWrite(rightTwo,LOW);

  int normalizedSpeed = (speed/100)*255;
  analogWrite(leftSpeed,normalizedSpeed);
  analogWrite(rightSpeed,normalizedSpeed);
}


void backward(double speed){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,HIGH);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);

  int normalizedSpeed = (speed/100)*255;
  analogWrite(leftSpeed,normalizedSpeed);
  analogWrite(rightSpeed,normalizedSpeed);

}

void turnLeft(double speed){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,HIGH);
  digitalWrite(rightOne,HIGH);
  digitalWrite(rightTwo,LOW);

  int normalizedSpeed = (speed/100)*255;
  analogWrite(leftSpeed,normalizedSpeed);
  analogWrite(rightSpeed,normalizedSpeed);
}


void turnRight(double speed){
  digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);

  int normalizedSpeed = (speed/100)*255;
  analogWrite(leftSpeed,normalizedSpeed);
  analogWrite(rightSpeed,normalizedSpeed);
}

void stop(){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,LOW);

  analogWrite(leftSpeed,0);
  analogWrite(rightSpeed,0);
}

void test(){

  for (int i=0; i<100; i++){
  forward(i);
  delay(100);
}


  stop();
}



