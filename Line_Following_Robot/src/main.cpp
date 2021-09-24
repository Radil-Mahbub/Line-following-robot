#include <Arduino.h>
#define LeftPin A0
#define RightPin A1

//motor settings
#define enA 11
#define enB 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6

void LineFollow()
{
  int Left = digitalRead (LeftPin);
  int Right= digitalRead (RightPin);

  if (Left == HIGH  && Right == LOW) //left turn
  {
digitalWrite (enB, HIGH);
digitalWrite (enA, HIGH);
               
digitalWrite (in3, LOW );
digitalWrite (in4, HIGH);

         
         digitalWrite (in1, HIGH );
         digitalWrite (in2, LOW);
  }

  else if (Right == HIGH && Left == LOW)
  {
      digitalWrite (enB, HIGH);
       digitalWrite (enA, HIGH);

         digitalWrite (in3, HIGH );
         digitalWrite (in4, LOW);

          digitalWrite (in1, LOW );
         digitalWrite (in2, HIGH);
  }
  
  else
  {
     digitalWrite (enA,HIGH);
    digitalWrite (enB, HIGH);
 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
 
  }
}


void setup()
{
   for (int i=in1; i<=in4; i++)
  {
    pinMode (i, OUTPUT);
  }
  pinMode (enA,OUTPUT);
  pinMode (enB,OUTPUT);

  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  LineFollow();
}