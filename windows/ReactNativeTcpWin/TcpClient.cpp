#include "TcpClient.h"
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

TcpClient::TcpClient() : m_socket(INVALID_SOCKET), m_isInitialized(false) {}

bool TcpClient::Initialize()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return false;
    }
    m_isInitialized = true;
    return true;
}

bool TcpClient::Connect(const std::string& ipAddress, const std::string& port)
{
    struct addrinfo* result = nullptr, hints = {};

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int iResult = getaddrinfo(ipAddress.c_str(), port.c_str(), &hints, &result);
    if (iResult != 0)
    {
        std::cerr << "getaddrinfo failed: " << iResult << std::endl;
        return false;
    }

    m_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (m_socket == INVALID_SOCKET)
    {
        std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        return false;
    }

    iResult = connect(m_socket, result->ai_addr, (int)result->ai_addrlen);
    freeaddrinfo(result);

    if (iResult == SOCKET_ERROR)
    {
        std::cerr << "Unable to connect to server: " << WSAGetLastError() << std::endl;
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
        return false;
    }

    return true;
}

int TcpClient::Send(const std::string& data)
{
    int iResult = send(m_socket, data.c_str(), (int)data.size(), 0);
    if (iResult == SOCKET_ERROR)
    {
        std::cerr << "Send failed: " << WSAGetLastError() << std::endl;
        return SOCKET_ERROR;
    }
    return iResult;
}

int TcpClient::Disconnect()
{
    if (m_socket != INVALID_SOCKET)
    {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
        return 0;
    }
    return 1;
}


TcpClient::~TcpClient()
{
    if (m_socket != INVALID_SOCKET)
    {
        closesocket(m_socket);
    }
    if (m_isInitialized)
    {
        WSACleanup();
    }
}