#include <iostream>
#include "xacc.hpp"

int main() {
    // Inicialize o framework XACC
    xacc::Initialize();

    // Crie um buffer quântico com 2 qubits
    auto buffer = xacc::qalloc(2);

    // Crie um circuito quântico simples
    xacc::qasm("H 0\nCNOT 0 1", buffer);

    // Execute o circuito no simulador quântico
    xacc::qasm("qpp", buffer);

    // Obtenha as probabilidades dos estados quânticos
    auto probs = buffer->getProbabilities();

    // Imprima as probabilidades
    std::cout << "Probabilidades dos estados quânticos:";
    for (const auto& prob : probs) {
        std::cout << " " << prob;
    }
    std::cout << std::endl;

    // Finalize o framework XACC
    xacc::Finalize();

    return 0;
}
