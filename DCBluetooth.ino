//DC Motor BTooth
char data = 0;
int p1 = 2;
int p2 = 3;// RIGHT WHEELS
int p3 = 4;
int p4 = 5;// LEFT WHEELS
void back()
{
  //FORWARD
  digitalWrite(p1, HIGH);
  digitalWrite(p2, LOW);
  digitalWrite(p3, HIGH);
  digitalWrite(p4, LOW);
}
void forward()
{
  digitalWrite(p2, HIGH);
  digitalWrite(p1, LOW);
  digitalWrite(p4, HIGH);
  digitalWrite(p3, LOW);
}
void left()
{
  digitalWrite(p1, LOW);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, LOW);
  digitalWrite(p4, LOW);
}
void right()
{
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
  digitalWrite(p4, HIGH);
}
void halt()
{
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
  digitalWrite(p4, LOW);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == 'F'||data=='f')              // Checks whether value of data is equal to 1
         forward();   //If value is 1 then LED turns ON
      else if(data == 'B'||data=='b')         //  Checks whether value of data is equal to 0
         back();    
      else if(data == 'h'||data=='H')
         halt();
      else if(data == 'l'||data=='L')
         left();
      else if(data == 'r'||data=='R')
         right();
   }
}
