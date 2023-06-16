
//Quiero todas las ciudades con todas y longitud máxima
//Busco el árbol de extensión máxima
template <typename tCoste>
void emasejer(const GrafoP<tCoste>& G){
    typedef typename GrafoP<tCoste>::vertice vertice;
    //Creamos grafo nuevo
    GrafoP<tCoste> Max(G.numVert());
    Max = arbol_extension_maximo(G);

    //Calculamos longitud
    tCoste total = 0;
    for(vertice i = 0; i < n ; i++){
        for(vertice j = 0; j < n; j++){
            if(Max[i][j] != GrafoP<tCoste>::INFINITO){
                total += fibra[i][j];
            }
        }
    }

    cout<< "Arbol de extension maximo\n"<< Max;
    cout << "Longitud: " << total; 
}
