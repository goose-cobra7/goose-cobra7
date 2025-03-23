#include <QTRSensors.h>

#define digi1 2 //color:
#define digi2 3 //color:
#define digi3 4 //color:
#define digi4 5 //color:
#define digi5 6 //color:

#define in2 11 //left //color:
#define ENA 9 //left //color:
#define in3 12 //right //color:
#define ENB 10 //right //color:

#define control 7

#define SensorCount 5 
#define BASE_SPEED 70 //145
#define MAX_SPEED 140 //255
#define LOW_SPEED 37 //37


#define Kp 1.0
#define Ki 0.2
#define Kd 0.5

int on_white = 0;
// Initialize the QTRSensors object

int I_error;
int prev_error;
float PID;
int lsp,rsp;

void setup() {
    //engine settings
    pinMode(in2, OUTPUT); //motor 1
    pinMode(ENA, OUTPUT); //control motor 1
    pinMode(in3, OUTPUT); //motor 2
    pinMode(ENB, OUTPUT); //control motor 2
    Serial.begin(9600); //debug tool
    //sensor setup

    //led setup
    //pinMode(LED_BUILTIN, OUTPUT);
    //control button setup
    //pinMode(control, INPUT_PULLUP);

    // print the calibration minimum values measured when emitters were on
    //digitalWrite(LED_BUILTIN, HIGH);
    //while (digitalRead(control)==LOW) {;} //waiting to finish setup and start loop
    //digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
    // Read digital sensor values
    int sensor1 = digitalRead(digi1) == LOW ? HIGH : LOW; // Invert: HIGH for black, LOW for white
    int sensor2 = digitalRead(digi2) == LOW ? HIGH : LOW;
    int sensor3 = digitalRead(digi3) == LOW ? HIGH : LOW;
    int sensor4 = digitalRead(digi4) == LOW ? HIGH : LOW;
    int sensor5 = digitalRead(digi5) == LOW ? HIGH : LOW;
    // Calculate position based on active sensors
    int position = calculatePosition(sensor1, sensor2, sensor3, sensor4, sensor5);
    
    engine_control(PIDfix(position),out_of_line(sensor1, sensor2, sensor3, sensor4, sensor5));
}

int PIDfix(int error)
{
    static int count = 0;
    //if(error == 0){I_error = 0;}else{I_error += error/100;}

    PID = float(error)*Kp + float(error-prev_error)*Kd + float(I_error)*Ki;
    count++;
    if(count > 40&& prev_error != error){prev_error = error; count = 0;}
    //Serial.print(error);
    //Serial.print(" ");
    Serial.println(PID);
    return (int)PID/(2000/BASE_SPEED);
    
}

void engine_control(int PID_error,int out_of_line)
{

    static int prev_fix = 0;
    lsp = BASE_SPEED - PID_error;
    rsp = BASE_SPEED + PID_error;
    
    lsp = constrain(lsp, LOW_SPEED, MAX_SPEED);
    rsp = constrain(rsp, LOW_SPEED, MAX_SPEED);

    if (out_of_line == -1) //if all on black move stright
    { //כאשר הכל שחור סע ישר
        lsp = BASE_SPEED;
        rsp = BASE_SPEED;
    }else if (out_of_line == 1) //if out of line repeat last move
    { //שאתה מחוץ לקו בצע פעולה אחרונה
        lsp = BASE_SPEED - prev_fix;
        rsp = BASE_SPEED + prev_fix;
        PID_error = prev_error; //make sure to continue
    }
    
    digitalWrite(in2, 1); //drive forword
    digitalWrite(in3, 1); //drive forword

    analogWrite(ENA, lsp);
    analogWrite(ENB, rsp);
    delay(40);
    prev_fix = PID_error; //save last move
}

int out_of_line(int s1, int s2, int s3, int s4, int s5)
{
    if (s1 == HIGH && s2 == HIGH && s3 == HIGH && s4 == HIGH && s5 == HIGH) {return 1;}
    if (s1 == LOW && s2 == LOW && s3 == LOW && s4 == LOW && s5 == LOW) {return -1;}
    return 0;
}

int calculatePosition(int s1, int s2, int s3, int s4, int s5) {
    // Weights for each sensor from left (-2000) to right (2000)
    const int weights[SensorCount] = {-2000, -1000, 0, 1000, 2000};
    int sumWeighted = 0; // Sum of weighted sensor values
    int sumActiveSensors = 0; // Count of active sensors

    // Accumulate weighted sum and count active sensors
    if (s1 == HIGH) { sumWeighted += weights[0]; sumActiveSensors++; }
    if (s2 == HIGH) { sumWeighted += weights[1]; sumActiveSensors++; }
    if (s3 == HIGH) { sumWeighted += weights[2]; sumActiveSensors++; }
    if (s4 == HIGH) { sumWeighted += weights[3]; sumActiveSensors++; }
    if (s5 == HIGH) { sumWeighted += weights[4]; sumActiveSensors++; }

    // Prevent division by zero in case no sensors are active
    if (sumActiveSensors > 0) {
        return sumWeighted / sumActiveSensors;
    } else {
        return 0; // Default to center when no sensors detect the line
    }
}