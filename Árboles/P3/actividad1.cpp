/*
Implementa un subprograma que dado un árbol general nos calcule su grado
*/

#include "../agen.hpp"
#include<iostream>
using namespace std;
/* Cabeceras -----------*/
template<typename T>
int numGrado(Agen<T> A);

template<typename T>
int numGradoRec(Agen<T> A, typename Agen<T>::nodo n);

template<typename T>
int numHijos(Agen<T> A, typename Agen<T>::nodo n);


/* Funciones ---------------*/

template<typename T>
int numGrado(Agen<T> A){
    return numGradoRec(A, A.raiz());
}

template<typename T>
int numGradoRec(Agen<T> A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return -1;
    else{
        int gradomax = numHijos(A, n); //Grado del nodo actual
        typename Agen<T>::nodo aux = A.hijoIzqdo(n); 
        //Empezamos a buscar desde la izquierda
        while(aux != Agen<T>::NODO_NULO){
            gradomax = max(gradomax,numGradoRec(A, aux)); 
            // Llamamos de cada nodo a sus hijos
            aux = A.hermDrcho(aux);
        }
       return gradomax;
    }
}

//Dado un nodo, calcula el numero de sus hijos
template<typename T>
int numHijos(Agen<T> A, typename Agen<T>::nodo n){
    int hijo = 0;
    typename Agen<T>::nodo aux=A.hijoIzqdo(n);
    while(aux!=Agen<T>::NODO_NULO){
        hijo++;
        aux = A.hermDrcho(aux);
    }
    return hijo;
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
    cout<<"El numero de hijos es: "<< numHijos(A, A.hijoIzqdo(A.raiz()))<< "\n";
    cout<<"El grado es: "<< numGrado(A);
    return 0;
}