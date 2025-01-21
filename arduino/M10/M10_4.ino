#define ENA 11
#define in1 12
#define in2 10
#define in3 7
#define in4 8
#define ENB 9

// Pin definitions for sensors
#define digi1  2//s0 - orenge
#define digi2  3//s1 - yellow
#define digi3  4//s2 - purple
#define digi4  5//s3 - green
#define digi5  6//s4 - blue

#define high_speed 100

void setup() {
    // Initialize sensor pins
    pinMode(digi1, INPUT);
    pinMode(digi2, INPUT);
    pinMode(digi3, INPUT);
    pinMode(digi4, INPUT);
    pinMode(digi5, INPUT);
    //engine settings
    pinMode(in1, OUTPUT); //motor 1
    pinMode(in2, OUTPUT); //motor 1
    pinMode(ENA, OUTPUT); //control motor 1
    pinMode(in3, OUTPUT); //motor 2
    pinMode(in4, OUTPUT); //motor 2
    pinMode(ENB, OUTPUT); //control motor 2
    Serial.begin(9600);
     // a
}

void loop() {
    // Read sensor values
    int sensor1 = (digitalRead(digi1) -1)*-1;
    int sensor2 = (digitalRead(digi2) -1)*-1;
    int sensor3 = (digitalRead(digi3) -1)*-1;
    int sensor4 = (digitalRead(digi4) -1)*-1;
    int sensor5 = (digitalRead(digi5) -1)*-1;
    
        
    // Print sensor values for debugging
    int sum = (sensor1+ sensor2+ sensor3+ sensor4+ sensor5);
    int sensor_int = (sensor1*-2000 + sensor2*-1000 + sensor3*0 + sensor4*1000 + sensor5*2000)/sum; 
    //enigne control defrentail to error
    //base speed + error*fixrate*engine_size(1/-1)
    int fix_rate = 20/1000;
    int left_engine_fix = sensor_int*fix_rate*(-1);
    int right_engine_fix = sensor_int*fix_rate*(1);
    int speed_left = high_speed + left_engine_fix;
    int speed_right = high_speed + right_engine_fix;

    digitalWrite(in1,LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, speed_left);
    digitalWrite(in3,LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENB, speed_right);
    
}