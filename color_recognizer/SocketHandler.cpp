/*
  SocketHandler.cpp - Library for handling websocket connection.
  Created by Luiz Henrique Naspolini, March 28, 2021.
  Released into the public domain.
*/

#include "SocketHandler.h"
#include <WebSocketsClient.h>
#define USE_SERIAL Serial

SocketHandler::SocketHandler(){}

WebSocketsClient SocketHandler::getSocket() {
  return socket;
}

void SocketHandler::openConnection(String url, int port, String path) {
  socket.begin(url, port, path);
  socket.setReconnectInterval(5000);
  socket.enableHeartbeat(15000, 3000, 2); 
}

void SocketHandler::sendMsg(String msg) {
  socket.sendTXT(msg);
};

void SocketHandler::loop() {
  socket.loop();
};
