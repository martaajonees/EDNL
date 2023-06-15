template<typename tCoste>
tCoste un_solo_transbordo(GrafoP<tCoste> Tren, GrafoP<tCoste> Bus, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = Tren.numVert();

    //Hago Dijkstra y DijkstraInv
    vector<vertice> vert(n);
    vector<tCoste> mTren(n);
    mTren = Dijkstra(Tren, origen, vert);
    vector<tCoste> mTrenInv(n);
    mTrenInv = DijkstraInv(Tren, destino, vert);
    vector<tCoste> mBus(n);
    mBus = Dijkstra(Bus, origen, vert);
    vector<tCoste> mBusInv(n);
    mBusInv = DijkstraInv(Bus, destino, vert);
    cout << mBusInv;
    
    //Vemos si sale más rentable ir en tren o en bus
    tCoste minimo = min(mTren[destino], mBus[destino]);
    //Vemos si esto es menor que hacer transbordo
    tCoste m;
    for(vertice i = 0; i < n; i++){
        if(i != origen || i != destino){
            //Empezar en tren y acabar en bus, empezar en bus y acabar en tren
            m = min(minimo, min(mTren[i]+ mBusInv[i], mBus[i]+mTrenInv[i]));
        }
    } 
  return m;
}
