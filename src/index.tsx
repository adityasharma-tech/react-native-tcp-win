import TcpWin from './NativeTcpWin';

/**
 * Multiplies two numbers using the native module.
 * @param a - The first number.
 * @param b - The second number.
 * @returns The product of `a` and `b`.
 */
export function multiply(a: number, b: number): number {
  return TcpWin.multiply(a, b);
}

/**
 * Adds two numbers using the native module.
 * @param a - The first number.
 * @param b - The second number.
 * @returns The sum of `a` and `b`.
 */
export function add(a: number, b: number): number {
  return TcpWin.add(a, b);
}

/**
 * Initializes the TCP socket.
 * @returns 0 on success, 1 on failure.
 */
export function InitializeTcpSocket(): number {
  return TcpWin.InitializeTcpSocket();
}

/**
 * Connects to a server using the provided IP address and port.
 * @param ipAddress - The server's IP address.
 * @param port - The server's port.
 * @returns 0 on success, 1 on failure.
 */
export function ConnectToServer(ipAddress: string, port: string): number {
  return TcpWin.ConnectToServer(ipAddress, port);
}

/**
 * Disconnects from the server.
 * @returns 0 on success, 1 on failure.
 */
export function DisconnectFromServer(): number {
  return TcpWin.DisconnectFromServer();
}
