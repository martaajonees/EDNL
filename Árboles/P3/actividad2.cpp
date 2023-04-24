/*
Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine 
la profundidad de éste nodo en el árbol. 
*/

#include "../agen.hpp"
#include<iostream>
using namespace std;
/* Cabecera ----------*/
template<typename T>
int profundidad(Agen<T> A, typename Agen<T>::nodo n);


/* Funciones ----------*/

template<typename T>
int profundidad(Agen<T> A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return -1;
    else{
        return 1 + profundidad(A, A.padre(n));
    }
}

int main(){
    /*
             1
            / \
           2   3
          / \   \
         4   5   6

    */

    Agen<int> A(7); // Crear árbol con 6 nodos
    A.insertarRaiz(1); // Insertar raíz con valor 1
    A.insertarHijoIzqdo(A.raiz(), 2); // Insertar hijo izquierdo de la raíz con valor 2
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), 3); // Insertar hermano derecho del hijo izquierdo de la raíz con valor 3
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 4); // Insertar hijo izquierdo del hijo izquierdo de la raíz con valor 4
    A.insertarHermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), 5); 
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), 6); // Insertar hermano derecho del hijo izquierdo de la raíz con valor 6
    cout<<"La profundidad es: "<< profundidad(A, A.hijoIzqdo(A.hijoIzqdo(A.raiz())));
    return 0;
}