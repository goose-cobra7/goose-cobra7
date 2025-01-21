// Pin definitions for sensors
#define digi1  2//s0 - orenge
#define digi2  3//s1 - yellow
#define digi3  4//s2 - purple
#define digi4  5//s3 - green
#define digi5  6//s4 - blue
// Pin definitions for engine
#define ENA 12 // gray
#define in1 11 // blue
#define in2 10 // red
#define in3 9  // yellow
#define in4 8  // orenge
#define ENB 7 // white

//speed settings
#define left_speed 100
#define right_speed 100


void setup() {
  // Initialize sensor pins
    pinMode(digi1, INPUT);
    pinMode(digi2, INPUT);
    pinMode(digi3, INPUT);
    pinMode(digi4, INPUT);
    pinMode(digi5, INPUT);

    // Initialize motor pins
    pinMode(ENA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    // Begin serial communication for debugging
    Serial.begin(9600);
    
    
}

void loop() 
{
 // Read sensor values
    int sensor1 = (digitalRead(digi1));
    int sensor2 = (digitalRead(digi2));
    int sensor3 = (digitalRead(digi3));
    int sensor4 = (digitalRead(digi4));
    int sensor5 = (digitalRead(digi5));
    
    if (sensor1 == 1 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0 && sensor5 == 0)
    {
      digital_hard_left() //+-|--
    }
    if (sensor1 == 1 && sensor2 == 1 && sensor3 == 0 && sensor4 == 0 && sensor5 == 0)
    {
      digital_left()      //++|--
    }
    if (sensor1 == 0 && sensor2 == 1 && sensor3 == 0 && sensor4 == 0 && sensor5 == 0)
    {
      digital_lil_left()   //-+|--
    }
    if (sensor1 == 0 && sensor2 == 1 && sensor3 == 1 && sensor4 == 0 && sensor5 == 0)
    {
      digital_soft_left() //-++--
    }
    if (sensor1 == 0 && sensor2 == 0 && sensor3 == 1 && sensor4 == 0 && sensor5 == 0)
    {
      digital_forward()   //--+--
    }
    if (sensor1 == 0 && sensor2 == 0 && sensor3 == 1 && sensor4 == 1 && sensor5 == 0)
    {
      digital_soft_right()//--++-
    }
    if (sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 1 && sensor5 == 0)
    {
      digital_lil_right() //--|+-
    }
    if (sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 1 && sensor5 == 1)
    {
      digital_right()     //--|++
    }
    if (sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0 && sensor5 == 1)
    {
      digital_hard_right()//--|-+
    }
}
void digital_hard_right()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*1.4);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*0.6);
}
void digital_right()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*1.3);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*0.7);
}
void digital_lil_right()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*1.2);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*0.8);
}
void digital_soft_right()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*1.1);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*0.9);
}
void digital_hard_left()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*0.6);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*1.4);
}
void digital_left()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*0.7);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*1.3);
}
void digital_lil_left()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*0.8);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*1.2);
}
void digital_soft_left()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed*0.9);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed*1.1);
}

void digital_forward()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, left_speed);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, right_speed);
}
void digital_revese()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, left_speed);
    digitalWrite(in3,LOW);
    digitalWrite(in4, right_speed);
    analogWrite(ENB, NUM2);
}


