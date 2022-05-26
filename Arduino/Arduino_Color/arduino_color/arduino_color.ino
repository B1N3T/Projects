//sets pins
#define s0 8
#define s1 9
#define s2 10
#define s3 11
#define out 12

//setting variables
int data=0;        
int color = 100;
int red_result = 100;

void setup() 
{
   pinMode(s0,OUTPUT);    //pin modes
   pinMode(s1,OUTPUT);
   pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);
   Serial.begin(9600);   //intialize the serial monitor baud rate
   digitalWrite(s0,HIGH); //output frequency scalling is at 100%
   digitalWrite(s1,HIGH); //LOW/LOW is off HIGH/LOW is 20% and LOW/HIGH is  2%
   
}

//S2/S3 levels define which set of photodiodes we are using
//LOW/LOW is for RED 
//LOW/HIGH is for Blue 
//HIGH/HIGH is for green
void loop()                 
{  
   digitalWrite(s2,LOW);       
   digitalWrite(s3,LOW);        //Under 25, it senses red
   Serial.print("Red ="); 
   red_result = GetData();      //Executing GetData (located at bottom of code)
   delay(2000);
}

int GetData(){
   data=pulseIn(out,LOW);
   delay(20);
   return data;
}
