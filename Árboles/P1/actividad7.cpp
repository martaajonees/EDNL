/*
Implementa un subprograma que determine si un árbol binario es o no pseudocompleto. 
En este problema entenderemos que un  árbol es pseudocompleto, si en el penúltimo 
nivel del mismo cada uno de los nodos tiene dos hijos o ninguno.
*/

#include "../abin.hpp"
#include "actividad2.cpp"
template<typename T>
bool pseudocompleto(Abin<T> A); //1º llamada
template<typename T>
bool pseudocompletoRec(Abin<T> A, typename Abin<T>::nodo n, int altura);

template<typename T>
bool pseudocompleto(Abin<T> A){
    return pseudocompletoRec(A, A.raiz(), numAltura(A));
}

template<typename T>
bool pseudocompletoRec(Abin<T> A, typename Abin<T>::nodo n, int altura){
    if(A.profundidad(n)==altura-1){ //estamos en el nivel
        if((A.hijoDrcho(n)!= Abin<T>::NODO_NULO && A.hijoDrcho(n)!= Abin<T>::NODO_NULO)||
        (A.hijoDrcho(n)== Abin<T>::NODO_NULO && A.hijoDrcho(n)== Abin<T>::NODO_NULO) ) return true;
        else return false;

    }else return pseudocompletoRec(A, A.hijoDrcho(n), altura) && pseudocompletoRec(A, A.hijoIzqdo(n), altura);
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
    //A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),4);
    //Llamamos a la función recursiva
    if(pseudocompleto(A)) printf("Es pseudocompleto");
    else printf("No es pseudocompleto");
}