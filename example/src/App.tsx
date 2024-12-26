import React from 'react';
import { Text, View, StyleSheet } from 'react-native';
import { add, InitializeTcpSocket, ConnectToServer, DisconnectFromServer } from 'react-native-tcp-win';

const result = add(3, 7);

export default function App() {
  React.useEffect(()=>{
    const isInitialized = InitializeTcpSocket()
    if(isInitialized == 0) {
      const isConnected = ConnectToServer("192.168.234.169", "8002");
      console.log("isConnected:", isConnected)
      if(isConnected == 0){
        
      }
    }
    console.log("isInitialized:", isInitialized)
    return () => {
      DisconnectFromServer()
    }
  }, [])
  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});
