//Author Jacob Waters
#include "VoltageDivider.h"
//lets see
int highSideResister = 990;//1K Ohm resister
int lowSideResister = 9950;//10K Ohm resister
double referenceVoltage = 3.3;
double errorFactor = 1.05; //implementation specific


VoltageDivider battery(990, 9950, A0, referenceVoltage, errorFactor);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  battery.getErrorFactor();
  delay(1000);

}
