int Pedido(){} //asumimos que existe el int pedido

template<typename tCoste>
double reparto(GrafoP<tCoste> caminos, size_t max_cant){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t n = caminos.numVert();
    //Caminos mínimos
    matriz<vector> vect;
    matriz<tCoste> d = Floyd(caminos, vect);
    //Partimos que el origen es 0
    vertice origen = 0, actual;
    //Almacenamos el recorrido
    double distancia_total = 0;
    //Lista de visitados
    vector<bool> visitados;
    visitados[origen] = true;
    //Cantidad actual
    size_t cant_actual = max_cant;
    

    while(!todo_visitado(visitados)){ //Iteramos hasta que todos los clientes hayan sido visitados
        while(cant_actual != 0){
            actual = cliente_mas_cercano(d, origen, visitados);
            if(Pedido(actual) <= cant_actual){ //Si el pedido es menor que la cantidad actual
                cant_actual -= Pedido(); //Le quitamos el stock del pedido
                visitados[actual] = true; //Lo marcamos como visitado
                distancia_total = d[origen][actual];
                origen = actual; //marcamos este como nuestro nuevo origen
            } else if(Pedido(actual) > cant_actual){ //Si el pedido es mayor que la cantidad actual
                Pedido(actual) -= cant_actual; //Le doy lo que tengo
                cant_actual = 0; //Se sale del while
            }
        }

        //Si se sale del bucle será: cantidad = 0 
        origen = 0; //Volvemos al almacén
        distancia_total += d[actual][origen]; //Coste de ir al almacén
        cant_actual = max_cant; //Rellenamos bebidas
    }
    return distancia_total;
}

template<typename tCoste>
auto cliente_mas_cercano(matriz<tCoste> d, typename GrafoP<tCoste>::vertice cliente_actual, 
vector<bool> visitados){
    typedef typename GrafoP<tCoste>::vertice vertice;
    tCoste distancia_min = GrafoP<tCoste>::INFINITO;
    vertice siguiente = -1;

    for(vertice i = 0; i < d.numVert(); i++){
        if(i != cliente_actual && !visitados[i] && d[cliente_actual][i] < distancia_min){
            distancia_min = d[cliente_actual][i];
            siguiente = i;
        }
    }
    return siguiente;
}

bool todo_visitado(vector<bool> visitado){
    bool v = true;
    for(int i = 0; i < visitado.size(); i++){
        if(visitado[i] != true) v = false;
    }
    return v;
}
