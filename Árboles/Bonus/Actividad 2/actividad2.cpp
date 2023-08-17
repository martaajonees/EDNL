// CABECERAS ----------------------

template<typename T>
int nNietos(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int nBisnietos(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int nHijos(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int doble(const Abin<T>& A);

template<typename T>
int dobleRec(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int Profundidad(const Abin<T>& a, typename Abin<T>::nodo n);

// FUNCIONES --------------------------

template<typename T>
int Profundidad(const Abin<T>& a, typename Abin<T>::nodo n){
    if(n == a.raiz()) return 0;
    else{
        return 1 + Profundidad(a, a.padre(n));
    }
}

template<typename T>
int nNietos(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        return nHijos(A, A.hijoDrcho(n)) + nHijos(A, A.hijoIzqdo(n));
    }
}

template<typename T>
int nHijos(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        int hijos = 0;
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO) hijos++;
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO) hijos++;
        return hijos;
    }
}

template<typename T>
int nBisnietos(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        return nNietos(A, A.hijoDrcho(n)) + nNietos(A, A.hijoIzqdo(n));
    }
}

template<typename T>
int doble(const Abin<T>& A){
    return dobleRec(A, A.raiz());
}

template<typename T>
int dobleRec(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        if(nNietos(A, n) == 2 * nBisnietos(A, n) && Profundidad(A, n) >= 3)
            return 1 + dobleRec(A, A.hijoDrcho(n)) + dobleRec(A, A.hijoIzqdo(n));
        else return dobleRec(A, A.hijoDrcho(n)) + dobleRec(A, A.hijoIzqdo(n));
    }
}
