
/*   This is the code for controlling any R/C car with an airplane transmitter written by Vishnu Chaitanya Karpuram. Enjoy!!   */


int channel5 = 12; // input from rx channel 5 (AUX1) for relay 
int channel2 = 4;// input from rx channel 2 (ELEVATOR) for speed control and forward backward 
//int ppm = 2; // for future ppm input
int relay1 = 10; // to relay
int motor1Left = 5;// defines pin 5 as connected to the motor
int motor1Right = 6;// defines pin 6 as connected to the motor
int speedPin1 = 3;// pwm1
//int motor2Left = 7;// defines pin 7 as connected to the motor
//int motor2Right = 8;// defines pin 8 as connected to the motor
//int speedPin2 = 9; //pwm2

//Leds connected to Arduino UNO Pin 13
//const int blinker  = 13;
//Buzzer / Speaker to Arduino UNO Pin 11
//const int buzzer = 11;   
int Relay1 ; // to relay input
int Channel5 ; // relay
int Channel2 ; // store values direction
//int Channel3 ; // store values direction
int val;
// The setup() method runs once, when the sketch starts

void  setup ()
{
  pinMode (relay1, OUTPUT);// output to relay
  //pinMode(13, OUTPUT);
  pinMode (channel5, INPUT);// as inputs
  pinMode (channel2, INPUT);// as inputs
  //pinMode(channel2, INPUT_PULLUP);
  pinMode (motor1Left, OUTPUT);// initialises the motor pins
  pinMode (motor1Right, OUTPUT);
  //pinMode (motor2Left, OUTPUT);
  //pinMode (motor2Right, OUTPUT);// as outputs
  pinMode (speedPin1, OUTPUT);
  //pinMode (speedPin2, OUTPUT);// as outputs
  //pinMode(blinker, OUTPUT); 
    
//Serial.begin (9600); // Sets the baud rate to 9600 bps for debugging
}

void  loop ()
{

Channel5 = (pulseIn (channel5, HIGH)); // Checks the value of channel3
 Serial.println (Channel5); //Prints the channels value value on the serial monitor
 
  if (Channel5 > 1300 && Channel5 < 1500 ) // If these conditions are true, do the following
  {
    digitalWrite (relay1, LOW);
    //Serial.println("ENGINE DISENGAGED");
  }
 
  if (Channel5 < 1300) // Checks if Channel5 is lesser than 1300
  {
    digitalWrite (relay1, LOW);
    //Serial.println("ENGINE DISENGAGED");
  }
  
  if (Channel5 > 1500) // Checks if Channel5 is greater than 1500
  {
     digitalWrite (relay1, HIGH);// Sets both the
    //Serial.println("ENGINE ENGAGED");
     //play a starting engine sound VAROOM!
  }  
//delay(100);  

  Channel2 = (pulseIn (channel2, HIGH)); // Checks the value of channel2
  Channel2 = map(Channel2,1000,2000,-255,255);
    Serial.println (Channel2); //Prints the channels value value on the serial monitor
 
  if (Channel2 > -25 && Channel2 < 25 ) // If these conditions are true, do the following  idle
  {
    digitalWrite (motor1Left, LOW); // Sets both the
    digitalWrite (motor1Right, LOW);// motors to low
   // digitalWrite (motor2Left, LOW);// Sets both the
   // digitalWrite (motor2Right, LOW);// motors to low
  }
 
  if (Channel2 < -25 && Channel2 > -255) // Checks if Channel2 is lesser than 1300  REVERSE
  {
    digitalWrite (motor1Left, LOW);// Turns the left
    digitalWrite (motor1Right, HIGH); // motor forward
    //digitalWrite (motor2Left, LOW);// Turns the left
    //digitalWrite (motor2Right, HIGH);// motor backward
    //digitalWrite(blinker, HIGH);   // turn the LED on (HIGH is the voltage level)
    //delay(1000);              // wait for a second
    //digitalWrite(blinker, LOW);    // turn the LED off by making the voltage LOW
    //delay(1000);              // wait for a second
 
  }
  if (Channel2 > 25 && Channel2 < 255) // Checks if Channel2 is greater than 1500  FORWARD
  {
    digitalWrite (motor1Left, HIGH);// Turns the right
    digitalWrite (motor1Right, LOW);// motor forward
    //digitalWrite (motor2Left, HIGH);// Turns the right
    //digitalWrite (motor2Right, LOW);// motor backward
  }
   
val = (pulseIn (channel2, HIGH)); // Checks the value of channel2
val = map(val,1000,2000,-255,255);  //val = map(val,1000,2000,-255,255);
Serial.println (val); //Prints the channels value value on the serial monitor
if (val >= 0) 
   {
     analogWrite (speedPin1, val);
   //  analogWrite (speedPin2, val);
   }
  else
  {
    val *= -1;
     analogWrite (speedPin1, val);
    // analogWrite (speedPin2, val);
   }

}

