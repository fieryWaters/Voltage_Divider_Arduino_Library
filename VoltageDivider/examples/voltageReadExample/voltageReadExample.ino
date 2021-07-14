#include "VoltageDivider.h"

VoltageDivider battery(5160,10320,A0);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(battery.getVoltage());
  delay(1000);

}
