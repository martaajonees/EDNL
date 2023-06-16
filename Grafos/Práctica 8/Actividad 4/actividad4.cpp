
//Quiero todas las ciudades con todas
//Busco el árbol de extensión máxima
template <typename tCoste>
void emasejer(const GrafoP<tCoste>& G){
    //Creamos grafo nuevo
    GrafoP<tCoste> Max(G.numVert());
    Max = arbol_extension_maximo(G);

    cout<< "Arbol de extension maximo\n"<< Max;
    cout << "Longitud: " << Max.numVert(); 
}
