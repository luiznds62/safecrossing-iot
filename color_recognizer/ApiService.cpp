/*
  ApiService.cpp - HTTP Handler for SafeCrossing-Api.
  Created by Luiz Henrique Naspolini, March 27, 2021.
  Released into the public domain.
*/

#include "ApiService.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <Arduino.h>

ApiService::ApiService(){};

String ApiService::auth(String email, String password)
{
    Serial.println("Starting auth process");
    String payload;
    String body;

    http.begin(baseUrl + "/auth");
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<96> doc;
    doc["email"] = email;
    doc["password"] = password;
    serializeJson(doc, body);

    Serial.print(body);
    Serial.println();

    int httpResponseCode = http.POST(body);

    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    http.end();

    Serial.println(payload);

    StaticJsonDocument<384> responseDoc;
    DeserializationError error = deserializeJson(responseDoc, payload);

    if (error)
    {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
    }

    String token = responseDoc["accessToken"];
    accessToken = tokenPrefix + token;
    return accessToken;
}
