#include <QTRSensors.h>
//settings
#define digi1 8 //color:
#define digi2 9 //color:
#define digi3 10 //color:
#define digi4 11 //color:
#define digi5 12 //color:


#define in2 4 //left //color:
#define ENA 5 //left //color:
#define in3 2 //right //color:
#define ENB 3 //right //color:

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