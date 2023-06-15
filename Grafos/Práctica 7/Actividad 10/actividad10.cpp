template<typename tCoste>
void camino_minimo(GrafoP<tCoste> Bus, GrafoP<tCoste> Tren, GrafoP<tCoste> Avion, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
tCoste tren_bus, tCoste aer_tren){
    size_t n = Bus.numVert();
    typedef typename GrafoP<tCoste>::vertice vertice;

    //Hacemos super grafo de 3 * n
    GrafoP<tCoste> SG(n * 3);

    //Inicializamos super grafo
    //Grafos Tren-Bus_Avion en la diagonal del supergrafo
    for(vertice i = 0; i < n ; i ++){
        for(vertice j = 0; j < n ; j++){
            SG[i][j] = Tren[i][j];
            SG[i+n][j+n] = Bus[i][j];
            SG[i+n+n][j+n+n] = Avion[i][j];
        }
    }
    //Inicializamos costes
 
      for (vertice i = 0; i < n; i++) {
        SG[i][i + n] = tren_bus;
        SG[i+n][i] = tren_bus;
        SG[i+n][i+n+n] = aer_tren;
        SG[i][i + n + n] = aer_tren;
        SG[i + n + n][i] = aer_tren;
        SG[i + n + n][i + n] = tren_bus;
    }

    //Hacemos Dijkstra para el coste de buses, el coste de trenes y el de aviones
    vector<vertice> Ptren(2*n);
    vector<tCoste> Dtren(2*n);
    Dtren = Dijkstra(SG, origen, Ptren);
    //cout<<Dtren;
    vector<vertice> Pbus(2*n);
    vector<tCoste> Dbus(2*n);
    Dbus = Dijkstra(SG, origen + n, Pbus);
    //cout<< Dbus;
    vector<vertice> Pavion(3*n);
    vector<tCoste> Davion(3*n);
    Davion = Dijkstra(SG, origen + n + n, Pavion);
    cout<< Davion;

    //Vemos el mínimo
    tCoste minimT = min(Dtren[destino], min(Dtren[destino + n], Dtren[destino + n + n]));
    tCoste minimB = min(Dbus[destino], min(Dbus[destino + n], Dbus[destino + n + n]));
    tCoste minimA = min(Dbus[destino], min(Dbus[destino + n], Dbus[destino + n + n]));
    tCoste minimo = min(minimA, min(minimB, minimT));

    if(minimo == minimB){
        if(minimo == Dbus[destino]){
            cout << "El camino más corto es: " << camino<tCoste>(origen + n, destino, Pbus) << endl;
            cout << "El coste es: " << minimo;
        } else if(minimo == Dbus[destino + n]){
            cout << "El camino más corto es: " << camino<tCoste>(origen + n, destino + n , Pbus) << endl;
            cout << "El coste es: " << minimo;
        } else if(minimo == Dbus[destino +n +n]){
            cout << "El camino más corto es: " << camino<tCoste>(origen + n, destino + n , Pbus) << endl;
            cout << "El coste es: " << minimo;
        } 
    } else if(minimo == minimT){
         if(minimo == Dtren[destino]){
            cout << "El camino más corto es: " << camino<tCoste>(origen, destino, Ptren) << endl;
            cout << "El coste es: " << minimo;
        } else if(minimo == Dtren[destino + n]){
            cout << "El camino más corto es: " << camino<tCoste>(origen, destino + n , Ptren) << endl;
            cout << "El coste es: " << minimo;
        } else if(minimo == Dtren[destino +n +n]){
            cout << "El camino más corto es: " << camino<tCoste>(origen, destino + n , Ptren) << endl;
            cout << "El coste es: " << minimo;
        } 
    } else if(minimo == minimA){
         if(minimo == Dtren[destino]){
            cout << "El camino más corto es: " << camino<tCoste>(origen + 2 * n, destino, Pavion) << endl;
            cout << "El coste es: " << minimo;
        } else if(minimo == Dtren[destino + n]){
            cout << "El camino más corto es: " << camino<tCoste>(origen + 2 * n, destino + n , Pavion) << endl;
            cout << "El coste es: " << minimo;
        } else if(minimo == Dtren[destino +n +n]){
            cout << "El camino más corto es: " << camino<tCoste>(origen + 2 * n, destino + n , Pavion) << endl;
            cout << "El coste es: " << minimo;
        } 
    }
}
