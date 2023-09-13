//Devuelve el número de cajas que quedan por servir
int Pedido(size_t); 

size_t cliente_mas_proximo(const GrafoP<double>& G, GrafoP<double>::vertice actual, double& coste, vector<bool> v){

    typedef GrafoP<double>::vertice vertice;
    //Vemos cliente más próximo 
    vector<double> D;
    vector<vertice> p;
    D = Dijkstra(G, actual, p);
    double min = GrafoP<double>::INFINITO;
    for(int i = 0; i< D.size(); i++){
        if(D[i] < min && i != actual && !v[i]) min = i;
    }
    coste = D[min];
    return min;
}

double volver_a_la_central(size_t actual, const GrafoP<double>& G, GrafoP<double>::vertice central){
    typedef GrafoP<double>::vertice vertice;
    vector<double> I;
    vector<vertice> p;
    I = DijkstraInv<double>(G, central, p);
    return I[actual];
}

bool todo_visitado(vector<bool> v){
    for(int i = 0; i< v.size(); i++){
        if(v[i] == false) return false;
    }
    return true;
}

double reparto(const GrafoP<double>& G, int capacidad_maxima, GrafoP<double>::vertice central){

    typedef GrafoP<double>::vertice vertice;
    const int N = G.numVert();
    vector<bool> visitado(N, false);
    double distancia_total = 0;

    //Vemos clientes más próximos desde la central
    while(!todo_visitado(visitado)){
        int cant_actual = capacidad_maxima; //salimos de la central
        vertice actual = central;
        //No volvemos a la central hasta que la cantidad esté a 0
        while(cant_actual > 0){
            double coste;
            actual = cliente_mas_proximo(G, actual, coste, visitado);
            distancia_total += coste;
            if(Pedido(actual) <= cant_actual){
                cant_actual -= Pedido(actual); //Restamos la cantidad
                visitado[actual] = true;
            }else {
                Pedido(actual) -= cant_actual;
                cant_actual = 0;
            }
        }
        distancia_total += volver_a_la_central(actual, G, central);
    }
    return distancia_total;
}
