const int buzzer = 8; 
int steady = 0; 
long Uduration, Lduration,  Uinches , Linches;
 
void setup() {
 
  pinMode(buzzer, OUTPUT); 
  pinMode(9,OUTPUT);
}
 
void loop()
{
 
  //Upper Tank
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  delayMicroseconds(5);   // find out the duration of obstacle 
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
  
  // Read the signal from the Upper tank sensor:
  pinMode(12, INPUT);
  Uduration = pulseIn(12, HIGH);
    
  // convert time into distance
  Uinches = (Uduration/2) / 74; 
  
  
  //Lower Tank
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  delayMicroseconds(5);  
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  // Read the signal from the Lowe tank sensor:
  pinMode(3, INPUT);
  Lduration = pulseIn(3, HIGH);
  
  // convert time into distance
  Linches = (Lduration/2) / 74; 
  
  
  //if Upper tank Water level is less than 5 inch
  // & Lower tank as more than 10 inch water level
  // Motor will ON
  
  if(Uinches<5 && Linches>10)
  {
  if(steady==0)
    {
    digitalWrite(9, HIGH);
    tone(buzzer, 500); 
    delay(100);        
    noTone(buzzer);     
    delay(100);
    steady=1;
    }
  }
  
  //if Lower tank as less than 5 inch water level
  // Motor will OFF
  
  else if(Linches < 5)
  {
    if(steady==1)
    {
    digitalWrite(9, LOW);
    tone(buzzer, 1000);
    delay(100);       
    noTone(buzzer);     
    delay(100);
    steady=0;
    }
    
  } 
  
}
