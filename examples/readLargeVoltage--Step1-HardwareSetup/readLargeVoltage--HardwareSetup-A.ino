
//These lines added for platformIO compatibility
#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef VoltageDivider_h
#include "VoltageDivider.h"
#endif



/*
Sometimes we find outselves needing to read voltages 
much larger than our microcontroller can safely ready
(typically 3.3V or 5V).

A simple solution is to build a voltage divider with
a circuit as follows:

    (referenceVoltage) -> R1 -> AnalogReadPin -> R2 -> GND

If R1 is 10x bigger than R2, then we get roughly a 10x
reduction in voltage, allowing possible a maximum read 
voltage of 50V for a 5V referenceVoltage.

What is the referenceVoltage of our microcontroller?
*/
double vRef = 5.0;

/*
We need the sum of our resisters to equal some value,
small enough so there isn't much noise on our ADC read,
but large enough so we aren't dissapating much heat or frying
the board. 10K Ohms is the recommended value for Arduino boards.
*/
double totalR = 10000;

/*
Now, what is the maximum voltage you'll be reading? 
Realize the larger this number is, the lower resultion
you'll effectively get from your ADC read.

REMEMBER TO MAKE THIS BIGGER THAN YOU NEED TO PREVENT HARDWARE DAMAGE
*/
double vMax = 14.4+6; //14.4V for a car battery and a 6V tolerance


double R2Recommended = (vRef*totalR)/vMax;
double R1Recommended = totalR * (1 - (vRef/vMax));



void setup() {
    Serial.begin(115200);

    /*
    However, since you probably don't have exact resister values listed
    above, if you must make one larger/smaller, make R1 larger
    and/or make R2 smaller. This ensures you don't accidentally
    make the voltage drop insufficient to protect your micro. 
    YOU CAN FRY YOUR DEVICE IF YOU SCREW THIS UP.
    */

}

void loop() {

    Serial.print("Based on your specifications, I recommend ");
    Serial.print(R1Recommended);
    Serial.print(" Ohms for R1, and ");
    Serial.print(R2Recommended); 
    Serial.println(" Ohms for R2.\n");
    delay(2000);
}
