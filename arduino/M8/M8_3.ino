//pin config
#define ENA 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define ENB 10



void setup() {
    pinMode(in1, OUTPUT); //motor 1
    pinMode(in2, OUTPUT); //motor 1
    pinMode(ENA, INPUT); //control motor right
    pinMode(in3, OUTPUT); //motor 2
    pinMode(in4, OUTPUT); //motor 2
    pinMode(ENB, INPUT); //control motor left
    Serial.begin(9600);
}
    int NUM1 = 240;
    int NUM2 = 200; 
void right()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, 75);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, 115);
}
void left()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, 140);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, 110);
}

void forward()
{
    digitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, 140);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, 140);
}
void revese()
{
    digitalWrite(in1,LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, NUM1);
    digitalWrite(in3,LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENB, NUM2);
}
void loop() {
    forward(); //go forward for 5 seconds
    delay(5000);
    right(); //turn right with radius of 40 cm for 5 sec
    delay(5000);
    left(); //turn left with radius of 10 cm for 5 sec
    delay(5000);
}