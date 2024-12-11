void setup() {
    pinMode(3, OUTPUT); // red
    pinMode(4, OUTPUT); // yellow
    pinMode(5, OUTPUT); // green
    pinMode(6, INPUT_PULLUP);
}
void loop() {
    if (digitalRead(6) == 0)
    {
      digitalWrite(5, LOW);  //green off
      digitalWrite(4, LOW); //yellow off
      digitalWrite(3, HIGH); //botton pressed then red is on
    }else{
        digitalWrite(4, LOW); // yellow off
        digitalWrite(3, HIGH); //trun red on
        delay(10000); //10 sec
        digitalWrite(4, HIGH); //turn yellow on (red and yellow on)
        delay(5000); //5 sec
        digitalWrite(3, LOW); //turn off red
        digitalWrite(4, LOW); //turn off yellow
        digitalWrite(5, HIGH); //green on (only green on)
        delay(10000); //10 sec
        digitalWrite(5, LOW); //green off
        digitalWrite(4, HIGH); //yellow on (only yellow on)
        delay(5000); // 5 sec
    }
}