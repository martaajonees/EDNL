
/* --------- Funciones ---------*/
template<typename T>
void poda(const Agen<T>& A, int x);

template<typename T>
void podaRec(Agen<T>& A, typename Agen<T>::nodo n);

template<typename T>
typename Agen<T>::nodo buscar(Agen<T>& A, typename Agen<T>::nodo n, int x);

/* ------------ Implementación ------------*/
template<typename T>
void poda(const Agen<T>& A, int x){
    Agen<T> A1 = A;
    return podaRec(A1, buscar(A, A.raiz(), x));
}

template<typename T>
void podaRec(Agen<T>& A, typename Agen<T>::nodo n){
    Agen<T>::nodo hijo = A.hijoIzqdo(n);

    if(n != Agen<T>::NODO_NULO){
        if(n == A.raiz()){ A.eliminarRaiz(); return; } //Si el nodo es la raiz, la elimino
        else { // Si no es la raiz vemos

            //Mientras que el hijo sea hoja
            while(hijo != Agen<T>::NODO_NULO && A.hijoIzqdo(hijo)==Agen<T>::NODO_NULO){ 
                A.eliminarHijoIzqdo(n); //Elimino el hijo
                hijo = A.hijoIzqdo(n);
            }

            //Si el hijo no es hoja
            if(hijo != Agen<T>::NODO_NULO && A.hijoIzqdo(hijo)!=Agen<T>::NODO_NULO){ 
                podaRec(A, A.hijoIzqdo(hijo)); //elimino los hijo del hijo
                A.eliminarHijoIzqdo(n); //Elimino al hijo izqdo
            }
        }
        
    }

}

template<typename T>
typename Agen<T>::nodo buscar(Agen<T>& A, typename Agen<T>::nodo n, int x){
    if(A.elemento(n) == x) return n;
    else {
        typename Agen<T>::nodo aux = A.hijoIzqdo(n);
        while(aux != Agen<T>::NODO_NULO){
            typename Agen<T>::nodo res = buscar(A, aux, x);
            if(res != Agen<T>::NODO_NULO) return res;
            aux = A.hermDrcho(aux);
        }
        return Agen<T>::NODO_NULO;
    }
}
