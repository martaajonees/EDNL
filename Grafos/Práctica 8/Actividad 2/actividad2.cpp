
template<typename tCoste>
struct Ciudad {
    Ciudad(tCoste x, tCoste y): x(x), y(y) {}
    tCoste x, y;
};

template<typename tCoste>
struct LineaAerea{
    LineaAerea(int x, int y, int distancia): x(x), y(y), distancia(distancia) {}
    int y, x;
    tCoste distancia;
};

//Encontrar las líneas aéreas necesarias
template<typename tCoste>
void tombuctu2(Grafo A, vector<Ciudad<tCoste> > ciudades){
    size_t n = A.numVert();
    Particion p(n);
    size_t numIslas = n;

    //Agrupo las ciudades
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] && p.encontrar(i) != p.encontrar(j)){
                numIslas --;
                p.unir(p.encontrar(i), p.encontrar(j));
            }
        }
    }
    //Necesito n* (n-1) / 2

    matriz<LineaAerea<tCoste> > vuelos(n);
    map<int, int > repre;
    int isla = 0; //Empezamos mapeando por 0
    for(int i = 0; i < numIslas; i++){ //Mapeo representantes
        if(repre.insert(make_pair(p.encontrar(i), isla)).second) isla++;
    }

    //Buscamos la mejor línea entre cada par de islas
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int isla1 = repre[p.encontrar(i)];
            int isla2 = repre[p.encontrar(j)];
            if(isla1 != isla2){ //Para distintas islas creamos vuelo
                tCoste distancia = sqrt(pow(ciudades[i].x- ciudades[j].x, 2) + pow(ciudades[i].y - ciudades[j].y, 2));
                if(distancia < vuelos[isla1][isla2].distancia) //Comparamos si la distancia entre estas dos islas es mínima
                    vuelos[isla1][isla2] = vuelos[isla2][isla1] = LineaAerea<tCoste>(i, j, distancia);
            }
        }
    }


    //Cojo de la matriz los vuelos y omito los valores nulos
    vector<LineaAerea<tCoste> >lineas(numIslas);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(vuelos[i][j] != 0){
                lineas.push_back(vuelos[i][j]);
            }
        }
    }

    return lineas

}
