 enum alergia {Bus, Tren, Avion};

struct viajero {
    unsigned dinero;
    alergia alergico;
};

template<typename tCoste>
vector<typename GrafoP<tCoste>::vertice> encontrar_ciudades(viajero v, GrafoP<tCoste> bus, GrafoP<tCoste> tren, GrafoP<tCoste> avion ,typename GrafoP<tCoste>::vertice origen){
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t N = tren.numVert();
    
    vector<vertice> vect;
    vector<tCoste> costeMin(N);

    //Vemos que medios de transporte podemos utilizar
    switch (v.alergico){
    case Bus:
        costeMin = CalcularViaje(tren, avion, origen);
        //cout << "Bus: "<< costeMin << "\n";
        break;
    case Tren:
        costeMin = CalcularViaje(bus, avion, origen);
        break;
    case Avion:
        costeMin = CalcularViaje(tren, bus, origen);
        break;
    default:
        break;
    }

    //Ponemos la secuencia de ciudades alcanzables con el dinero disponible
    vector<vertice> ciudades(N);
    vector<tCoste> costes;
    for(vertice i = 0; i < costeMin.size(); i++){
        if(v.dinero >= costeMin[i]){
            ciudades.push_back(i);
            costes.push_back(costeMin[i]);
        }
    }

    cout<<"Costes: "<<costes<< endl;;
    return ciudades;
}

template<typename tCoste>
vector<tCoste> CalcularViaje(GrafoP<tCoste> medio1, GrafoP<tCoste> medio2,
typename GrafoP<tCoste>::vertice origen){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t N = medio1.numVert();
    GrafoP<tCoste> G(N);
    G = medio1;
    for(vertice i = 0; i < N; i++){
        for(vertice j=0; j < N; j++){
            G[i][j]= min(G[i][j], medio2[i][j]);
        }
    }
    cout << G;
    vector<vertice> vert;
    vector<tCoste> D = Dijkstra(G,origen,vert);
    return D;
}
