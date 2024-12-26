#include "pch.h"

#include "ReactNativeTcpWin.h"
#include "TcpClient.cpp"

namespace winrt::ReactNativeTcpWin
{

  TcpClient client;

  // See https://microsoft.github.io/react-native-windows/docs/native-modules for details on writing native modules

  void ReactNativeTcpWin::Initialize(React::ReactContext const &reactContext) noexcept
  {
    m_context = reactContext;
  }

  double ReactNativeTcpWin::multiply(double a, double b) noexcept
  {
    return a * b;
  }

  double ReactNativeTcpWin::add(double a, double b) noexcept
  {
    return a + b;
  }

  int ReactNativeTcpWin::InitializeTcpSocket() noexcept
  {
    if(!client.Initialize()){
      return 1;
    }
    return 0;
  }

  int ReactNativeTcpWin::ConnectToServer(std::string ipAddress, std::string port) noexcept {
    if(!client.Connect(ipAddress, port)){
      return 1;
    }
    return 0;
  }

  int ReactNativeTcpWin::SendMessage(std::string message) noexcept {
    return client.Send(message);
  }

  int ReactNativeTcpWin::DisconnectFromServer() noexcept {
    client.Disconnect();
    return 0;
  }
  

} // namespace winrt::ReactNativeTcpWin