// Definiciones --------------------------------------
template<typename T>
int tres_nietos(const Abin<T>&);

template<typename T>
int tres_nietosRec(const Abin<T>&, typename Abin<T>::nodo n);

template<typename T>
int nNietos(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int nHijos(const Abin<T>& A, typename Abin<T>::nodo n);

// Funciones --------------------------------------

//Contar numero de nietos de ese nodo
template<typename T>
int nNietos(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        if(nHijos(A, n)!= 0){
            return nHijos(A, A.hijoDrcho(n)) + nHijos(A, A.hijoIzqdo(n));
        } else return 0;
    }
}

//Contar numero de hijos de ese nodo
template<typename T>
int nHijos(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        int hijos = 0;
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO) hijos++;
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO) hijos++;
        return hijos;
    }
}

template<typename T>
int tres_nietos(const Abin<T>& A){
    return tres_nietosRec(A, A.raiz());
}

template<typename T>
int tres_nietosRec(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        if(nNietos(A, n)== 3) return 1 + tres_nietosRec(A, A.hijoDrcho(n)) + tres_nietosRec(A, A.hijoIzqdo(n));
        else return tres_nietosRec(A, A.hijoDrcho(n)) + tres_nietosRec(A, A.hijoIzqdo(n));
    }
}
