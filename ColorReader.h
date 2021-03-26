#ifndef Color_Reader_h
#define Color_Reader_h

#include <Arduino.h>

class ColorReader
{
public:
    ColorReader(int S0, int S1, int S2, int S3, int sensorOut);
    string read();

private:
    int S0_;
    int S1_;
    int S2_;
    int S3_;
    int sensorOut_;

    int redFrequency = 0;
    int greenFrequency = 0;
    int blueFrequency = 0;

    const std::string RED_COLOR = "RED";
    const std::string GREEN_COLOR = "GREEN";
    const std::string YELLOW_COLOR = "YELLOW";
};
#endif