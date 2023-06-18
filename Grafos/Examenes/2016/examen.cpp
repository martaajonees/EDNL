struct Puente {
    Ciudad a, b;
    double coste;
};

struct Ciudad {
    int x, y;
};
template<typename tCoste>
Puente grecolandia(Grafo F, Grafo D, vector<Ciudad>F_ciudad, vector<Ciudad> D_ciudad, 
vector<Ciudad> F_costa, vector<Ciudad> D_costa){
    double minimo = GrafoP<tCoste>::INFINITO;
    Puente p;
    for(size_t i = 0; i < F_costa.size(); i++){ //Ciudades costeras de Fobos
        for(size_t j = 0; j < D_costa.size(); j++){ //Ciudades costerad de Deimos
                double dist = distancia_euclidea(F_costa[i], D_costa[j]);
            if(dist < minimo){
                minimo = dist;
                p.a = F_costa[i];
                p.b = D_costa[j];
            }
        }
    }
    p.coste = minimo;
    return p;
}

double distancia_euclidea(Ciudad a, Ciudad b){
    return sqrt(pow(a.x - b.x, 2)+ pow(a.y - b.y, 2));
}
