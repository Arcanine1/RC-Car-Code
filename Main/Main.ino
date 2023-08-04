# define leftOne 5
# define leftTwo 6
# define rightOne 7
# define rightTwo 8


void setup() {

  // sets up pins
  pinMode(leftOne, OUTPUT);
  pinMode(leftTwo, OUTPUT);
  pinMode(rightOne, OUTPUT);
  pinMode(rightTwo, OUTPUT);


}

void loop() {
  test();
}


void forward(){
  digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,HIGH);
  digitalWrite(rightTwo,LOW);

}

void backward(){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,HIGH);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);

}

void turnLeft(){
  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);
}


void turnRight(){
  digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,LOW);
}

void test(){

  forward();
  delay(2000);

  backward();
  delay(2000);

  turnLeft();
  delay(2000);

  turnRight();
  delay(2000);
}



