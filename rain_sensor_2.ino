/* Connection pins:
Arduino     Rain Sensor
  A0         Analog A0
  5V           VCC
  GND          GND
*/
/*
  - If the Sensor Board is completely soaked; "case 0" will be activated and " Flood " will be sent to the serial monitor.
  - If the Sensor Board has water droplets on it; "case 1" will be activated and " Rain Warning " will be sent to the serial monitor.
  - If the Sensor Board is dry; "case 2" will be activated and " Not Raining " will be sent to the serial monitor. 
*/
// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  Serial.begin(9600);  
  pinMode(2, OUTPUT); // red led
  pinMode(3, OUTPUT); // yellow led
  pinMode(4, OUTPUT); // green led
}

void loop() {
 int sensorReading = analogRead(A0); // read the sensor on analog A0
 int range = map(sensorReading, sensorMin, sensorMax, 0, 3); // map(value, fromLow, fromHigh, toLow, toHigh)
                                                              /*
                                                              value: the number to map.
                                                              fromLow: the lower bound of the value’s current range.
                                                              fromHigh: the upper bound of the value’s current range.
                                                              toLow: the lower bound of the value’s target range.
                                                              toHigh: the upper bound of the value’s target range.
                                                              */
 switch (range) { // range value
  case 0:    // Sensor getting wet
   Serial.println("Flood");
   digitalWrite(2, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   break;
  case 1:    // Sensor getting wet
   Serial.println("Rain Warning");
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(4, LOW);
   break;
  case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
   Serial.println("Not Raining");
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, HIGH);
   break;
 }
delay(1000);  // sensor reads input every 1 s
}
