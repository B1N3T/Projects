#include <Servo.h>
#define s0 8       //Module pins wiring
#define s1 0
#define s2 1
#define s3 13
#define out 12

int motor1pin1 = 5;
int motor1pin2 = 4;
int motor2pin1 = 6;
int motor2pin2 = 7;
int IR1 = 10;
int IR2 = 2;
int data1;
int data2;
int data = 0;        //This is where we're going to stock our values
int color = 100;
int servoPin = 3;
int angle = 140;
int red_result = 100;
bool x = true;

// Create a servo object
Servo Servo1;

void setup()
{
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(s0, OUTPUT);   //pin modes
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  Servo1.attach(servoPin);

  Serial.begin(9600);   //intialize the serial monitor baud rate

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

}

void loop()                  //Every 2s we select a photodiodes set and read its data
{
  digitalWrite(s2, LOW);       //S2/S3 levels define which set of photodiodes
  //LOW/LOW is for RED
  //LOW/HIGH is for Blue
  //HIGH/HIGH is for green
  digitalWrite(s3, LOW);       //Under 25, it senses red
  Serial.print("Red =");
  red_result = GetData();                   //Executing GetData function to get the value

  // Make servo go to 0 degrees
  Servo1.write(angle);
  delay(1000);

  if (red_result  <= 20)
  {
    // Make servo go to 90 degrees
    Servo1.write(angle - 102);
    delay(10000);
    while (x = true) {
      data1 = digitalRead(IR1);
      data2 = digitalRead(IR2);
      Serial.print(data1);
      Serial.print(data2);
      if (data1 ==  1 && data2 == 0) {
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
      }
      else if (data2 == 1 && data1 == 0) {
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
      }
      else {
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
      }
    }

    Serial.println();

    delay(2000);
  }
}

int GetData() {
  data = pulseIn(out, LOW);
  Serial.print(data);
  Serial.print("\t");
  delay(20);
  return data;
}
