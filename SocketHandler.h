#ifndef SOCKET_HANDLER_H
#define SOCKET_HANDLER_H

#include <Arduino.h>
#include <WebSocketsClient.h>
#include <Hash.h>

class SocketHandler
{
public:
    SocketHandler();
    WebSocketsClient getSocket();
    void openConnection(String url, int port, String path);
    void sendMsg(String message);
    void loop();
private:
    WebSocketsClient socket;
};
#endif
