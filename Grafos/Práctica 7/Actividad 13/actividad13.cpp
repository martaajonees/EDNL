template<typename tCoste>
struct Puente{
    typename GrafoP<tCoste>::vertice ciudad1, ciudad2;
};

template<typename tCoste>
tCoste coste_total(GrafoP<tCoste> Islas){
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

//Dados dos islas y dos costas indica cual es el mejor puente entre estas dos ciudades
template<typename tCoste> 
Puente<tCoste> mejor_puente(GrafoP<tCoste> G, vector<typename GrafoP<tCoste>::vertice> costa1, vector<typename GrafoP<tCoste>::vertice> costa2){
    typedef typename GrafoP<tCoste>::vertice vertice;

    tCoste min = GrafoP<tCoste>::INFINITO;
    vertice ciudad1, ciudad2;

    //Costes con puente en cada ciudad costera
    for(vertice i = 0; i < costa1.size(); i++){
        for(vertice j = 0; j < costa2.size(); j++){
            Islas[costa1[i]][costa2[j]] = 0;
            //Vemos si reduce el coste
            tCoste c = coste_total(Islas);
            if(min > c){
                ciudad1 = i;
                ciudad2 = j;
                min = c;
            }
            Islas[costa1[i]][costa2[j]] = GrafoP<tCoste>::INFINITO; 
            //Lo volvemos a poner en infinito y probamos con el siguiente
        }
    }
    Puente<tCoste> res;
    res.ciudad1 = ciudad1;
    res.ciudad2 = ciudad2;

    return res;

}

template<typename tCoste>
vector< Puente<tCoste> > maremoto(matriz<tCoste> isla1, matriz<tCoste> isla2, matriz<tCoste> isla3, vector<typename GrafoP<tCoste>::vertice> costa1, 
vector<typename GrafoP<tCoste>::vertice> costa2, vector<typename GrafoP<tCoste>::vertice> costa3){
    typedef typename GrafoP<tCoste>::vertice vertice;

    //Hacemos grafo
    GrafoP<tCoste> Islas(isla1.dimension()+ isla2.dimension()+ isla3.dimension());

    //Inicializamos islas
    //Isla 1
    for(vertice i = 0; i < isla1.dimension(); i++){
        for(vertice j = 0; j < isla1.dimension(); j++){
            Islas[i][j] = isla1[i][j];
        }
    }
    //Isla 2
    for(vertice i = isla1.dimension(), m = 0; i < isla1.dimension() + isla2.dimension(); i++, m++){
        for(vertice j = isla1.dimension(), n = 0; j < isla1.dimension() + isla2.dimension(); j++, n++){
            Islas[i][j] = isla2[m][n];
        }
    }

    //Isla 3
    for(vertice i = isla1.dimension() + isla2.dimension(), m = 0; i < isla1.dimension() + isla2.dimension() + isla3.dimension(); i++, m++){
        for(vertice j = isla1.dimension() + isla2.dimension(), n = 0; j < isla1.dimension() + isla2.dimension() + isla3.dimension(); j++, n++){
            Islas[i][j] = isla3[m][n];
        }
    }

    //Como mínimo debe haber tres puentes: 1 a 2, 2 a 3 y 1 a 3 
    Puente<tCoste> puente12 = mejor_puente(Islas, costa1, costa2);
    Puente<tCoste> puente23 = mejor_puente(Islas, costa2, costa3);
    Puente<tCoste> puente13 = mejor_puente(Islas, costa1, costa3);

    vector< Puente<tCoste> > res(4);
    res.push_back(puente12);
    res.push_back(puente13);
    res.push_back(puente23);

    return res;
}
