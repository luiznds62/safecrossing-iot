#ifndef COLOR_READER_H
#define COLOR_READER_H

#include <Arduino.h>

class ColorReader
{
public:
    enum Colors
    {
        RED = 1,
        YELLOW = 2,
        GREEN = 3
    };

    ColorReader(int S0, int S1, int S2, int S3, int sensorOut);
    bool enableLogging();
    void log(int value);
    void log(char *message);
    int read();

private:
    int S0_;
    int S1_;
    int S2_;
    int S3_;
    int sensorOut_;

    bool isLoggingEnabled = false;

    int redFrequency = 0;
    int greenFrequency = 0;
    int blueFrequency = 0;

    const int frequencyReaderDelay = 250;
};
#endif
