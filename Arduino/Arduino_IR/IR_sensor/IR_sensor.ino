//setting inputs for line tracking sensors
int IR1 = 7;
int IR2 = 2;
int data1;
int data2;

//setting up input pins
void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2,INPUT);
  Serial.begin(9600);
}

//reads data from pins and stores them in variables
//also prints values for testing
void loop() {
  data1 = digitalRead(IR1);
  data2 = digitalRead(IR2);
  Serial.print(data1);
  Serial.print(data2);
} 
