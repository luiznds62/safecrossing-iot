#ifndef API_SERVICE_H
#define API_SERVICE_H

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

class ApiService
{
public:
    ApiService();
    String auth(String email, String password);
    int getServicePort();
private:
    WiFiClient client;
    HTTPClient http;

    String accessToken = "";
    String tokenPrefix = "Bearer ";
    const String baseUrl = "http://safecrossing-api.herokuapp.com";
    const int DEVICE_ID = 1;
};
#endif
