// Pin definitions for sensors
#define digi1  2
#define digi2  3
#define digi3  4
#define digi4  5
#define digi5  6

// Pin definitions for motors
#define motor1Pin 9
#define motor2Pin 10

void setup() {
  // Initialize sensor pins
  pinMode(digi1, INPUT);
  pinMode(digi2, INPUT);
  pinMode(digi3, INPUT);
  pinMode(digi4, INPUT);
  pinMode(digi5, INPUT);
  // Begin serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
    // Read sensor values
    int sensor1 = digitalRead(digi1);
    int sensor2 = digitalRead(digi2);
    int sensor3 = digitalRead(digi3);
    int sensor4 = digitalRead(digi4);
    int sensor5 = digitalRead(digi5);
    
    
    // Print sensor values for debugging
    int sum = (sensor1+ sensor2+ sensor3+ sensor4+ sensor5);
    int sensor_int = (sensor1*(-2000) + sensor2*(-1000) + sensor3*0 + sensor4*1000 + sensor5*2000)/sum; 
    (sensor_int == -2000) ? Serial.print("0 "):NULL;
    (sensor_int == -1500) ? Serial.print("0 and 1 "):NULL;
    (sensor_int == -1000) ? Serial.print("1 "):NULL;
    (sensor_int == -500) ? Serial.print("1 and 2 "):NULL;
    (sensor_int == 0) ? Serial.print("2 "):NULL;
    (sensor_int == 500) ? Serial.print("2 and 3 "):NULL;
    (sensor_int == 1000) ? Serial.print("3 "):NULL;
    (sensor_int ==1500) ? Serial.print("3 and 4 "):NULL;
    (sensor_int == 2000) ? Serial.print("4 "):NULL;
    Serial.print(":error = ");
    Serial.println(sensor_int);    


}
