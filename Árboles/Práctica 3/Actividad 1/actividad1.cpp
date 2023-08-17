
// Cabeceras ------------------------------------
template<typename T>
int Grado(const Agen<T>&);

template<typename T>
int GradoRec(const Agen<T>&, typename Agen<T>::nodo);

template<typename T>
int nHijos(const Agen<T>& A, typename Agen<T>::nodo n);

// Funciones --------------------------------------

template<typename T>
int Grado(const Agen<T>& A){
    return GradoRec(A, A.raiz());
}

template<typename T>
int GradoRec(const Agen<T>& A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return 0;
    else{
        int gradomax = nHijos(A, n);
        typename Agen<T>::nodo aux = A.hijoIzqdo(n);
        while(aux != Agen<T>::NODO_NULO){
            gradomax = max(gradomax, GradoRec(A, aux));
            aux = A.hermDrcho(aux);
        }
        return gradomax;
    }
}

template<typename T>
int nHijos(const Agen<T>& A, typename Agen<T>::nodo n){
    int cont = 0;
    typename Agen<T>::nodo aux = A.hijoIzqdo(n);
    while(aux != Agen<T>::NODO_NULO){
        cont++;
        aux = A.hermDrcho(aux);
    }
    return cont;
}
