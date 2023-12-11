#include "QuantumGates.h"

namespace QuantumGates {

Matrix2cd hadamardGate() {
    // Matriz de Hadamard
    Matrix2cd h;
    h << 1.0 / sqrt(2.0), 1.0 / sqrt(2.0),
         1.0 / sqrt(2.0), -1.0 / sqrt(2.0);
    return h;
}

Matrix2cd pauliXGate() {
    // Matriz Pauli-X (NOT Gate)
    Matrix2cd x;
    x << 0.0, 1.0,
         1.0, 0.0;
    return x;
}

Matrix2cd pauliYGate() {
    // Matriz Pauli-Y
    Matrix2cd y;
    y << 0.0, -1.0i,
         1.0i, 0.0;
    return y;
}

Matrix2cd pauliZGate() {
    // Matriz Pauli-Z
    Matrix2cd z;
    z << 1.0, 0.0,
         0.0, -1.0;
    return z;
}

Matrix2cd sGate() {
    // Matriz S (quadrado da raiz da matriz Z)
    Matrix2cd s;
    s << 1.0, 0.0,
         0.0, 1.0i;
    return s;
}

Matrix2cd sDaggerGate() {
    // Matriz S-Dagger (conjugado transposto da matriz S)
    return sGate().adjoint();
}

Matrix4cd toffoliGate() {
    // Matriz de Toffoli (CCNOT Gate)
    Matrix4cd toffoli;
    toffoli << 1.0, 0.0, 0.0, 0.0,
               0.0, 1.0, 0.0, 0.0,
               0.0, 0.0, 1.0, 0.0,
               0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0;
    return toffoli;
}

Matrix4cd fredkinGate() {
    // Matriz de Fredkin (CSWAP Gate)
    Matrix4cd fredkin;
    fredkin << 1.0, 0.0, 0.0, 0.0,
               0.0, 1.0, 0.0, 0.0,
               0.0, 0.0, 0.0, 1.0,
               0.0, 0.0, 1.0, 0.0;
    return fredkin;
}

 
// Adicionarei mais implementações de portas lógicas conforme necessário
Matrix4cd qSwapGate() {
    Matrix4cd qSwap;
    qSwap << 1, 0, 0, 0,
             0, 0, 1, 0,
             0, 1, 0, 0,
             0, 0, 0, 1;
    return qSwap;
}

  
} // namespace QuantumGates
