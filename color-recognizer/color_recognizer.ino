#include "ColorReader.h"
#include <string>

ColorReader colorReader(D4, D5, D6, D7, D8);

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int color = colorReader.read();
  if (color == 1)
  {
    Serial.println("RED");
  }
  else if (color == 2)
  {
    Serial.println("YELLOW");
  }
  else if (color == 3)
  {
    Serial.println("GREEN");
  }
}
