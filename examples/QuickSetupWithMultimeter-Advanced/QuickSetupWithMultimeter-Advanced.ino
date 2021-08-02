//Author Jacob Waters

#ifndef VoltageDivider_h
#include "VoltageDivider.h"
#endif

/*
  If your circuit is already wired, and you can't be bothered to
  measure individual components, or you wish to use VoltageDivider
  without resisters in your implementation, simply declare the pin
  and a custom correction factor.

  The correctionFactor simply multiplies any ADC reading by a linear factor.

  Measure your analogPin with a multimeter, and update the variable
  correctionFactor below as instructed by the sketch. Once the circuit is
  tuned properly, delete the code in the loop and use battery.getVoltage()
  to your heart's content. 
 */

byte precision = 4;
int analogPin = A0;
double correctionFactor = 1.00; //replace this value with the value recommended below
VoltageDivider battery(analogPin, correctionFactor);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

double multimeterVoltage = 3.3;//replace this with a real measurement of your analog pin using a multimeter.

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Your ADC Voltage is ");
  double adcVoltage = battery.getVoltage();
  Serial.println(adcVoltage,precision);
  Serial.print("Your multimeter voltage is ");//measured by you and input into the sketch above ^
  Serial.println(multimeterVoltage,precision);
  Serial.print("Your updated correction factor is ");
  double newCorrectionFactor = correctionFactor * battery.getCorrectionFactor(adcVoltage, multimeterVoltage);
  Serial.println(newCorrectionFactor,precision);
  Serial.println("Now save this value for reference and update correctionFactor in the sketch\n");

  delay(1000);


}
