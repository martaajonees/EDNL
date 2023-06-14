int main() {
    int numCiudades = 4;

    // Crear los grafos de costos para cada medio de transporte
    GrafoP<int> bus(numCiudades);
    GrafoP<int> tren(numCiudades);

    // Rellenar los grafos de costos con los valores correspondientes

    // Rellenar el grafo de costos en bus
    bus[0][1] = 2;
    bus[0][2] = 2;
    bus[1][0] = 2;
    bus[1][3] = 1;
    bus[2][0] = 2;
    bus[2][3] = 3;
    bus[3][1] = 1;
    bus[3][2] = 3;

    // Rellenar el grafo de costos en tren
    tren[0][1] = 1;
    tren[0][2] = 3;
    tren[1][0] = 1;
    tren[1][3] = 4;
    tren[2][0] = 3;
    tren[2][3] = 2;
    tren[3][1] = 4;
    tren[3][2] = 2;

    // Rellenar el grafo de costos en avion


    GrafoP<int>::vertice transbordo = 1;  // Ciudad de origen del viajero


    /// Ejemplo de uso de la función "viajero" con los grafos de costos creados
    matriz<int> c = tarifa_minima(bus, tren, transbordo);

    // Imprimir las ciudades alcanzables
     cout << "Resultado\n"<< c;

    return 0;
}
