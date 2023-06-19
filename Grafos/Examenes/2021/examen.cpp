struct Ciudad {
    Ciudad(int x, int y): x(x), y(y) {}
    int x, y;
};

struct Puente {
    Puente(int a= 0, int b = 0, double coste = 0.0): a(a), b(b), coste(coste) {}
    int a, b;
    double coste;
};

double distancia_euclidea(Ciudad a, Ciudad b){
    return sqrt(pow(a.x - b.x, 2)+pow(a.y - b.y, 2));
}


template<typename tCoste>
GrafoP<tCoste> grecoland(vector<Ciudad> F_ciudad, vector<Ciudad> D_ciudad, vector<Ciudad> E_ciudad, 
double coste_puente, double coste_carretera, double puente_ad, double carr_ad){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t N1 = F_ciudad.size();
    size_t N2 = D_ciudad.size();
    size_t N3 = E_ciudad.size();

    //Buscamos sólo las menores carreteras
    //Islas
    GrafoP<tCoste> SG(N1 + N2 + N3);

    for(vertice i = 0; i <= N1-1; i++){
        for(vertice j = 0; j <= N1-1; j++){
            if(i != j){
                SG[i][j] = SG[j][i]= coste_carretera + distancia_euclidea(F_ciudad[i], F_ciudad[j])* carr_ad;
            }
        }
    }
    //Deimos
    for(vertice i = N1; i <= N1+ N2-1; i++){
        for(vertice j = N1; j <= N1+ N2-1; j++){
            SG[i][j] = SG[j][i]= coste_carretera + distancia_euclidea(D_ciudad[i], D_ciudad[j])* carr_ad;
        }
    }

    //Europa
    for(vertice i = N1 +N2; i <= N1+ N2 +N3-1; i++){
        for(vertice j = N1+ N2; j <= N1+ N2+ N3-1; j++){
            SG[i][j] = SG[j][i]= coste_carretera + distancia_euclidea(E_ciudad[i], E_ciudad[j])* carr_ad;
        }
    }

    //Ponemos puentes
    for (vertice i = 0; i < N1; i++) {
        for (vertice j = 0; j < N2; j++) {
            SG[i][j + N1] = SG[j + N1][i] = coste_puente + distancia_euclidea(F_ciudad[i], D_ciudad[j]) * puente_ad;
        }
    }

    for (vertice i = 0; i < N1; i++) {
        for (vertice j = 0; j < N3; j++) {
            SG[i][j + N1 + N2] = SG[j + N1 + N2][i] = coste_puente + distancia_euclidea(F_ciudad[i], E_ciudad[j]) * puente_ad;
        }
    }

    for (vertice i = 0; i < N2; i++) {
        for (vertice j = 0; j < N1; j++) {
            SG[i + N1][j] = SG[j][i + N1] = coste_puente + distancia_euclidea(D_ciudad[i], F_ciudad[j]) * puente_ad;
        }
    }

    
    //Hacemos prim para las rutas menores
    GrafoP<tCoste> Rutas(SG.numVert());
    Rutas = Prim(SG);

   return Rutas;

}
