#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <complex>
#include <bitset>
#include "qiskit.hpp"

int main() {
    // Número para fatorar (altere para testar outros valores)
    int N = 15;
    
    // Verifica se N é par
    if (N % 2 == 0) {
        std::cout << "O número " << N << " é par." << std::endl;
        return 0;
    }

    // Verifica se N é primo usando a função is_prime do exemplo anterior
    // (ou utilize uma implementação mais robusta do Teste de Miller-Rabin)
    if (is_prime(N)) {
        std::cout << "O número " << N << " é primo." << std::endl;
        return 0;
    }

    // Define o número de qubits a serem utilizados no algoritmo
    int n_qubits = static_cast<int>(std::ceil(std::log2(N)));

    // Inicializa o registro quântico com n_qubits
    qiskit::QubitRegister reg(n_qubits);

    // Implementação do algoritmo de Shor usando Qiskit
    qiskit::QCircuit circuit(reg);

    // Preparação do estado superposto uniforme usando a transformada de Hadamard
    for (int i = 0; i < n_qubits; ++i) {
        circuit.h(i);
    }

    // Aplicação do operador modular (neste exemplo, ignorado)

    // Medição dos qubits e execução do circuito em um simulador quântico
    std::mt19937 generator(std::random_device{}());
    std::vector<int> measurements = qiskit::measure(circuit, reg, generator);

    // Converte a medição dos qubits para um número inteiro
    int measured_value = 0;
    for (int i = 0; i < n_qubits; ++i) {
        measured_value |= measurements[i] << i;
    }

    // Calcula o Máximo Divisor Comum (MDC) entre o valor medido e N
    int factor = gcd(measured_value, N);

    if (factor == 1 || factor == N) {
        std::cout << "O algoritmo de Shor falhou. Tente outro número." << std::endl;
    } else {
        std::cout << "Um fator não trivial de " << N << " é " << factor << std::endl;
    }

    return 0;
}
