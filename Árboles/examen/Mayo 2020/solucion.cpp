//Cabeceras

struct Proposicion;

bool resolver (const Abin<Proposicion>& A, vector<bool> valoracion);

bool recResolver (const Abin<Proposicion>& A, typename Abin<Proposicion>::nodo n, vector<bool> valoracion);

//Funciones

struct Proposicion {
    Proposicion(char con):es_conectiva(true), conect(con){}
    Proposicion(int v):es_conectiva(false), simbolo(v){}
    bool es_conectiva;
    char conect; // Y, O o NO
    int simbolo; // s1, s2, ...
};


bool resolver (const Abin<Proposicion>& A, vector<bool> valoracion){
    return recResolver(A, A.raiz(), valoracion);
}

bool recResolver (const Abin<Proposicion>& A, typename Abin<Proposicion>::nodo n, vector<bool> valoracion){
    if(!A.elemento(n).es_conectiva){ // SI no es conectiva, sacamos su valor de verdad
        int simbolo = A.elemento(n).simbolo;
        return valoracion[simbolo - 1]; 
    } else { //Es un símbolo
        switch (A.elemento(n).simbolo)
        {
        case 'Y':
            return recResolver(A, A.hijoDrcho(n), valoracion) && recResolver(A, A.hijoIzqdo(n), valoracion);
            break;
        case 'O':
            return recResolver(A, A.hijoDrcho(n), valoracion) || recResolver(A, A.hijoIzqdo(n), valoracion);
            break;
        case 'NO':
            return !recResolver(A, A.hijoIzqdo(n), valoracion);
            break;
        default:
            break;
        }
    }
}
