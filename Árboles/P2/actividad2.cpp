/*
 Para un árbol binario B, podemos construir el árbol binario 
 reflejado BR cambiando los subárboles izquierdo y derecho en 
 cada nodo. Implementa un subprograma que devuelva el árbol binario 
 reflejado de uno dado
*/

#include "../abin.hpp"
template<typename T>
Abin<T> arbolreflejado(Abin<T> B, typename Abin<T>::nodo n);
template<typename T>
Abin<T> arbolreflejadoRec(Abin<T> B, typename Abin<T>::nodo n);

template<typename T>
Abin<T> arbolreflejado(Abin<T> B,typename Abin<T>::nodo n){
    Abin<T> B=B1;
    return arbolreflejadoRec(B1, B.raiz());
}

template<typename T>
Abin<T> arbolreflejadoRec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return A;
    else {
        A.hijoDrcho(n) = arbolreflejadoRec(A, A.hijoDrcho(n));
        A.hijoIzqdo(n) = arbolreflejadoRec(A, A.hijoIzqdo(n));
        typename Abin<T>::nodo aux = A.hijoDrcho(n);
        A.hijoDrcho(n) = A.hijoIzqdo(n);
        A.hijoIzqdo(n) = aux;
        return A;
    }
}

int main(){}