//Author Jacob Waters
#ifndef VoltageDivider_h
#include "VoltageDivider.h"
#endif

/*
  Once resister values have been chosen and the circuit wired,
  input their values below:
 */
int highSideResister = 9950;//10K Ohm resister
int lowSideResister = 995;//1K Ohm resister
int analogPin = A0;
double referenceVoltage = 3.3;


VoltageDivider battery(highSideResister, lowSideResister, analogPin, referenceVoltage);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Your battery voltage is ");
  Serial.print(battery.getVoltage());
  Serial.println(" Volts");
  delay(1000);

}
