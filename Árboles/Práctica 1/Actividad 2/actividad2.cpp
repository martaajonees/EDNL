template<typename T>
int Altura(const Abin<T>& a);

template<typename T>
int AlturaRec(const Abin<T>&, typename Abin<T>::nodo);

template<typename T>
int Altura(const Abin<T>& A){
    return AlturaRec(A, A.raiz());
}

template<typename T>
int AlturaRec(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        return 1 + max(AlturaRec(A, A.hijoDrcho(n)), AlturaRec(A, A.hijoDrcho(n)));
    }
}
