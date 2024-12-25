#include <jni.h>
#include "react-native-tcp-win.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_tcpwin_TcpWinModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return tcpwin::multiply(a, b);
}
