#include "../Materiales Grafos/alg_grafo_E-S.h"
#include "actividad4.cpp"
#include <iostream>

int main() {
    // Crear un grafo de ejemplo
    GrafoP<double> grafo(5); // Supongamos un grafo con 5 vértices

    // Agregar aristas al grafo
    grafo[0][1] = 10.0;
    grafo[1][0] = 10.0;
    grafo[0][2] = 5.0;
    grafo[2][0] = 5.0;
    grafo[1][2] = 3.0;
    grafo[2][1] = 3.0;
    grafo[1][3] = 2.0;
    grafo[3][1] = 2.0;
    grafo[2][3] = 9.0;
    grafo[3][2] = 9.0;
    grafo[2][4] = 7.0;
    grafo[4][2] = 7.0;
    grafo[3][4] = 1.0;
    grafo[4][3] = 1.0;

    // Definir los datos de las ciudades
    std::vector<Parte> trabajos;
    trabajos.push_back(Parte(3,1));
    trabajos.push_back(Parte(2,2));
    trabajos.push_back(Parte(1,3));
    trabajos.push_back(Parte(7,4));

    // Llamar a la función empresa
    cout << cementos(grafo, 4, trabajos);

}
