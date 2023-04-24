/*
    Construye una función que, dado un Árbol Binario, devuelva true 
    si es un AVL y false en el caso contrario
*/
#include "../abin.hpp"
template<typename T>
bool es_avlRec(Abin<T> A, typename Abin<T>::nodo n);
template<typename T>
bool es_avl(Abin<T> A);
template<typename T>
bool orden(Abin<T> A, typename Abin<T>::nodo n);
template<typename T>
bool equilibrado(Abin<T> A, typename Abin<T>::nodo n);

template<typename T>
bool es_avl(Abin<T> A){
    return es_avlRec(A, A.raiz());

}
template<typename T>
bool es_avlRec(Abin<T> A, typename Abin<T>::nodo n){
    if(equilibrado(A, n)){ //Si es equilibrado vemos si sigue el orden
        if(orden(A,n)) return true;
        else return false;
    }else return false; //Si no es equilibrado no es un avl
    
}

template<typename T>
bool equilibrado(Abin<T> A, typename Abin<T>::nodo n){
    if(n== Abin<T>::NODO_NULO) return true; //Si llegamos al final
    else{
        int altizq = A.altura(A.hijoIzqdo(n)); //Altura del hijo izquierdo
        int altder= A.altura(A.hijoDrcho(n)); //Altura del hijo derecho
        int maxim = max(equilibrado(A,A.hijoDrcho(n)), equilibrado(A, A.hijoIzqdo(n)));
        return (max(maxim, abs(altder-altizq))<=1);
    }
}

template<typename T>
bool orden(Abin<T> A, typename Abin<T>::nodo n){
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
        if(A.elemento(A.hijoIzqdo(n))>= A.elemento(n)) return false; 
        
    if(A.hijoDrcho(n)!= Abin<T>::NODO_NULO)
        if(A.elemento(A.hijoDrcho(n))<=A.elemento(n)) return false;
    
    
    return true; 
}

int main () {
    Abin<int> A;

    A.insertarRaiz(10);

    A.insertarHijoIzqdo(A.raiz(),8);
    A.insertarHijoDrcho(A.raiz(),12);

    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),7);
    A.insertarHijoDrcho(A.hijoIzqdo(A.raiz()),9);

    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()),11);
    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()),13);

    if(es_avl(A)) std::cout<<"Es un AVL";
    else std::cout<<"NO es AVL";

    return 0;
}