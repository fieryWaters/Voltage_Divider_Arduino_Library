//Author Jacob Waters

/*
 * This is the source code for my VoltageDivider class.
 */
#ifndef VoltageDivider_h
#include "VoltageDivider.h"
#endif

VoltageDivider::VoltageDivider(uint32_t r1, uint32_t r2, uint8_t pin, double referenceVoltage /* =5 by default */, double manualCorrectionFactor)
{
	resister1 = r1;
	resister2 = r2;
	pinNumber = pin;
	VoltageDivider::errorFactor = errorFactor;
	correctionFactor = ((double)(resister1 + resister2)) / resister2;//(r2/(r1+r2)) is the ratio of voltage drop. Multiplying by the inverse corrects the measurement to 100%.
	correctionFactor = (correctionFactor * referenceVoltage) / 1032;//Any analogRead value needs to be corrected to get a real voltage
	correctionFactor = correctionFactor * manualCorrectionFactor; //accounts for errors after calculations
}
VoltageDivider::VoltageDivider(uint8_t pin,double correctionFactor)
{
	pinNumber = pin;
	VoltageDivider::correctionFactor = correctionFactor;
}

double VoltageDivider::getVoltage()
{
	return analogRead(pinNumber) * correctionFactor;
}
/*
double VoltageDivider::getErrorFactor()
{
	Serial.print("Your ADC Voltage is ");
	Serial.println(getVoltage());
	Serial.println("What is your voltage as measured by a multimeter?");

	while (Serial.available() == 0)
	{
		delay(10);
	}
	double measuredVoltage = Serial.parseFloat();
	Serial.print("multimeterVoltage = ");
	Serial.println(measuredVoltage);

	Serial.println("errorFactor: ");
	Serial.println(errorFactor);

	double factor = errorFactor * measuredVoltage / getVoltage();
	Serial.print("Your error factor for this circuit is ");
	Serial.println(factor);
}
*/
double VoltageDivider::getCorrectionFactor(double adcVoltage, double multimeterVoltage)
{
	return multimeterVoltage/adcVoltage;
}
