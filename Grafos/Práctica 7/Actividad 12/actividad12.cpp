template<typename tCoste>
void coste_total(GrafoP<tCoste> Islas){
    typedef typename GrafoP<tCoste>::vertice vertice;

    //Hacemos Floyd
    matriz<vertice> mvert(Islas.numVert());
    matriz<tCoste> total = Floyd(Islas, mvert);
    
    tCoste res = 0;
    //Calculamos Coste Total de floyd
    for(vertice i = 0; i < Islas.numVert(); i++){
        for(vertice j = 0; j < Islas.numVert(); j++){
            if(total[i][j] != GrafoP<tCoste>::INFINITO){
                res += total[i][j];
            }
        }
    }
    return res;
}


template<typename tCoste>
void construir_puente(matriz<tCoste> Fobos, matriz<tCoste> Deimos, vector<typename GrafoP<tCoste>::vertice> costaF,  vector<typename GrafoP<tCoste>::vertice> costaD){
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    //Creamos Grafo
    GrafoP<tCoste> Islas(Fobos.dimension()+ Deimos.dimension());

    //Inicializamos Grafo con Fobos
    for(tCoste i = 0; i < Fobos.dimension(); i++){
        for(tCoste j = 0; j < Fobos.dimension(); j++){
            Islas[i][j] = Fobos[i][j];
        }
    }

    //Inicializamos Grafo con Deimos
    for(tCoste i = Fobos.dimension(), m = 0; i < Deimos.dimension()+ Fobos.dimension(); i++, m++){
        for(tCoste j = Fobos.dimension(), n=0; j < Deimos.dimension()+ Fobos.dimension(); j++, n++){
            Islas[i][j] = Deimos[m][n];
        }
    }

    tCoste min = GrafoP<tCoste>::INFINITO;
    vertice ciudadF, ciudadD;


    //Costes con puente en cada ciudad costera
    for(vertice i = 0; i < costaF.size(); i++){
        for(vertice j = 0; j < costaD.size(); j++){
            Islas[costaF[i]][costaD[j]] = 0;
            //Vemos si reduce el coste
            tCoste c = coste_total(Islas);
            if(min > c){
                ciudadF = i;
                ciudadD = j;
                min = c;
            }
        }
    }

    cout << "Las ciudades donde se debe instalar el puente son "<< ciudadF << "(Fobos) y " << ciudadD<< " (Debos)";

}
