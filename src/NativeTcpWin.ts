import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  multiply(a: number, b: number): number;
  add(a: number, b: number): number;
  /**
   * Initializes the TCP socket.
   * @returns 0 on success, 1 on failure.
   */
  InitializeTcpSocket(): number;

  /**
   * Connects to a TCP server using the provided IP address and port.
   * @param ipAddress - The IP address of the server.
   * @param port - The port to connect to.
   * @returns 0 on success, 1 on failure.
   */
  ConnectToServer(ipAddress: string, port: string): number;

  /**
   * Disconnects from the TCP server.
   * @returns 0 on success, 1 on failure.
   */
  DisconnectFromServer(): number;
}

export default TurboModuleRegistry.getEnforcing<Spec>('ReactNativeTcpWin');
