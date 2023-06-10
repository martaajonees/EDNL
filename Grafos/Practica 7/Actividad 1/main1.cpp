#include "alg_grafo_E-S.h"
#include "actividad1.cpp"
int main() {
    typedef int tCoste;  // Puedes cambiar el tipo de dato según tus necesidades

    // Crear un grafo de ejemplo
    GrafoP<tCoste> grafo(4);
    grafo[0][1] = 5;
    grafo[0][2] = 3;
    grafo[1][2] = 1;
    grafo[1][3] = 2;
    grafo[2][3] = 4;
    grafo[3][0] = 1;

    cout << grafo << endl;
    Viaje<tCoste> viaje = otravezungrafo(grafo);

    std::cout << "Viaje máximo" << std::endl;
    std::cout << "\t Origen: " << viaje.origen << std::endl;
    std::cout << "\t Destino: " << viaje.destino << std::endl;
    std::cout << "\t Coste máximo: " << viaje.Coste << std::endl;

    return 0;
}
