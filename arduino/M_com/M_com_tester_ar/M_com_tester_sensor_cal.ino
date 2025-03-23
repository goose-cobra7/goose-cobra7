#define digi1 2 // Leftmost sensor
#define digi2 3 // Left sensor
#define digi3 4 // Center sensor
#define digi4 5 // Right sensor
#define digi5 6 // Rightmost sensor

#define SensorCount 5

void setup() {
    Serial.begin(9600); // Initialize Serial Monitor

    // Set sensor pins as input
    pinMode(digi1, INPUT);
    pinMode(digi2, INPUT);
    pinMode(digi3, INPUT);
    pinMode(digi4, INPUT);
    pinMode(digi5, INPUT);

    Serial.println("Calculating line position...");
}

void loop() {
    // Read digital sensor values
    int sensor1 = digitalRead(digi1);
    int sensor2 = digitalRead(digi2);
    int sensor3 = digitalRead(digi3);
    int sensor4 = digitalRead(digi4);
    int sensor5 = digitalRead(digi5);

    // Calculate position based on active sensors
    int position = calculatePosition(sensor1, sensor2, sensor3, sensor4, sensor5);

    // Print the individual sensor readings
    Serial.print("Sensors: ");
    Serial.print(sensor1 == HIGH ? "1" : "0");
    Serial.print(" ");
    Serial.print(sensor2 == HIGH ? "1" : "0");
    Serial.print(" ");
    Serial.print(sensor3 == HIGH ? "1" : "0");
    Serial.print(" ");
    Serial.print(sensor4 == HIGH ? "1" : "0");
    Serial.print(" ");
    Serial.println(sensor5 == HIGH ? "1" : "0");

    // Print the calculated position
    Serial.print("Position: ");
    Serial.println(position);

    delay(200); // Small delay for readability
}

// Function to calculate position
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
