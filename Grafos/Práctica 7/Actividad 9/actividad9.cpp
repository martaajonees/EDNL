template<typename tCoste>
void camino_minimo(GrafoP<tCoste> Tren, GrafoP<tCoste> Bus, typename GrafoP<tCoste>::vertice origen, 
    typename GrafoP<tCoste>::vertice destino, tCoste taxi){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = Tren.numVert();
    
    //inicializo el supergrafo
    GrafoP<tCoste> SG(n * 2);
    for(vertice i = 0; i < n; i++){
        for(vertice j = 0; j < n; j++){
            SG[i][j] = Tren[i][j];
            SG[i+n][j+n] = Bus[i][j];
        }
    }
    //inicializo taxis
    
    for(vertice i = 0; i < 2 * n; i++){
        for(vertice j = 0; j < 2 * n; j++){
            if(i != j){
                if(i%n == j) SG[i][j] = taxi;
                else if(j%n == i) SG[i][j] = taxi;
            }
        }
    }
    
    //Hacemos Dijkstra para el coste de buses y el coste de trenes
    vector<vertice> Ptren(2*n);
    vector<tCoste> Dtren(2*n);
    Dtren = Dijkstra(SG, origen, Ptren);
    //cout<<Dtren;
    vector<vertice> Pbus(2*n);
    vector<tCoste> Dbus(2*n);
    Dbus = Dijkstra(SG, origen + n, Ptren);
    //cout<< Dbus;

    tCoste minim = min(Dtren[destino], min(Dtren[destino + n], min(Dbus[destino], Dbus[destino+n])));

    if(minim == Dtren[destino]){
        cout << "El camino más corto es: " << camino<tCoste>(origen, destino, Ptren) << endl;
        cout << "El coste es: " << minim;
    } else if(minim == Dtren[destino + n]){
        cout << "El camino más corto es: " << camino<tCoste>(origen, destino+n, Ptren)<< endl;
        cout << "El coste es: " << minim;
    } else if(minim == Dbus[destino]){
        cout << "El camino más corto es: " << camino<tCoste>(origen+n, destino, Pbus)<< endl;
        cout << "El coste es: " << minim;
    } else if(minim == Dbus[destino]){
        cout << "El camino más corto es: " << camino<tCoste>(origen+n, destino + n, Pbus)<< endl;
        cout << "El coste es: " << minim;
    }

}
