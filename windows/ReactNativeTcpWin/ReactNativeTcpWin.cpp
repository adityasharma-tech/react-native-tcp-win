#include "pch.h"

#include "ReactNativeTcpWin.h"

namespace winrt::ReactNativeTcpWin
{

// See https://microsoft.github.io/react-native-windows/docs/native-modules for details on writing native modules

void ReactNativeTcpWin::Initialize(React::ReactContext const &reactContext) noexcept {
  m_context = reactContext;
}

double ReactNativeTcpWin::multiply(double a, double b) noexcept {
  return a * b;
}

} // namespace winrt::ReactNativeTcpWin