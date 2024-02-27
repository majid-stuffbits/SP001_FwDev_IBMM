const int analogInPin = 33; // Replace with your chosen ESP32 analog input pin
const float adcReferenceVoltage = 1.1; // ADC reference voltage of the ESP32
const float acs758Sensitivity = 0.04; // Sensitivity of ACS758 (40mV/A)

void setup() {
Serial.begin(115200);
}

void loop() {
int adcValue = analogRead(analogInPin);
float voltage = adcValue * adcReferenceVoltage / 4095; // Convert ADC reading to voltage
float current = voltage / acs758Sensitivity; // Calculate current using ACS758 sensitivity

Serial.print("Raw ADC Value: ");
Serial.print(adcValue);
Serial.print(" Voltage: ");
Serial.print(voltage, 4);
Serial.print("V Current: ");
Serial.print(current, 4);
Serial.println("A");

delay(1000); // Delay for stability
}

//const int senseIn = 33;
//int miliVoltsPerAmp = 40; //See the diagram for scale factors
//int acOffset = 2500;  //See the diagram for offset value
//int rawSense = 0;
//double voltageValue = 0;
//double amp = 0;
//
//void setup(){
//    while(!Serial){
//  Serial.begin(115200); //If serial is available 
//}
//  Serial.println("14CORE | ACS758 Test Code");
//  Serial.println("Initializing ............");
//  delay(2000);
//}
//
//void loop(){
//    rawSense = analogRead(senseIn);
//    voltageValue = (rawSense / 4096.0) * 1100;
//    amp = ((voltageValue - acOffset)/miliVoltsPerAmp);
//    Serial.println("RAW VALUE > ");
//    Serial.println("rawSense");
//    Serial.println("MiliVolts > "); //Print measured voltageValue
//    Serial.println("voltageValue, 3"); //Set display 3 digits after decimal point
//    Serial.println("AMPS > "); 
//    Serial.println(amp, 3);
//    delay(1000);
//}
