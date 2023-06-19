template<typename tCoste>
matriz<tCoste> nocapital(const GrafoP<tCoste>& zuelandia, typename GrafoP<tCoste>::vertice capital){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t N = zuelandia.numVert();
    GrafoP<tCoste> G(zuelandia);

    //no residentes
    for(vertice i = 0; i <= N-1; i++){
        for(vertice j = 0; j <= N-1; j++){
            if(i == capital && j == capital) G[i][j] = 0; //De capital a si misma es 0
            else if(i == capital || j == capital){ //Si va a pasar por la capital, el coste es infinito
                G[i][j] = GrafoP<tCoste>::INFINITO;
            }
        }
    }

    //Hacemos Floyd para caminos mínimos entre ciudades sin pasar por la ciudad
    matriz<vertice> caminos(N);
    matriz<tCoste> caminos = Floyd(zuelandia, caminos);
 
    //Residentes
    //hacemos Dijkstra y Dijkstra inverso para que en el caso de ser residente
    vector<vertice> vect(N);
    vector<tCoste> D = Dijkstra(zuelandia, capital, vect);
    vector<vertice> vectI(N);
    vector<tCoste> D = Dijkstra(zuelandia, capital, vectI);

    //Devolvemos caminos
    for(vertice i=0; i < n ; i++){
        caminos[capital][i] = vect[i];
        caminos[i][capital] = vectI[i];
    }
    return caminos;
}
