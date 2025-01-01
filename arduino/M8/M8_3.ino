#define ENA 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define ENB 10



void setup() {
    pinMode(in1, OUTPUT); //motor 1
    pinMode(in2, OUTPUT); //motor 1
    pinMode(ENA, INPUT); //control motor 1
    pinMode(in3, OUTPUT); //motor 2
    pinMode(in4, OUTPUT); //motor 2
    pinMode(ENB, INPUT); //control motor 2
    Serial.begin(9600);
}
    int NUM1 = 240;
    int NUM2 = 200; 
void right()
{
    igitalWrite(in1,LOW);
    digitalWrite(in2, LOW);
    analogWrite(ENA, NUM1);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, NUM2);
}
void left()
{
    igitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, NUM1);
    digitalWrite(in3,LOW);
    digitalWrite(in4, LOW);
    analogWrite(ENB, NUM2);
}

void forward()
{
    igitalWrite(in1,HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, NUM1);
    digitalWrite(in3,HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, NUM2);
}
void revese()
{
    igitalWrite(in1,LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, NUM1);
    digitalWrite(in3,LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENB, NUM2);
}
void loop() {
        
}