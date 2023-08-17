
// Cabeceras --------------------------------------
template<typename T>
int desequilibrio(const Agen<T>& A);

template<typename T>
int desequilibrioRec(const Agen<T>& A, typename Agen<T>::nodo);

template<typename T>
int Altura(const Agen<T>& A, typename Agen<T>::nodo);

// Funciones --------------------------------------

template<typename T>
int desequilibrio(const Agen<T>& A){
    return desequilibrioRec(A, A.raiz());
}

template<typename T>
int desequilibrioRec(const Agen<T>& A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return 0;
    else {
        int altmax = 0, altmin = 99999, maximo;
        typename Agen<T>::nodo aux = A.hijoIzqdo(n);
        while(aux != Agen<T>::NODO_NULO){
            altmax = max(Altura(A, aux), altmax);
            altmin = min(Altura(A, aux), altmin);
            maximo = max(desequilibrioRec(A, aux), maximo);
            aux = A.hermDrcho(aux);
        }
        return max(maximo, altmax-altmin);
    }
}

template<typename T>
int Altura(const Agen<T>& A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return 0;
    else {
        return 1 + Altura(A, A.hijoIzqdo(n));
    }
}
