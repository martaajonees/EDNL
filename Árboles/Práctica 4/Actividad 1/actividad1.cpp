// Cabecera ------------------------

template<typename T>
void eliminar(Abb<T>& A, int x);

template<typename T>
void eliminarRec(Abb<T>& A, typename Abb<T>::nodo n);

// Funciones -----------------------

template<typename T>
void eliminar(Abb<T>& A, int x){
    typename Abb<T>::nodo n = A.buscar(x);
    return eliminarRec(A, n);
}

template<typename T>
void eliminarRec(Abb<T>& A, typename Abb<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return;
    else {
        eliminarRec(A, A.drcho(n)); //Elimino arbol derecho

        eliminarRec(A, A.izqdo(n)); //Elimino arbol izquierdo

        A.eliminar(n); //Una vez es hoja elimino el nodo
    }
    
}
