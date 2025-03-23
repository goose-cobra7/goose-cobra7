#include <QTRSensors.h>
//settings
#define digi1 A3 //color:
#define digi2 A3 //color:
#define digi3 A4 //color:
#define digi4 A5 //color:
#define digi5 A6 //color:

#define in2 11 //left //color: orenge
#define ENA 9//left //color: brown
#define in3 12 //A2 //right //color: blue
#define ENB 10 //right //color: red

#define control 7

#define SensorCount 5
#define BASE_SPEED 180
#define MAX_SPEED 255
#define LOW_SPEED 20

#define Kp 1.0
#define Ki 0.5
#define Kd 0.2




int on_white = 0;
QTRSensors qtr;

uint16_t sensorValues[SensorCount];
int threshold[SensorCount];
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
}


//change LOW_SPEED and MAX_SPEED to find your settings
//open Serial Plotter for better view
void loop() {
    digitalWrite(in2, 1); //drive forword
    digitalWrite(in3, 1); //drive forword

    digitalWrite(LED_BUILTIN, HIGH);
    for (size_t i = LOW_SPEED; i <= MAX_SPEED; i++) //speed up
    {
        analogWrite(ENA, i);
        analogWrite(ENB, i);
        delay(40);
        Serial.println(i);
    }
    digitalWrite(LED_BUILTIN, LOW);
    for (size_t i = MAX_SPEED; i >= LOW_SPEED; i--) //slow down
    {
        analogWrite(ENA, i);
        analogWrite(ENB, i);
        delay(40);
        Serial.println(i);
    }

}