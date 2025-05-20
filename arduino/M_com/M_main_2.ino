#include <QTRSensors.h>

#define digi1 12 //color:
#define digi2 11 //color:
#define digi3 10 //color:
#define digi4 9 //color:
#define digi5 8 //color:

#define in2 4 //left //color:
#define ENA 5 //left //color:
#define in3 2 //right //color:
#define ENB 3 //right //color:

#define control 7

#define SensorCount 5 
#define BASE_SPEED 100 //145
#define MAX_SPEED 250 //255
#define LOW_SPEED 37 //37

#define CRITICAL_SPEED 200
#define CRITICAL_SPEED_MORE 400
#define MAX_ENGLE 400


#define Kp 0.8
#define Ki 0
#define Kd 1

//int out_of_line = 0;
// Initialize the QTRSensors object

int I_error;
int prev_error;
float PID;
int lsp,rsp;

//float startTime;
//float endTime;

int how_much_to_slow_in_angle = 0;

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
  //startTime = millis();  // Record start time

    // Read digital sensor values
    int sensor1 = digitalRead(digi1) == LOW ? HIGH : LOW; // Invert: HIGH for black, LOW for white
    int sensor2 = digitalRead(digi2) == LOW ? HIGH : LOW;
    int sensor3 = digitalRead(digi3) == LOW ? HIGH : LOW;
    int sensor4 = digitalRead(digi4) == LOW ? HIGH : LOW;
    int sensor5 = digitalRead(digi5) == LOW ? HIGH : LOW;
    // Calculate position based on active sensors
    int position = calculatePosition(sensor1, sensor2, sensor3, sensor4, sensor5);
    
    engine_control(PIDfix(position),out_of_line(sensor1, sensor2, sensor3, sensor4, sensor5));
    //endTime = millis(); 
    //Serial.println(endTime - startTime); 
}

int PIDfix(int error)
{
    static int count = 0;
    //if(error == 0){I_error = 0;}else{I_error += error/100;}
    check_engle(error);
    PID = float(error)*Kp + float(error-prev_error)*Kd /*+ float(I_error)*Ki*/;
    count++;
    if(count > 400&& prev_error != error){prev_error = error; count = 0;}
    //Serial.print(error);
    //Serial.print(" ");
    //Serial.println(PID);
    return (int)PID/(2000/BASE_SPEED);
    
}

int check_engle(int error)
{
    if((error > MAX_ENGLE || error < (-1)*MAX_ENGLE) && how_much_to_slow_in_angle < CRITICAL_SPEED_MORE)
    {
        how_much_to_slow_in_angle =+ 10;
    }
    else if((error > MAX_ENGLE || error < (-1)*MAX_ENGLE) && how_much_to_slow_in_angle < CRITICAL_SPEED)
    {
        how_much_to_slow_in_angle =+ 2;
        
    }else if (error == 0 && how_much_to_slow_in_angle > -200)
    {
        how_much_to_slow_in_angle = how_much_to_slow_in_angle-1;
    }
    //Serial.println(how_much_to_slow_in_angle); //debug check
}

void engine_control(int PID_error,int out_of_line)
{
    static int count_on_white = 0;
    static int prev_fix = 0;
    lsp = (BASE_SPEED-(how_much_to_slow_in_angle/50)) - PID_error;
    rsp = (BASE_SPEED-(how_much_to_slow_in_angle/50)) + PID_error;
    
    lsp = constrain(lsp, LOW_SPEED, MAX_SPEED);
    rsp = constrain(rsp, LOW_SPEED, MAX_SPEED);
    //Serial.println(out_of_line);
    if (out_of_line == 1) //if all on black move stright
    { //כאשר הכל שחור סע ישר
        lsp = BASE_SPEED;
        rsp = BASE_SPEED;
    }else if (out_of_line == -1) //if out of line repeat last move
    { //if all white continue stright
        lsp = BASE_SPEED;
        rsp = BASE_SPEED;
        if(count_on_white < 400 && count_on_white != 0)
        {
            edge_case_1();
            count_on_white = 0;
        }else
        {
            count_on_white = 0;
        }
    }else{
      digitalWrite(in2, 1); //drive forword
      digitalWrite(in3, 1); //drive forword
      count_on_white++;
      analogWrite(ENA, lsp);
      analogWrite(ENB, rsp);
      prev_fix = PID_error; //save last move
    }   
}

void edge_case_1()
{
    analogWrite(ENA, 250);
    analogWrite(ENB, 0);
    delay(200);
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);

}

int out_of_line(int s1, int s2, int s3, int s4, int s5)
{
    if (s1 == HIGH && s2 == HIGH && s3 == HIGH && s4 == HIGH && s5 == HIGH) {return 1;} //all black
    if (s1 == LOW && s2 == LOW && s3 == LOW && s4 == LOW && s5 == LOW) {return -1;} //all white
    return 0; //on line
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