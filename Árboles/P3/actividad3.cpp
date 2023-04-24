/*
Se define el desequilibrio de un árbol general como la máxima diferencia 
entre las alturas de los subárboles más bajo y más alto de cada nivel. 

Implementa un subprograma que calcule el grado de desequilibrio de un árbol 
general. 
*/
#include "../agen.hpp"
#include<iostream>
using namespace std;

template<typename T>
int desequilibrioRec(Agen<T> A, typename Agen<T>::nodo n);
template<typename T>
int desequilibrio(Agen<T> A);

template<typename T>
int numAltura(Agen<T> A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return 0;
    else{
        return 1+ numAltura(A, A.hijoIzqdo(n));
    }
}

template<typename T>
int desequilibrio(Agen<T> A){
    return desequilibrioRec(A, A.raiz());
}

template<typename T>
int desequilibrioRec(Agen<T> A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return 0;
    else{
        int altmax = 0, altmin= 9999, maxim;
        typename Agen<T>::nodo aux = A.hijoIzqdo(n);
        while (aux != Agen<T>::NODO_NULO)
        {
            altmax = max(numAltura(A, aux), altmax);
            altmin= min(numAltura(A, n), altmin);
            maxim = max(desequilibrioRec(A, aux), maxim);
            aux = A.hermDrcho(aux);
        }
        return max(maxim, altmax-altmin);
    }
}