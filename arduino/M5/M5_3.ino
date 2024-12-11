#define SIN_MULTI 2
#define COS_MULTI 1
float X; //cos value
float Y; //sin value
void setup() {
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < 75; i++)
    {
        X = cos((4*PI*i)/75);
        Y = sin((2*PI*i)/75);
        Serial.print(X);
        Serial.print(" ");
        Serial.println(Y);
    }
    
}