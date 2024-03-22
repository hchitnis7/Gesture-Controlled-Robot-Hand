#include <Servo.h>

Servo servothumb;
Servo servoindex;
Servo servomiddle;
Servo servoring;
Servo servopinky;

char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 6;

int servoPinky, servoMiddle, servoIndex, servoThumb, servoRing;
int myVals[] = { 0, 0, 0, 0, 0 };

int myButton = 1;
bool portable;

void setup() {

  Serial.begin(9600);
  servothumb.attach(9);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);

  servoindex.attach(10);
  servopinky.attach(11);
  servoring.attach(12);
  servomiddle.attach(13);
  myButton = analogRead(A0);
  delay(500);
  if (myButton == 0) {
    portable = false;
  } else {
    portable = true;
  }
}

void loop() {

  myButton = analogRead(A0);
  if (portable != true) {
    if (myButton == 0) {
      // allOFF();}
    } else {
    }  // allON();}
  } else {
    Serial.println("inels");
    receiveData();
  }
}

void allON() {

  servopinky.write(180);
  servoindex.write(180);
  servomiddle.write(180);
  servothumb.write(180);
  servoring.write(180);
}


void allOFF() {

  servopinky.write(0);
  servoindex.write(0);
  servomiddle.write(0);
  servothumb.write(0);
  servoring.write(0);
}


int receiveData() {
  int i = 0;
  int p = 0;
  while (Serial.available()) {

    myRevivedString = Serial.readString();

    // if (c == '$') {
    // stringCounterStart = true;
    // }
    // if (stringCounterStart == true )
    // {
    //   if (stringCounter < stringLength)
    //   {
    //     myRevivedString = String(myRevivedString + c);
    //     stringCounter++;
    //   }
    // if (stringCounter >= stringLength) {
    // stringCounter = 0; stringCounterStart = false;
    Serial.println("here");
    servoPinky = myRevivedString.substring(1, 2).toInt();
    servoRing = myRevivedString.substring(2, 3).toInt();
    servoMiddle = myRevivedString.substring(3, 4).toInt();
    servoIndex = myRevivedString.substring(4, 5).toInt();
    servoThumb = myRevivedString.substring(5, 6).toInt();
    // Serial.print(servoPinky);
    // Serial.print(" ");
    // Serial.print(servoRing);
    // Serial.print(" ");
    // Serial.print(servoMiddle);
    // Serial.print(" ");
    // Serial.print(servoIndex);
    // Serial.print(" ");
    // Serial.println(servoThumb);
    if (servoPinky == 1) {
      servopinky.write(180);
    } else {
      servopinky.write(0);
    }
    if (servoIndex == 1) {
      servoindex.write(180);
    } else {
      servoindex.write(0);
    }
    if (servoMiddle == 1) {
      servomiddle.write(180);
    } else {
      servomiddle.write(0);
    }
    if (servoThumb == 1) {
      servothumb.write(180);
        digitalWrite(4, HIGH);
    } else {
      servothumb.write(0);
      digitalWrite(7, HIGH);
    }
    if (servoRing == 1) {
      servoring.write(180);
    } else {
      servoring.write(0);
    }
    Serial.println("writtten");
    // delay(1000);
    // digitalWrite(7, LOW);
  }
  // digitalWrite(4, HIGH);
  // delay(5000);
  // digitalWrite(4, LOW);
  myRevivedString = "";
  return p;
  // }
}
