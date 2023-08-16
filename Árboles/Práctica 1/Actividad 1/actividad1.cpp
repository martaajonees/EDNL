
template<typename T>
int numNodos(const Abin<T>& a);

template<typename T>
int numNodosRec(const Abin<T>&, typename Abin<T>::nodo);

template<typename T>
int numNodos(const Abin<T>& a){
    return numNodosRec(a, a.raiz());
}

template<typename T>
int numNodosRec(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        return 1 + numNodosRec(A, A.hijoDrcho(n)) + numNodosRec(A, A.hijoIzqdo(n));
    }
}
