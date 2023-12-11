#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip> // Para std::fixed e std::setprecision
#include <fstream> // Para salvar em arquivos
#include <complex>

using namespace std;
//using complex = std::complex<double>;

std::complex<double> phi(int n, double r, double lambda, double a) {
    const std::complex<double> i(0, 1); 
    const double alpha = 1.0; // Parâmetro que pode ser ajustado

    // Termo que diminui com a distância ao núcleo
    std::complex<double> radialPart = exp(-alpha * r * r);

    // Termo que varia com o índice n (pode representar, por exemplo, diferentes orbitais atômicos)
    std::complex<double> angularPart = sin(n * M_PI * r);

    // Combinação dos termos
    return radialPart * angularPart;
}


// // Função phi atualizada para retornar um std::complex<double>
// std::complex<double> phi(int n, double x, double lambda, double a) {
//     const std::complex<double> i(0, 1); // Unidade imaginária

//     std::complex<double> term1 = std::exp(i * x); // Primeiro termo
//     std::complex<double> term2 = std::exp(2.0 * i - 5.0 * a) * (std::exp(4.0 * a) - std::exp(8.0 * i));
//     std::complex<double> term3 = x * (a - 2.0 * i);
//     std::complex<double> term4 = 1.0 + lambda * (std::exp(i - a) - std::exp(5.0 * i - a)); // Incluir a função Ei adequada

//     return term1 + (lambda * term2 / term3) / term4;
// }

// // Definição de uma função de onda de um único elétron (por exemplo, uma função de onda de orbital atômico)
// double phi(int n, double x) {
//     // Para simplificar, usamos uma função de onda gaussiana modificada com um parâmetro 'n'
//     const double alpha = 1.0; // Parâmetro variacional
//     return exp(-alpha * x * x) * std::sin(n * M_PI * x) * std::cos(n * M_PI * x);
// }

// Constrói a matriz de Slater para um sistema de N partículas
Eigen::MatrixXcd buildSlaterMatrix(const std::vector<double>& positions, double lambda, double a) {
    int N = positions.size();
    Eigen::MatrixXcd slaterMatrix(N, N); // Matriz de números complexos

    for (int n = 0; n < N; ++n) {
        for (int j = 0; j < N; ++j) {
            slaterMatrix(n, j) = phi(n + 1, positions[j], lambda, a);
        }
    }
    return slaterMatrix;
}


// Corrigir a declaração para usar std::complex<double> explicitamente
void printMatrixToLatex(const Eigen::MatrixXcd& matrix, const string& filename, const std::complex<double>& det) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "\\begin{bmatrix}\n";
        for (int i = 0; i < matrix.rows(); ++i) {
            for (int j = 0; j < matrix.cols(); ++j) {
                file << matrix(i, j).real(); // Apenas a parte real
                if (j < matrix.cols() - 1) file << " & ";
            }
            file << " \\\\" << endl; // Final de linha no LaTeX
        }
        file << "\\end{bmatrix}\n";
        file << "\\text{Determinante: " << det.real() << " + " << det.imag() << "i}" << endl; // Formatação do número complexo
    }
    file.close();
}


int main() {

  	const int N = 5; // Número de partículas
  	// Definir parâmetros e posicões das partículas
    vector<double> positions(N, 0.0);
    double lambda = -0.5; // Exemplo de valor para lambda
    double a = 1.0; // Exemplo de valor para a
   
    
    // Inicializar o gerador de números aleatórios
    srand(std::time(0));

    // Gerar posições aleatórias para cada partícula
    for (int i = 0; i < N; ++i) {
        positions[i] = static_cast<double>(rand()) / RAND_MAX; // Posições aleatórias entre 0 e 1
    }

    // Construir a matriz de Slater
    Eigen::MatrixXcd slaterMatrix = buildSlaterMatrix(positions, lambda, a);

	// Imprimir a matriz de Slater
	cout << "Matriz de Slater:" << endl;
	cout << fixed << setprecision(3); // Limita a 5 casas decimais, por exemplo
	for (int i = 0; i < slaterMatrix.rows(); ++i) {
	  for (int j = 0; j < slaterMatrix.cols(); ++j) {
        cout << slaterMatrix(i, j) << "\t";
	  }
	  cout << endl; // Nova linha após cada linha da matriz
	}
    
    // Calcular o determinante da matriz de Slater
	std::complex<double> det = slaterMatrix.determinant();

	
    // Imprimir o resultado
    cout << "Determinante da matriz de Slater para " << N << " partículas: " << det << endl;

	// Imprimir o Latex para um arquivo .tex
	printMatrixToLatex(slaterMatrix, "slaterMatrix.tex", det);
    
    return 0;
}
