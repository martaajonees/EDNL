
//Queremos que nos de la longitud mínima de conectar todas las ciuudades
template<typename tCoste>
tCoste reteuni3(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = G.numVert();

    //Creamos grafo con solución
    GrafoP<tCoste> fibra(n);
    fibra = Kruskall(G);

    //Para la longitud calculamos los costes del grafo resutante
    tCoste total = 0;
    for(vertice i = 0; i < n ; i++){
        for(vertice j = 0; j < n; j++){
            if(fibra[i][j] != GrafoP<tCoste>::INFINITO){
                total += fibra[i][j];
            }
        }
    }
    return total;
}
