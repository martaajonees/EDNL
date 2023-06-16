//Mayor caudal posible, menor longitud
template<typename tCoste>
void emasajer(GrafoP<tCoste> ciudades, GrafoP<tCoste> caudales, double subvencion_canal, double coste_km){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = ciudades.numVert();
    //Creo nuevo grafo
    GrafoP<tCoste> canal(n);
    tCoste longitud = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(ciudades[i][j] != GrafoP<tCoste>::INFINITO && canal[i][j] != GrafoP<tCoste>::INFINITO){
                canal[i][j] = suma(ciudades[i][j]* subvencion_canal,  - caudales[i][j]* coste_km); 
            }
        }
    }

    //Ya tenemos los costes, ahora los mínimos
    cout<< "Canales \n" << Kruskall(canal);
}
