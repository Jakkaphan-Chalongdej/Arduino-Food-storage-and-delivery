# define EN 8 // stepper motor enable , active low
# define X_DIR 5 // X -axis stepper motor direction control
# define Y_DIR 6 // y -axis stepper motor direction control
# define Z_DIR 7 // z axis stepper motor direction control

# define X_STP 2 // x -axis stepper control
# define Y_STP 3 // y -axis stepper control
# define Z_STP 4 // z -axis stepper control

# define limitPinX 9  // x
# define limitPinY 10 // y
# define limitPinZ 11 // z
# define limitPin 13




void setup () {   // The stepper motor used in the IO pin is set to output
    pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
    pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
    pinMode (Z_DIR, OUTPUT); pinMode (Z_STP, OUTPUT);
    pinMode(limitPinX, INPUT_PULLUP);
    pinMode(limitPinY, INPUT_PULLUP);
    pinMode(limitPinZ, INPUT_PULLUP);
    pinMode(limitPin, INPUT_PULLUP);
    pinMode (EN, OUTPUT);
    digitalWrite (EN, LOW);
    Serial.begin(9600);
}
void step (boolean dir, byte dirPin, byte stepperPin, int steps)
{
    digitalWrite (dirPin, dir);
    delay (50);
    for (int i = 0; i <steps; i ++) 
    {
        digitalWrite (stepperPin, HIGH);
        delayMicroseconds (500);
        digitalWrite (stepperPin, LOW);
        delayMicroseconds (500);
    }
    
}
void loop () {
  if(digitalRead(limitPinX,limitPinY,limitPinZ)==HIGH)
  {
    setfood1();
  }
  else
  {
    setfood2(); 
  }           
} 
void setfood1() {
  if(digitalRead(limitPin)==HIGH)
  {
    if(digitalRead(limitPinX)==LOW)// micro switch X
    {
      step (false, X_DIR, X_STP, 7000);// X axis motor reverse 1 ring, the 200 step is a circle.
      delay (5000);
      step (true, X_DIR, X_STP, 7000); // X axis motor forward 1 laps, the 200 step is a circle.
      
    }
    else if(digitalRead(limitPinY)==LOW)
    {
      step (false, Y_DIR, Y_STP, 7000);    
      delay (5000);
      step (true, Y_DIR, Y_STP, 7000);
      
    }
    else if(digitalRead(limitPinZ)==LOW)
    {
      step (false, Z_DIR, Z_STP, 7000);
      delay (5000);
      step (true, Z_DIR, Z_STP, 7000);
      
    }
    
  }
}
void setfood2(){
  if(digitalRead(limitPin)==HIGH)
  {
    if(digitalRead(limitPinX)==HIGH)// micro switch X
    {
      step (false, X_DIR, X_STP, 7000);// X axis motor reverse 1 ring, the 200 step is a circle.
      delay (5000);
      step (true, X_DIR, X_STP, 7000); // X axis motor forward 1 laps, the 200 step is a circle.
      
    }
    else if(digitalRead(limitPinY)==HIGH)
    {
      step (false, Y_DIR, Y_STP, 7000);    
      delay (5000);
      step (true, Y_DIR, Y_STP, 7000);
      
    }
    else if(digitalRead(limitPinZ)==HIGH)
    {
      step (false, Z_DIR, Z_STP, 7000);
      delay (5000);
      step (true, Z_DIR, Z_STP, 7000);
      
    }
    
  }
}
  
