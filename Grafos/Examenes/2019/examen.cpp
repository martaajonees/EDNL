struct LineaAerea {
    LineaAerea(Ciudad x, Ciudad y, double coste): a{x}, b{y}, distancia{coste}{}
    Ciudad a, b;
    double distancia;
};
struct Ciudad {
    int x,y;
};

template<typename tCoste>
void tombuctu2(Grafo A, vector<Ciudad> ciudades){
    typedef typename GrafoP<tCoste>::vertice vertice;
    //Creamos un tad particion
    Particion p;
    // Nº de islas
    size_t N = ciudades.size();
    //Recorremos la matriz de adyascencia
    for(int i = 0; i < ciudades.size(); i++){
        for(int j = 0; j < ciudades.size(); j++){
            if(A[i][j]){ //Si es adyascente, hay camino directo: Misma Isla
                if(p.encontrar(i) != p.encontrar(j)){ //Misma isla
                    p.unir(p.encontrar(i), p.encontrar(j));
                    N--; //Para calcular el nº de islas
                }
            }
        }
    }

    //Vemos lineas aereas más cortas entre islas y la ponemos en matriz
    matriz<LineaAerea> lineas;
    //para optimizar podemos mapear
    map<int, int> opt;
    int cont = 0;
    for(int i = 0; i < N; i++){ //Asignamos 
        if(opt.insert(make_pair(p.encontrar(i), cont)).second) cont ++;
    }

    for(vertice i = 0; i <= N-1; i++){
        for(vertice j = 0; j <= N-1; j++){
            int isla1 = opt[p.encontrar(i)];
            int isla2 = opt[p.encontrar(j)];
            if(isla1 != isla2){ //Distintas islas, necesitamos construir linea
                double dist = distancia(ciudades[i], ciudades[j]);
                if(dist < lineas[isla1][isla2]){ //Si esa distancia es menor que una guardada
                    lineas[isla1][isla2] = lineas[isla2][isla1] = LineaAerea(ciudades[i], ciudades[j], dist);
                }
            }
        }
    }

    return lineas;

}

double distancia(Ciudad a, Ciudad b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
