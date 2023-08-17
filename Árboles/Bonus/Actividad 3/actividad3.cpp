// CABECERAS ------------------

template<typename T>
int antecesor(const Abin<T>& , typename Abin<T>::nodo);

template<typename T>
int descendiente(const Abin<T>& , typename Abin<T>::nodo);

template<typename T>
int nostalgicosRec(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int nostalgicos(const Abin<T>& A);

// FUNCIONES ------------------

template<typename T>
int antecesor(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == A.raiz()) return 0;
    else{
        return 1 + antecesor(A, A.padre(n));
    }
}

template<typename T>
int descendiente(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        return 1 + descendiente(A, A.hijoDrcho(n)) + descendiente(A, A.hijoIzqdo(n));
    }
}

template<typename T>
int nostalgicosRec(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        if(antecesor(A, n) > descendiente(A, n)){
            return 1 + nostalgicosRec(A, A.hijoDrcho(n)) + nostalgicosRec(A, A.hijoIzqdo(n));
        }
        return nostalgicosRec(A, A.hijoDrcho(n)) + nostalgicosRec(A, A.hijoIzqdo(n));
    }
}
