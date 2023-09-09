//Cabecera

template<typename T>
void transforma(Abin<T>& A);

template<typename T>
void recTransforma(Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
bool mayor_que_ancestro(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
bool mayorREC(const Abin<T>& A, const T& elem, typename Abin<T>::nodo aux);

template<typename T>
bool menor_que_descendiente(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
bool menorREC(const Abin<T>& A, const T& elem, typename Abin<T>::nodo aux);

template<typename T>
void borrar(Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
void recBorrar(Abin<T>& A, typename Abin<T>::nodo n);

// Funciones

template<typename T>
void transforma(Abin<T>& A){
    recTransforma(A, A.raiz());
}

template<typename T>
void recTransforma(Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){ 
        return; //Llega al final, termina
    } else {
        if(mayor_que_ancestro(A, n) && menor_que_descendiente(A, n)){
            borrar(A, n); //Si el nodo lo cumple, borramos descendientes propios
        } else { //Si no lo cumple
            recTransforma(A, A.hijoDrcho(n));
            recTransforma(A, A.hijoIzqdo(n));
        }
    }
}

// Se debe comprobar que el contenido de un nodo sea >= que el de sus ancestros
template<typename T>
bool mayor_que_ancestro(const Abin<T>& A, typename Abin<T>::nodo n){
    return mayorREC(A, A.elemento(n), A.padre(n));
}

template<typename T>
bool mayorREC(const Abin<T>& A, const T& elem, typename Abin<T>::nodo aux){
    if(aux == Abin<T>::NODO_NULO){
        return true; // llega al final, es verdadero
    } else {
        if(elem >= A.elemento(aux)){
            return mayor_que_ancestro(A, elem, A.padre(aux)); // comprobamos a condición
        } else {
            return false; // no se cumple
        }
    }
}

// Se debe comprobar que el contenido de un nodo sea <= que el de sus descendientes
template<typename T>
bool menor_que_descendiente(const Abin<T>& A, typename Abin<T>::nodo n){
    return menorREC(A, A.elemento(n), A.hijoDrcho(n)) && 
    menorREC(A, A.elemento(n), A.hijoIzqdo(n)) ;
}

template<typename T>
bool menorREC(const Abin<T>& A, const T& elem, typename Abin<T>::nodo aux){
    if(aux == Abin<T>::NODO_NULO ){
        return true; //Ha llegado al final, es verdad
    } else {
        if(elem <= A.elemento(aux)){
            return menorREC(A, elem, A.hijoDrcho(aux)) && menorREC(A, elem, A.hijoIzqdo(aux));
        } else {
            return false;
        }
    }
}

// Esta funcion elimina los descendientes propios del nodo dado
template<typename T>
void borrar(Abin<T>& A, typename Abin<T>::nodo n){
    recBorrar(A, A.hijoDrcho(n));
    recBorrar(A, A.hijoIzqdo(n));
}

template<typename T>
void recBorrar(Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){ 
        return;  // Verificar si el nodo actual es nulo
    } else if(A.hijoDrcho(n) == Abin<T>::NODO_NULO && A.hijoIzqdo(n) == Abin<T>::NODO_NULO ){
        // Verificar si el nodo actual es una hoja (no tiene hijos)
        typename Abin<T>::nodo padre = A.padre(n);
        if(A.hijoDrcho(padre) == n) A.eliminarHijoDrcho(padre);
        else A.eliminarHijoIzqdo(padre);
    } else {
        // Si el nodo actual no es una hoja, recursivamente eliminar descendientes
        recBorrar(A, A.hijoDrcho(n));
        recBorrar(A, A.hijoIzqdo(n));
    }
}
