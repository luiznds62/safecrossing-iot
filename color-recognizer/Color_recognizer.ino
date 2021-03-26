#include <ColorReader.h>

ColorReader colorReader(D4,D5,D6,D7,D8);

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  string color = colorReader.read();
  Serial.print("COLOR: ");
  Serial.println(colorReader);
}
