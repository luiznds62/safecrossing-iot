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
}

string ColorReader::read()
{
    digitalWrite(S2_, LOW);
    digitalWrite(S3_, LOW);
    redFrequency = pulseIn(sensorOut_, LOW);
    Serial.print("R = ");
    Serial.print(redFrequency);
    delay(100);
    digitalWrite(S2_, HIGH);
    digitalWrite(S3_, HIGH);
    greenFrequency = pulseIn(sensorOut_, LOW);
    Serial.print(" G = ");
    Serial.print(greenFrequency);
    delay(100);
    digitalWrite(S2_, LOW);
    digitalWrite(S3_, HIGH);
    blueFrequency = pulseIn(sensorOut_, LOW);
    Serial.print(" B = ");
    Serial.println(blueFrequency);
    delay(100);

    if (redFrequency >= 11 && redFrequency <= 24 && greenFrequency >= 158 && greenFrequency <= 235)
    {
        return RED_COLOR;
    }
    else if (greenFrequency >= 31 && greenFrequency <= 49 && blueFrequency >= 31 && blueFrequency <= 102)
    {
        return GREEN_COLOR;
    }
    else if (redFrequency >= 14 && redFrequency <= 23 && greenFrequency >= 29 && greenFrequency <= 50 && blueFrequency >= 46 && blueFrequency <= 74)
    {
        return YELLOW_COLOR;
    }
}