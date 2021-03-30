#include "ColorReader.h"
#include "Connection.h"
#include "ApiService.h"
#include "SocketHandler.h"

#define USE_SERIAL Serial

ColorReader colorReader(D4, D5, D6, D7, D8);
SocketHandler socketHandler;
ApiService apiService;

String lastColor = "";

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length)
{

  switch (type)
  {
  case WStype_DISCONNECTED:
    USE_SERIAL.printf("[WSc] Disconnected!\n");
    break;
  case WStype_CONNECTED:
  {
    USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

    // send message to server when Connected
    socketHandler.sendMsg("Connected");
  }
  break;
  case WStype_TEXT:
    USE_SERIAL.printf("[WSc] get text: %s\n", payload);

    // send message to server
    // webSocket.sendTXT("message here");
    break;
  case WStype_BIN:
    USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
    hexdump(payload, length);

    // send data to server
    // webSocket.sendBIN(payload, length);
    break;
  case WStype_PING:
    // pong will be send automatically
    USE_SERIAL.printf("[WSc] get ping\n");
    break;
  case WStype_PONG:
    // answer to a ping we send
    USE_SERIAL.printf("[WSc] get pong\n");
    break;
  }
}

void setup()
{
  Serial.begin(74880);

  Connection connection("Luiz Henrique 2G", "1998Luiz");
  int port = apiService.getServicePort();

  socketHandler.openConnection("safecrossing-api.herokuapp.com", 80, "/traffic-light");
  socketHandler.getSocket().onEvent(webSocketEvent);
}

void loop()
{
  socketHandler.loop();
  int color = colorReader.read();
  if (color == 1 && lastColor != "RED")
  {
    Serial.println("RED");
    lastColor = "RED";
    socketHandler.sendMsg("{\"trafficLightId\": 1, \"color\": \"RED\"}");
  }
  else if (color == 2 && lastColor != "YELLOW")
  {
    Serial.println("YELLOW");
    lastColor = "YELLOW";
    socketHandler.sendMsg("{\"trafficLightId\": 1, \"color\": \"YELLOW\"}");
  }
  else if (color == 3 && lastColor != "GREEN")
  {
    Serial.println("GREEN");
    lastColor = "GREEN";
    socketHandler.sendMsg("{\"trafficLightId\": 1, \"color\": \"GREEN\"}");
  }
  else
  {
    delay(100);
  }
}
