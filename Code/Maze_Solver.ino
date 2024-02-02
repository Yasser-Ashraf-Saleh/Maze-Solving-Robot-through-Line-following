#define rights 10
#define middle 4
#define lefts 2 

void setup() {
pinMode(lefts,INPUT);
pinMode(rights,INPUT);
pinMode(middle,INPUT);
Serial.begin(9600); // Starts the serial communication

}
int deadpoint=0;

void loop() {
   if (digitalRead(rights)==0&digitalRead(lefts)==1& digitalRead(middle)==1)
    {
      right();
      deadpoint=0;
    }
    else if (digitalRead(rights)==0&digitalRead(lefts)==1& digitalRead(middle)==0)
    {
      right();
      deadpoint=0;
    }
    else if (digitalRead(lefts)==0& digitalRead(middle)==1&digitalRead(rights)==1)
    {
      left();
      deadpoint=0;
    }
    else if (digitalRead(lefts)==0& digitalRead(middle)==0&digitalRead(rights)==1)
    {
      left();
      deadpoint=0;
    }
    else if (digitalRead(middle)==0 & digitalRead(lefts)==1&digitalRead(rights)==1)
    {
      forward();
      deadpoint=0;
    }
      else if (digitalRead(middle)==0 & digitalRead(lefts)==0 &digitalRead(rights)==0)
    {
      right();
      deadpoint=0;
    }
    else if (digitalRead(middle)==1 & digitalRead(lefts)==0 &digitalRead(rights)==0)
    {
      Stop();
      deadpoint=0;
      delay(100000);
    }
      else if (digitalRead(middle)==1 & digitalRead(lefts)==1 &digitalRead(rights)==1)
    {
      if (deadpoint==40)
      {
          left_p();
      }
      else
      {
        deadpoint=deadpoint+1;
      }
    }
      
    
  }


#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

void forward(){ 
  analogWrite(ENA,100); //enable L298n A channel
  analogWrite(ENB,100); //enable L298n B channel
  digitalWrite(IN1,HIGH); //set IN1 hight level
  digitalWrite(IN2,LOW);  //set IN2 low level
  digitalWrite(IN3,LOW);  //set IN3 low level
  digitalWrite(IN4,HIGH); //set IN4 hight level
}

void back(){
  analogWrite(ENA,100);
  analogWrite(ENB,100);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void left(){
  analogWrite(ENA,200);
  analogWrite(ENB,150);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 
}

void right(){
  analogWrite(ENA,200);
  analogWrite(ENB,150);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void left_p(){
  analogWrite(ENA,150);
  analogWrite(ENB,150);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void Stop(){
  analogWrite(ENA,100);
  analogWrite(ENB,100);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
