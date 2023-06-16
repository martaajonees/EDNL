template<typename tCoste>
struct Isla{
    tCoste x, y;
};

template<typename tCoste>
void tombuctu(Grafo A, vector<Isla<tCoste> > islas){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = A.numVert();
    //Crear grafo ponderado
    GrafoP<double> G (n);
    Particion p(n);

    //Recorremos la matriz de adyascencia
    for( int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j]){
                //Le asignamos distancia euclidiana
                G[i][j] = sqrt(pow(islas[i].x - islas[i].y, 2) + pow(islas[j].x - islas[j].y, 2));
                //Unimos las islas que estén conectadas entre ellas en el tad particion
                if(p.encontrar(i) != p.encontrar(j)){
                    p.unir(p.encontrar(i), p.encontrar(j));
                }
            }
        }
    }
    //Hacemos Floys para los costes mínimos
    vector<vertice> vert(n);
    vector<tCoste> mCoste = Floyd(G, vert);

    cout << "Costes minimos \n" << mCoste;

    return p;
}
