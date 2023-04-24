/*
 Implementa un subprograma que calcule el número de nodos de un 
 árbol binario.
*/
#include<iostream>
#include "../abin.hpp"
template<typename T>
int numNodos(Abin<T> A); //Hace la primera llamada
template<typename T> //Calcula el número de nodos en un árbol dado
int numNodosRec(Abin<T> A, typename Abin<T>::nodo n);

template<typename T>
int numNodos(Abin<T> A){
    return numNodosRec(A, A.raiz());
}

template<typename T>
int numNodosRec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else{
        return 1+ numNodosRec(A, A.hijoDrcho(n))+ numNodosRec(A, A.hijoIzqdo(n));
    }
}

int main(){
    /*       1
            /  \ 
          2     3 
         / \    /\
        4  5   6  7 */
    Abin<int> A;
    A.insertarRaiz(1);
    A.insertarHijoDrcho(A.raiz(),3);
    A.insertarHijoIzqdo(A.raiz(),2);
    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()),7);
    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()),6);
    A.insertarHijoDrcho(A.hijoIzqdo(A.raiz()),5);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),4);
    //Llamamos a la función recursiva
    cout<<"Tiene "<<numNodos(A)<<" nodos";

}
