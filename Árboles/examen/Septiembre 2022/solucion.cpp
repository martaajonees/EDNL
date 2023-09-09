//Cabeceras

template<typename T>
bool es_avl (const Abin<T>& A);

template<typename T>
int alturaRec(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int desequilibrio(const Abin<T>& A);

template<typename T>
int REC_desequilibrio(const Abin<T>& A, typename Abin<T>::nodo n);


//Funciones

template<typename T>
bool es_avl (const Abin<T>& A){
    if(desequilibrio(A) == 0 || desequilibrio(A) == 1){
        return true;
    }
    else return false;
}

template<typename T>
int desequilibrio(const Abin<T>& A){
    return REC_desequilibrio(A, A.raiz());
}

template<typename T>
int REC_desequilibrio(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return 0; // Si es nodo, nulo, ha acabado
    } else {
        int maximo = max(REC_desequilibrio(A, A.hijoIzqdo(n)), REC_desequilibrio(A, A.hijoDrcho(n)));
        return max(maximo, abs(alturaRec(A, A.hijoIzqdo(n)) - alturaRec(A, A.hijoDrcho(n))));
    }
}

template<typename T>
int alturaRec(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO){
        return 0;
    } else {
        return 1 + max(alturaRec(A, A.hijoDrcho(n)), alturaRec(A, A.hijoIzqdo(n)));
    }
}
