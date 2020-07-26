#include<Servo.h>
Servo m;
char data = 0;            //Variable for storing received data
void setup()
{
    m.attach(7);
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
}
void up()
{
  for(int i=90;i<=170;i+=1)
  {
    m.write(i);
    delay(10);
  }
}
void down()
{
  for(int i=170;i>=90;i-=1)
  {
    m.write(i);
    delay(10);
  }
}
void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == 'U' || data == 'u')              // Checks whether value of data is equal to 1
         up();
      else if(data == 'D'||data == 'd')         //  Checks whether value of data is equal to 0
         down();
      else if(data =='S'||data == 's')
         m.detach();
         delay(2);
         m.attach(7);    
      
   }
}
