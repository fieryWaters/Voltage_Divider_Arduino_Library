/*
 * This is the source code for my VoltageDivider class.
 */

#include "Arduino.h"
#include "VoltageDivider.h"

VoltageDivider::VoltageDivider(uint32_t r1, uint32_t r2, uint8_t pin, double referenceVoltage /* =5 by default */, double errorFactor)
{
	resister1 = r1;
	resister2 = r2;
	pinNumber = pin;
	correctionFactor = ((double)(resister1 + resister2)) / resister2;//(r2/(r1+r2)) is the ratio of voltage drop. Multiplying by the inverse corrects the measurement to 100%.
	correctionFactor = (correctionFactor * referenceVoltage) / 1032;//Any analogRead value needs to be corrected to get a real voltage
	correctionFactor = correctionFactor * errorFactor; //accounts for errors after calculations
}
double VoltageDivider::getVoltage()
{
	return analogRead(pinNumber) * correctionFactor;
}
double getErrorFactor()
{
	Serial.print("Your measured Voltage is ");
	Serial.println(getVoltage());
	Serial.println("What is your voltage as measured by a multimeter?");
	while (Serial.available() == 0)
	{
		delay(10);
	}
	double measuredVoltage = Serial.parseFloat();
	double factor = errorFactor * measuredVoltage / getVoltage();
	Serial.print("Your error factor for this circuit is ");
	Serial.println(factor);

}
