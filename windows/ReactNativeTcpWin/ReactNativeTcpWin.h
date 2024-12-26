#pragma once

#include "pch.h"
#include "resource.h"

#if __has_include("codegen/NativeReactNativeTcpWinDataTypes.g.h")
  #include "codegen/NativeReactNativeTcpWinDataTypes.g.h"
#endif
#include "codegen/NativeTcpWinSpec.g.h"

#include "NativeModules.h"

namespace winrt::ReactNativeTcpWin
{

REACT_MODULE(ReactNativeTcpWin)
struct ReactNativeTcpWin
{
  using ModuleSpec = ReactNativeTcpWinCodegen::TcpWinSpec;

  REACT_INIT(Initialize)
  void Initialize(React::ReactContext const &reactContext) noexcept;

  REACT_SYNC_METHOD(multiply)
  double multiply(double a, double b) noexcept;

  REACT_SYNC_METHOD(add)
  double add(double a, double b) noexcept;

  REACT_SYNC_METHOD(InitializeTcpSocket)
  int InitializeTcpSocket () noexcept;

  REACT_SYNC_METHOD(ConnectToServer)
  int ConnectToServer(std::string ipAddress, std::string port) noexcept;

  REACT_SYNC_METHOD(SendMessage)
  int SendMessage(std::string message) noexcept;

  REACT_SYNC_METHOD(DisconnectFromServer)
  int DisconnectFromServer() noexcept;

private:
  React::ReactContext m_context;
};

} // namespace winrt::ReactNativeTcpWin