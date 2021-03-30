/*
  ColorReader.cpp - Library for read colors from TCS3200 sensor.
  Created by Luiz Henrique Naspolini, March 25, 2021.
  Released into the public domain.
*/

#include "ColorReader.h"

ColorReader::ColorReader(int S0, int S1, int S2, int S3, int sensorOut)
{
    S0_ = S0;
    S1_ = S1;
    S2_ = S2;
    S3_ = S3;
    sensorOut_ = sensorOut;

    pinMode(S0_, OUTPUT);
    pinMode(S1_, OUTPUT);
    pinMode(S2_, OUTPUT);
    pinMode(S3_, OUTPUT);
    pinMode(sensorOut_, INPUT);

    digitalWrite(S0_, HIGH);
    digitalWrite(S1_, LOW);

    Serial.println("Class ready to read colors");
}

bool ColorReader::enableLogging()
{
    isLoggingEnabled = true;
}

void ColorReader::log(int value)
{
    if (isLoggingEnabled)
    {
        Serial.print(value);
    }
}

void ColorReader::log(char *message)
{
    if (isLoggingEnabled)
    {
        Serial.print(message);
    }
}

int ColorReader::read()
{
    digitalWrite(S2_, LOW);
    digitalWrite(S3_, LOW);
    redFrequency = pulseIn(sensorOut_, LOW);
    log("R = ");
    log(redFrequency);
    delay(frequencyReaderDelay);
    digitalWrite(S2_, HIGH);
    digitalWrite(S3_, HIGH);
    greenFrequency = pulseIn(sensorOut_, LOW);
    log(" G = ");
    log(greenFrequency);
    delay(frequencyReaderDelay);
    digitalWrite(S2_, LOW);
    digitalWrite(S3_, HIGH);
    blueFrequency = pulseIn(sensorOut_, LOW);
    log(" B = ");
    log(blueFrequency);
    delay(frequencyReaderDelay);

    if (redFrequency >= 7 && redFrequency <= 183 && greenFrequency >= 124 && greenFrequency <= 258)
    {
        return RED;
    }
    else if (redFrequency >= 60 && redFrequency <= 164 && greenFrequency >= 4 && greenFrequency <= 116 && blueFrequency >= 31 && blueFrequency <= 110)
    {
        return GREEN;
    }
    else if (redFrequency >= 5 && redFrequency <= 43 && greenFrequency >= 7 && greenFrequency <= 65 && blueFrequency >= 21 && blueFrequency <= 133)
    {
        return YELLOW;
    }
}
