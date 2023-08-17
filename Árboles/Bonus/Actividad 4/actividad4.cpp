// CABECERA ------------------

template<typename T>
int nodosReflejados(const Abin<T>& A);

template<typename T>
int nodosReflejadosRec(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
bool reflejo(const Abin<T>& A, typename Abin<T>::nodo a, typename Abin<T>::nodo b);

template<typename T>
bool hermanos(const Abin<T>& A, typename Abin<T>::nodo a, typename Abin<T>::nodo b);

// FUNCIONES --------------------

template<typename T>
int nodosReflejados(const Abin<T>& A){
    return nodosReflejadosRec(A, A.raiz());
}

template<typename T>
int nodosReflejadosRec(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        if(hermanos(A, A.hijoDrcho(n), A.hijoIzqdo(n)) && reflejo(A, A.hijoDrcho(n), A.hijoIzqdo(n))) {
            return 1 + nodosReflejadosRec(A, A.hijoDrcho(n)) + nodosReflejadosRec(A, A.hijoIzqdo(n));
        } else return nodosReflejadosRec(A, A.hijoDrcho(n)) + nodosReflejadosRec(A, A.hijoIzqdo(n));
    }
}

template<typename T>
bool reflejo(const Abin<T>& A, typename Abin<T>::nodo a, typename Abin<T>::nodo b){
    if(a == Abin<T>::NODO_NULO && b == Abin<T>::NODO_NULO) return true;
    else if((a != Abin<T>::NODO_NULO && b == Abin<T>::NODO_NULO)||(a == Abin<T>::NODO_NULO && b != Abin<T>::NODO_NULO)){
        return false;
    } else if(A.hijoDrcho(a)==A.hijoIzqdo(b) && A.hijoIzqdo(a) == A.hijoDrcho(b)){
        return reflejo(A, A.hijoDrcho(a), A.hijoDrcho(b))&& reflejo(A, A.hijoIzqdo(a), A.hijoIzqdo(b));
    } else return false;
}

template<typename T>
bool hermanos(const Abin<T>& A, typename Abin<T>::nodo a, typename Abin<T>::nodo b) {
    if(a == Abin<T>::NODO_NULO && b == Abin<T>::NODO_NULO) return false;
    else {
        if(A.padre(a) == A.padre(b)) return true;
        else return false;
    }
}
