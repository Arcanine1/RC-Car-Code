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
  
  digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,LOW);
  delay(2000);

  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,HIGH);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,LOW);
  delay(2000);

  digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,HIGH);
  digitalWrite(rightTwo,LOW);
  delay(2000);

    digitalWrite(leftOne,LOW);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);
  delay(2000);

      digitalWrite(leftOne,HIGH);
  digitalWrite(leftTwo,LOW);
  digitalWrite(rightOne,LOW);
  digitalWrite(rightTwo,HIGH);
  delay(2000);
}
