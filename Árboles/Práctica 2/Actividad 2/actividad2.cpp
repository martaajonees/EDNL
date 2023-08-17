
// Cabeceras ------------------------------------
template<typename T>
Abin<T> reflejado(const Abin<T>& a);

template<typename T>
Abin<T> reflejadoRec(Abin<T>& B,typename Abin<T>::nodo n);

template<typename T>
Abin<T> reflejado(const Abin<T>& A){
    Abin<T> B = A;
    return reflejadoRec(B, A.raiz());
}

// Funciones ------------------------------------

template<typename T>
Abin<T> reflejadoRec(Abin<T>& B,typename Abin<T>::nodo n){
   if(n == Abin<T>::NODO_NULO) return B;
   else {
        B.hijoDrcho(n) = reflejadoRec(B, B.hijoDrcho(n));
        B.hijoIzqdo(n) = reflejadoRec(B, B.hijoIzqdo(n));
        // Intercambiamos
        typename Abin<T>::nodo aux;
        aux = B.hijoDrcho(n);
        B.hijoDrcho(n) = B.hijoIzqdo(n);
        B.hijoIzqdo(n) = aux; 
   }
}
