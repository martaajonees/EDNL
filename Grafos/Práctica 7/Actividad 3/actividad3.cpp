struct Ciudad{
    double subvencion;
    size_t capacidad;
    Ciudad(double subvencion, size_t capacidad)
        : subvencion(subvencion), capacidad(capacidad) {}
};

template<typename tCoste>
vector<double> empresa(GrafoP<tCoste> G, typename GrafoP<double>::vertice origen, 
size_t cantidades, vector<Ciudad> ciudades ){

    tCoste INFINITO = GrafoP<tCoste>::INFINITO;
    typedef typename GrafoP<tCoste>::vertice vertice;
    
    //Costes con las subvenciones
    for(vertice i = 0; i < G.numVert(); i++){
        for(vertice j = 0; j < G.numVert(); j++){
            if(G[i][j] != INFINITO)
                G[i][j] *= (1 - ciudades[j].subvencion/100);
        }
    }
    //Hacemos Dijkstra ya que conocemos el origen 
    vector<vertice> vectD;
    vector<tCoste> mCoste(G.numVert()) ;
    mCoste = Dijkstra(G, origen, vectD);

    //Repartimos cantidades
    vector<double> total(G.numVert(), 0);
    while(cantidades > 0){
        tCoste min = INFINITO;
        vertice ciudad = origen;
        for(vertice i = 0; i < G.numVert(); i++){
            //Si no es la ciudad origen, la capacidad es mayor que 0, es el minimo y no está 
            if(i != ciudad && ciudades[i].capacidad > 0 && min > mCoste[i]&& total[i]==0){
                ciudad = i;
                min = mCoste[i];
            }
        }
        if(ciudades[ciudad].capacidad >= cantidades){
            total[ciudad] = cantidades;
            cantidades = 0;
        }else{
            total[ciudad] = ciudades[ciudad].capacidad;
            cantidades -= ciudades[ciudad].capacidad;
        }
    }
    return total;
}
