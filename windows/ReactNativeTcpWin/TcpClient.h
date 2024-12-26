#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

class TcpClient
{
public:
    TcpClient();
    ~TcpClient();

    bool Initialize();
    bool Connect(const std::string& ipAddress, const std::string& port);
    int Send(const std::string& data);
    int Disconnect();

private:
    SOCKET m_socket;
    bool m_isInitialized;
};
