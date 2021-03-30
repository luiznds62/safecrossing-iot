#include "ColorReader.h"
#include "Connection.h"
#include "ApiService.h"
#include "SocketHandler.h"

#define USE_SERIAL Serial

ColorReader colorReader(D4, D5, D6, D7, D8);
SocketHandler socketHandler;
ApiService apiService;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

  switch(type) {
    case WStype_DISCONNECTED:
      USE_SERIAL.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED: {
      USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

      // send message to server when Connected
      socketHandler.getSocket().sendTXT("Connected");
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

  Connection connection("Luiz Henrique 2G","1998Luiz");
  String token = apiService.auth("admin@admin.com", "123456");
  Serial.println(token);

  socketHandler.openConnection("192.168.0.117", 3000, "/traffic-light");
  socketHandler.getSocket().onEvent(webSocketEvent);
}

void loop()
{
  socketHandler.loop();
  delay(10000);
  socketHandler.sendMsg("{\"trafficLightId\": 1, \"color\": \"GREEN\"}");
  // int color = colorReader.read();
  // if (color == 1)
  // {
  //   Serial.println("RED");
  // }
  // else if (color == 2)
  // {
  //   Serial.println("YELLOW");
  // }
  // else if (color == 3)
  // {
  //   Serial.println("GREEN");
  // }
}
