/*
Contar el número de nodos de un árbol binario que son nodos reflejos. Dos nodos son reflejos 
cuando, siendo hermanos entre si, son las raíces de dos árboles (subárboles si queréis) que 
son reflejados entre sí. La definición de un árbol reflejado la conocéis de las prácticas, 
entendemos reflejado como la imagen especular.
*/

#include "../abin.hpp"
//Devuelve true si son hermanos y false si no lo son
template<typename T>
bool hermanos(Abin<T> A, typename Abin<T>::nodo n1, typename Abin<T>::nodo n2);
//Devuelve true si dos nodos son reflejados
template<typename T>
bool reflejados(Abin<T> A, typename Abin<T>::nodo n1, typename Abin<T>::nodo n2);
template<typename T>
int nodoverde(Abin<T> A); //1º llamada
template<typename T>
int nodoverdeRec(Abin<T> A, typename Abin<T>::nodo n);

template<typename T>
bool hermanos(Abin<T> A, typename Abin<T>::nodo n1, typename Abin<T>::nodo n2){
    if(n1==Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO) return false;
    else{
        if(A.padre(n1)==A.padre(n2)) return true;
        else return false;
    }
}
template<typename T>
bool reflejados(Abin<T> A, typename Abin<T>::nodo n1, typename Abin<T>::nodo n2){
    if(n1==Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO) return true;
    else{
        if(n1==Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO || n1 != n2) return false;
        else{
            if(A.hijoDrcho(n1)==A.hijoIzqdo(n2)&& A.hijoIzqdo(n1)==A.hijoDrcho(n2)) 
            return reflejados(A, A.hijoDrcho(n1), A.hijoDrcho(n2)) && reflejados(A, A.hijoIzqdo(n1), A.hijoIzqdo(n2));
            else return false;
        }
    }
}

template<typename T>
int nodoverde(Abin<T> A){
    return nodoverdeRec(A, A.hijoDrcho(A.raiz()), A.hijoIzqdo(A.raiz()));
}
template<typename T>
int nodoverdeRec(Abin<T> A, typename Abin<T>::nodo n1, typename Abin<T>::nodo n2){
    if(n1==Abin<T>::NODO_NULO || n2==Abin<T>::NODO_NULO) return 0;
    else{
        if(hermanos(A, n1, n2) && reflejados(A, n1, n2)) 
        return 1 + nodoverdeRec(A, A.hijoDrcho(n),A.hijoDrcho(n))+nodoverdeRec(A, A.hijoIzqdo(n), A.hijoIzqdo(n));
        else return nodoverdeRec(A, A.hijoDrcho(n),A.hijoDrcho(n))+nodoverdeRec(A, A.hijoIzqdo(n), A.hijoIzqdo(n));
    }
}
