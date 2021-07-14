/*
 * This class is designed to read coltage values above the maximum value arduino can read of 5V.
 * 
 */

#ifndef VoltageDivider_h
#define VoltageDivider_h

#include "Arduino.h"

class VoltageDivider
{
	public:
		VoltageDivider(uint32_t r1, uint32_t r2, uint8_t pin);
		double getVoltage();
    
	private:
		uint32_t resister1, resister2;//R1 on high voltage side, R2 on low voltage side
		uint8_t pinNumber;
		double correctionFactor;
};

#endif
