int motor1=3;
int motor2=5;
int poten1=15;
int poten2=14;
int switch1=2;
int switch2=4;
int R1=0, R2=0;
char x;

void setup()
{
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(poten1,INPUT);
  pinMode(poten2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()){
    x=Serial.read();}
  
  if(digitalRead(switch1)==HIGH || x == 'L'){
    int R1 = map(analogRead(poten1),0,1023,0,255);
    analogWrite(motor1,R1);
  }
  else{analogWrite(motor1,0);}

  if(digitalRead(switch2)==HIGH || x =='R'){
    int R2 = map(analogRead(poten2),0,1023,0,255);
    analogWrite(motor2,R2);
  }
    else{analogWrite(motor2,0);}
  if(x=='S'){analogWrite(motor1,0); analogWrite(motor2,0);}
}
