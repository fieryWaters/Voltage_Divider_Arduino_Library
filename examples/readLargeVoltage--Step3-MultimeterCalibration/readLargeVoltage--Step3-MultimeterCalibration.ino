//Author Jacob Waters
#ifndef VoltageDivider_h
#include "VoltageDivider.h"
#endif

/*
  Once a basic config has been setup, you might want to tune the output
  to match the reading of a higher quality instrument such as a multimeter.

  The voltageDivider will atttempt to correct the ADC reading to account
  for the circuit you put it in. However, due to errors in the resistors
  or elsewhere, the value may be off by a linear factor. This sketch is 
  designed to find this implementation-specific linear factor,
  and account for it.  

  To use this sketch, measure your analog pin with a multimeter 
  and update the multimeterVoltage variable below, then run the sketch.
  It will tell you a value to use for your correctionFactor, update
  correctionFactor as instructed until the battery.getVoltage() call
  returns a value sufficiently close to your multimeter's measured value.

  Once you are satisfied, use this correctionFactor whenever contructing
  a VoltageDivider for this curcuit. That's it!

  IMPORTANT: If (newCorrectionFactor > 1.1) || (newCorrectionFactor < .9),
    YOU PROBABLY MADE AN ERROR IN YOUR CIRCUIT BEWARE!
 */
 
byte precision = 4;
int highSideResister = 5000;//MEASURE WITH MULTIMETER AND UPDATE THIS
int lowSideResister = 5000;//MEASURE WITH MULTIMETER AND UPDATE THIS
int analogPin = A0;
double referenceVoltage = 3.3;//MEASURE WITH MULTIMETER AND UPDATE THIS
double correctionFactor = 1.00; //replace this value with the value recommended below
VoltageDivider battery(highSideResister, lowSideResister, analogPin, referenceVoltage, correctionFactor);

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
