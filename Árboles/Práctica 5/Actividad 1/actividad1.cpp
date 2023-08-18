// Cabecera ------------------------

void eliminar(Abin<int> A, int elto);

Abin<int>::nodo buscar(const Abin<int>& A, Abin<int>::nodo n, int elto);

// Funciones -----------------------

void eliminar(Abin<int> A, int elto){
    Abin<int>::nodo aux = buscar(A, A.raiz(), elto);
    if(A.elemento(aux) == elto){
        borrar(A, aux);
    }
}

void borrar(Abin<int>& A, Abin<int>::nodo n){
    if(A.hijoIzqdo(A.padre(n)) == n){
        A.eliminarHijoIzqdo(A.padre(n));
    } else A.eliminarHijoDrcho(A.padre(n));
}


Abin<int>::nodo buscar(const Abin<int>& A, Abin<int>::nodo n, int elto){
    if(n == Abin<int>::NODO_NULO) return n;
    else {
        if(A.elemento(n) == elto) return n;
        else {
            if(A.elemento(n) < elto){
                Abin<int>::nodo izq = buscar(A, A.hijoIzqdo(n), elto);
                if(izq == Abin<int>::NODO_NULO) return buscar(A, A.hijoDrcho(n), elto);
                else return izq;
            }
        }
    }
}
