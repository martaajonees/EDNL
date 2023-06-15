template<typename tCoste>
tCoste camino_minimo(GrafoP<tCoste> Tren, GrafoP<tCoste> Bus, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
typename GrafoP<tCoste>::vertice cambio1,typename GrafoP<tCoste>::vertice cambio2 ){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = Tren.numVert();

    vector<vertice> vert; //vector de vertice para Dijkstra
    vector<tCoste> mTren = Dijkstra(Tren, origen, vert);
    vector<tCoste> mBus = DijkstraInv(Bus, destino, vert);

   tCoste m = std::min(mTren[cambio1]+ mBus[cambio1], mTren[cambio2]+ mBus[cambio2]);
   if(m == mTren[cambio1]+ mBus[cambio1]){
        std::cout<<"La ruta será: "<< origen << ", " << cambio1 << ", " << destino<< std::endl;
   } else std::cout<<"La ruta será: "<< origen << ", " << cambio2 << ", " << destino << std::endl;
   return m;
}
