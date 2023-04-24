/*
Implementa una función genérica que transforme un árbol binario de un tipo genérico T, eliminando 
los descendientes propios de todos aquellos nodos cuyo contenido sea, al mismo tiempo, mayor o igual 
que el de sus ascendientes propios y menor o igual que el de sus descendientes propios.

*/
#include "../abin_E-S.h"
#include "../abin.hpp"
/* CABECERAS ---------*/
template<typename T>
void eliminarRec(Abin<T>& A, typename Abin<T>::nodo n);
template<typename T>
void eliminar(Abin<T> &A);
//Dado un nodo, destruyo su descendencia
template<typename T>
void destruirnodo(Abin<T>& A, typename Abin<T>::nodo n);
//Dado un nodo, lo destruyo 
template<typename T>
void eliminarNodo(Abin<T>& A, typename Abin<T>::nodo n);
template<typename T>
bool descendientes(Abin<T>& A, typename Abin<T>::nodo n, T elemento);


/*FUNCIONES ----------------*/
template<typename T>
void eliminar(Abin<T>& A){
    eliminarRec(A, A.raiz());
}

template<typename T>
void eliminarRec(Abin<T>& A, typename Abin<T>::nodo n){
    if(n != Abin<T>::NODO_NULO){
        if(ascendientes(A,n, A.elemento(n)) && descendientes(A, n, A.elemento(n))){
            destruirnodo(A, n);
        }
        eliminarRec(A, A.hijoDrcho(n));
        eliminarRec(A, A.hijoIzqdo(n));
    }
    
}

//Dado un nodo, destruyo su descendencia
template<typename T>
void destruirnodo(Abin<T>& A, typename Abin<T>::nodo n){
    if(!A.arbolVacio()){
        if(A.hijoDrcho(n)== Abin<T>::NODO_NULO && A.hijoIzqdo(n)== Abin<T>::NODO_NULO)
            eliminarNodo(A,n); //Si es hoja, lo elimino
        else{
            destruirnodo(A, A.hijoDrcho(n)); //llamo a hijo derecho
            destruirnodo(A, A.hijoIzqdo(n)); //llamo a hijo izquierdo
        }
   }
   
}
//Dado un nodo, lo destruyo 
template<typename T>
void eliminarNodo(Abin<T>& A, typename Abin<T>::nodo n){
    typename Abin<T>::nodo padre = A.padre(n);
    if(A.hijoDrcho(padre)== n) A.eliminarHijoDrcho(padre);
    else A.eliminarHijoIzqdo(padre);
}

template<typename T>
bool ascendientes(Abin<T>& A, typename Abin<T>::nodo n, T elemento){
    if(n == A.raiz()) return true;
    else{
        typename Abin<T>::nodo asc = A.padre(n);
        if(elemento>=A.elemento(asc)) 
            return ascendientes(A, A.padre(n), elemento);
        else return false;
    }
}

template<typename T>
bool descendientes(Abin<T>& A, typename Abin<T>::nodo n, T elemento){
    if(n == Abin<T>::NODO_NULO) return true;
    else{
        typename Abin<T>::nodo der = A.hijoDrcho(n);
        typename Abin<T>::nodo izq = A.hijoIzqdo(n);
        if(der != Abin<T>::NODO_NULO && izq != Abin<T>::NODO_NULO){ 
            if(elemento<=A.elemento(der)&& elemento<=A.elemento(izq)) 
                return descendientes(A, A.hijoDrcho(n), elemento) && descendientes(A, A.hijoIzqdo(n), elemento);
            else return false;
        }else if(der == Abin<T>::NODO_NULO && izq !=Abin<T>::NODO_NULO){
            if(elemento<=A.elemento(izq)) return descendientes(A, A.hijoIzqdo(n), elemento);
            else return false;
        } 
        else if (izq == Abin<T>::NODO_NULO && der !=Abin<T>::NODO_NULO){
            if(elemento<=A.elemento(der)) return descendientes(A, A.hijoDrcho(n), elemento);
            else return false;
        }
    }
}

int main () {
    Abin<int> A;

    A.insertarRaiz(4);

    A.insertarHijoIzqdo(A.raiz(),6);
    A.insertarHijoDrcho(A.raiz(),3);

    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),10);

    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()),22);

    imprimirAbin(A);

    eliminar(A);

    std::cout<<"Estado Nuevo:"<<std::endl;
    imprimirAbin(A);

    return 0;
}