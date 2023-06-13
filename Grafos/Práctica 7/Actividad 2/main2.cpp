#include "actividad2.cpp"
#include "../Materiales Grafos/alg_grafo_E-S.h"

#include <iostream>
using namespace std;

int main() {
    int n = 5; // Tamaño del laberinto
    Casilla entrada = {0, 0}; // Casilla de entrada
    Casilla salida = {n-1, n-1}; // Casilla de salida
    
    vector<Pared> paredes;
    Pared pared1;
    pared1.a.fila = 0;
    pared1.a.colum = 1;
    pared1.b.fila = 1;
    pared1.b.colum = 1;
    paredes.push_back(pared1);

    Pared pared2;
    pared2.a.fila = 2;
    pared2.a.colum = 2;
    pared2.b.fila = 3;
    pared2.b.colum = 2;
    paredes.push_back(pared2);
    
    Pared pared3;
    pared3.a.fila = 3;
    pared3.a.colum = 1;
    pared3.b.fila = 4;
    pared3.b.colum = 1;
    paredes.push_back(pared3);
    
    vector<Casilla> camino = laberinto<int>(n, paredes, entrada, salida);

    if (camino.empty()) {
        cout << "No hay camino posible desde la entrada a la salida." << endl;
    } else {
        cout << "Camino más corto encontrado:" << endl;
        for (const Casilla& c : camino) {
            cout << "(" << c.fila << ", " << c.colum << ")" << endl;
        }
    }

    return 0;
}
