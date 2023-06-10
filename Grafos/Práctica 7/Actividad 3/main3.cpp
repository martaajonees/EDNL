#include "../Materiales Grafos/alg_grafo_E-S.h"
#include "actividad3.cpp"

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
   std::vector<Ciudad> ciudades;
    ciudades.push_back(Ciudad(20.0, 2));
    ciudades.push_back(Ciudad(45.0, 1));
    ciudades.push_back(Ciudad(0.0, 1));
    ciudades.push_back(Ciudad(30.0, 1));
    ciudades.push_back(Ciudad(18.0, 5));

    // Llamar a la función empresa
    vector<double> result = empresa(grafo, 0, 6, ciudades);
    for (double value : result) {
        cout << value << "\t ";
    }

    }
