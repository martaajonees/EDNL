
// Cabeceras -----------------------------
template<typename T>
bool SimilaresRec(const Abin<T>& A, const Abin<T>& B, typename Abin<T>::nodo a, typename Abin<T>::nodo b);

template<typename T>
bool similares(const Abin<T>& A, const Abin<T>& B);

// Funciones -----------------------------

template<typename T>
bool similares(const Abin<T>& A, const Abin<T>& B){
    return SimilaresRec(A, B, A.raiz(), B.raiz());
}

template<typename T>
bool SimilaresRec(const Abin<T>& A, const Abin<T>& B, typename Abin<T>::nodo a, typename Abin<T>::nodo b) {
    if(A.arbolVacio() && B.arbolVacio()) return true; //Si los dos son vacíos, son similares
    else{ // Si no comprobamos
        if(a == Abin<T>::NODO_NULO && b == Abin<T>::NODO_NULO ) return true;
        else{
            if( (a == Abin<T>::NODO_NULO && b != Abin<T>::NODO_NULO)|| (a != Abin<T>::NODO_NULO && b == Abin<T>::NODO_NULO)) return false;
            else return SimilaresRec(A, B, A.hijoDrcho(a), B.hijoDrcho(b)) && SimilaresRec(A, B, A.hijoIzqdo(a), B.hijoIzqdo(b));
        }
    }
}
