/*
  Connection.cpp - Library for connecting in WiFi with ESP8266 board.
  Created by Luiz Henrique Naspolini, March 27, 2021.
  Released into the public domain.
*/

#include "Connection.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;

Connection::Connection(char *ssid, char *password)
{
  if(WiFi.getMode() & WIFI_AP) {
        WiFi.softAPdisconnect(true);
    }

    WiFiMulti.addAP(ssid, password);

    //WiFi.disconnect();
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    String ip = WiFi.localIP().toString();
    Serial.printf("[SETUP] WiFi Connected %s\n", ip.c_str());
}
