//Cabeceras

template<typename T>
bool es_avl (const Abin<T>& A);

template<typename T>
int alturaRec(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int desequilibrio(const Abin<T>& A);

template<typename T>
int REC_desequilibrio(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
bool orden(const Abin<T>& A);

template<typename T>
bool recOrden(const Abin<T>& A, typename Abin<T>::nodo n);


//Funciones

template<typename T>
bool es_avl (const Abin<T>& A){
    if(desequilibrio(A) == 0 || desequilibrio(A) == 1){ // Está equilibrado
        if(orden(A)){
            return true;
        } else {
            return false;
        }
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

//COmprobar que se cumple la condición del orden
template<typename T>
bool orden(const Abin<T>& A){
    return recOrden(A, A.raiz());
}

template<typename T>
bool recOrden(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return true; // Llego al final
    } else {
        if(A.hijoDrcho(n) != Abin<T>::NODO_NULO){
            if(A.elemento(A.hijoDrcho(n)) <= A.elemento(n)){
                return false;
            }
        }
        if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO){
            if(A.elemento(A.hijoIzqdo(n)) >= A.elemento(n)){
                return false;
            }
        }

        return recOrden(A, A.hijoDrcho(n)) && recOrden(A, A.hijoIzqdo(n));
        
    }
}
