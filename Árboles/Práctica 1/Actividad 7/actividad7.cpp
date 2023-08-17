template<typename T>
bool Pseudocompleto(const Abin<T>&);

template<typename T>
bool PseudocompletoRec(const Abin<T>&, typename Abin<T>::nodo, int altura);

template<typename T>
bool Pseudocompleto(const Abin<T>& A){
    return PseudocompletoRec(A, A.raiz(), Altura(A));
}

template<typename T>
bool PseudocompletoRec(const Abin<T>& A, typename Abin<T>::nodo n, int altura){
    if(Profundidad(A, n) == altura -1){ //Estamos en el nivel
        if((A.hijoDrcho(n)!= Abin<T>::NODO_NULO && A.hijoIzqdo(n)!= Abin<T>::NODO_NULO) ||
        (A.hijoDrcho(n)== Abin<T>::NODO_NULO && A.hijoIzqdo(n)== Abin<T>::NODO_NULO))
        return true;
        else return false;
    }
    else return PseudocompletoRec(A, A.hijoDrcho(n), altura) && PseudocompletoRec(A, A.hijoIzqdo(n), altura);
}
