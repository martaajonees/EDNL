
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
    vector<LineaAerea> lineas;
    matriz<bool> adecuada(N*N, false);
    Apo<LineaAerea> arbol(N * (N - 1) / 2);
    
    //Vector de representantes
    vector<int> representantes(N, -1);

    //Metemos todos los representantes
    for(int i = 0; i < N; i++){
        int rep = p.encontrar(i);
        if(rep == -1){
            representantes[rep] = i;
        }
    }

    //Vemos las líneas que se puedes crear y lo metemos en el apo
    for(vertice i = 0; i <= N-1; i++){
        for(vertice j = 0; j <= N-1; j++){
            int isla1 = p.encontrar(i);
            int isla2 = p.encontrar(j);
            if(isla1 != isla2){ //Distintas islas, necesitamos construir linea
                double dist = distancia(ciudades[i], ciudades[j]);
                LineaAerea linea(ciudades[i], ciudades[j], dist);
                arbol.insertar(linea); //Inserto línea en el apo
            }
        }
    }

    while(lineas.size() < (N * (N - 1) / 2)){ //Acabamos cuando tengamos las N * (N-1) / 2 ciudades
        LineaAerea linea = arbol.cima(); //El elemento en la cima es la de la distancia más corta
        arbol.suprimir(); //Elimino el apo en la cima

        int isla1 = p.encontrar(representantes[linea.a]); //Origen de la cima
        int isla2 = p.encontrar(representantes[linea.b]); //Destino

        //Vamos a la casilla de la matriz de booleanos
        if(!adecuada[isla1][isla2]){ //Si es true descartamos la cima, si es false
            lineas.push_back(linea); //Metemos la linea en el vector resultado
            adecuada[isla1][isla2] = true;
        }
    }

    return lineas;

}

double distancia(Ciudad a, Ciudad b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

