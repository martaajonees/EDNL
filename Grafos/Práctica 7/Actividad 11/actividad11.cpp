
//Estructura puente: un puente une dos ciudades
template<typename tCoste>
struct Puente{
    typename GrafoP<tCoste>::vertice ciudad1, ciudad2;
};

template<typename tCoste>
matriz<tCoste> archipielagos(GrafoP<tCoste> isla1, GrafoP<tCoste> isla2, GrafoP<tCoste> isla3, vector<Puente<tCoste> > puentes){
    typedef typename GrafoP<tCoste>::vertice vertice;

    //Tamaño:
    size_t n = isla1.numVert() + isla2.numVert() + isla3.numVert();
    
    // Hacemos grafo con costes de estas tres islas
    GrafoP<tCoste> Archipielago(n);

    //Relleno el grafo con las islas
    //Isla 1
    for(vertice i = 0; i < isla1.numVert(); i++){
        for(vertice j = 0; j < isla1.numVert(); j++){
            Archipielago[i][j] = isla1[i][j];
        }
    }

    //Isla 2
    for(vertice i = isla1.numVert(), m = 0; i < isla1.numVert()+ isla2.numVert(); i++, m++){
        for(vertice j = isla1.numVert(), n=0 ; j < isla1.numVert()+ isla2.numVert(); j++, n++){
            Archipielago[i][j] = isla2[m][n];
        }
    }

    //Isla 3
    for(vertice i = isla2.numVert() + isla1.numVert(), m = 0; i < n; i++, m++){
        for(vertice j = isla2.numVert() + isla1.numVert(), n=0 ; j < n; j++, n++){
            Archipielago[i][j] = isla2[m][n];
        }
    }

    //Pasar por el puente entre islas vale 0
    for(size_t i = 0; i < puentes.size(); i++){
        Archipielago[puentes[i].ciudad1][puentes[i].ciudad2] = 0;
        Archipielago[puentes[i].ciudad2][puentes[i].ciudad1] = 0;
    }

    //Una vez inicializado hacemos Floyd para la matriz de costes minimos
    matriz<vertice> mVert(n);
    matriz<tCoste> mCoste = Floyd(Archipielago,mVert);

return mCoste;

}
