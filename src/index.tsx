import TcpWin from './NativeTcpWin';

export function multiply(a: number, b: number): number {
  return TcpWin.multiply(a, b);
}

export function add(a: number, b: number): number {
  return TcpWin.add(a, b);
}