#include"agenenla.hpp"
#include<iostream>
using namespace std;

template<typename T>
void imprimirAgen(const Agen<T>& A);

template<typename T>
void imprimirAgenRec(const Agen<T>& A, typename Agen<T>::nodo n, int nivel);

template<typename T>
void imprimirAgen(const Agen<T>& A) {
    imprimirAgenRec(A, A.raiz(), 0);
}

template<typename T>
void imprimirAgenRec(const Agen<T>& A, typename Agen<T>::nodo n, int nivel) {
    for (int i = 0; i < nivel; i++) {
        std::cout << "  ";
    }
    std::cout << "|__" << A.elemento(n) << std::endl;

    for (typename Agen<T>::nodo hijo = A.hijoIzqdo(n); hijo != Agen<T>::NODO_NULO; hijo = A.hermDrcho(hijo)) {
        imprimirAgenRec(A, hijo, nivel+1);
    }
}