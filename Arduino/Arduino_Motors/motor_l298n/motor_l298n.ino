//sets pin variables
int motor1pin1 = 5;
int motor1pin2 = 4;
#define ENA_pin 9
#define ENB_pin 11
int motor2pin1 = 6;
int motor2pin2 = 7;

//sets pins outputs and inputs
//also writes initial speed to motors
void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  analogWrite(ENA_pin, 255);
  analogWrite(ENB_pin, 255);
}

//switches motor directions every 1000 ms
void loop() {
  // put your main code here, to run repeatedly:   
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);
}
