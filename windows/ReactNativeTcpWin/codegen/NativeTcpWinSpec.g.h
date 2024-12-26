
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off


#include <NativeModules.h>
#include <tuple>

namespace ReactNativeTcpWinCodegen {

struct TcpWinSpec : winrt::Microsoft::ReactNative::TurboModuleSpec {
  static constexpr auto methods = std::tuple{
      SyncMethod<double(double, double) noexcept>{0, L"multiply"},
      SyncMethod<double(double, double) noexcept>{1, L"add"},
      SyncMethod<double() noexcept>{2, L"InitializeTcpSocket"},
      SyncMethod<double(std::string, std::string) noexcept>{3, L"ConnectToServer"},
      SyncMethod<double() noexcept>{4, L"DisconnectFromServer"},
  };

  template <class TModule>
  static constexpr void ValidateModule() noexcept {
    constexpr auto methodCheckResults = CheckMethods<TModule, TcpWinSpec>();

    REACT_SHOW_METHOD_SPEC_ERRORS(
          0,
          "multiply",
          "    REACT_SYNC_METHOD(multiply) double multiply(double a, double b) noexcept { /* implementation */ }\n"
          "    REACT_SYNC_METHOD(multiply) static double multiply(double a, double b) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          1,
          "add",
          "    REACT_SYNC_METHOD(add) double add(double a, double b) noexcept { /* implementation */ }\n"
          "    REACT_SYNC_METHOD(add) static double add(double a, double b) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          2,
          "InitializeTcpSocket",
          "    REACT_SYNC_METHOD(InitializeTcpSocket) double InitializeTcpSocket() noexcept { /* implementation */ }\n"
          "    REACT_SYNC_METHOD(InitializeTcpSocket) static double InitializeTcpSocket() noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          3,
          "ConnectToServer",
          "    REACT_SYNC_METHOD(ConnectToServer) double ConnectToServer(std::string ipAddress, std::string port) noexcept { /* implementation */ }\n"
          "    REACT_SYNC_METHOD(ConnectToServer) static double ConnectToServer(std::string ipAddress, std::string port) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          4,
          "DisconnectFromServer",
          "    REACT_SYNC_METHOD(DisconnectFromServer) double DisconnectFromServer() noexcept { /* implementation */ }\n"
          "    REACT_SYNC_METHOD(DisconnectFromServer) static double DisconnectFromServer() noexcept { /* implementation */ }\n");
  }
};

} // namespace ReactNativeTcpWinCodegen
