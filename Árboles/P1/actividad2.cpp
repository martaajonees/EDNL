/*
Implementa un subprograma que calcule la altura de un árbol binario. 
*/

#include"../abin.hpp"
template<typename T>
int numAltura(Abin<T> A); //Hace la primera llamada

template<typename T>
int numAlturaRec(Abin<T> A, typename Abin<T>::nodo n);

template<typename T>
int numAltura(Abin<T> A){
    return numAlturaRec(A, A.raiz());
}

template<typename T>
int numAlturaRec(Abin<T> A, typename Abin<T>::nodo n){
    if(A.arbolVacio()) return -1; //Si está vacío, devuelve -1
    else{
        if(n == Abin<T>::NODO_NULO) return 0; //Si n es hoja devuelve 0
        else{
            return 1 + max(numAlturaRec(A, A.hijoDrcho(n)), numAlturaRec(A, A.hijoIzqdo(n)));
        }
    }
}

/* 
int main(){
          1
            /  \ 
          2     3 
         / \    /\
        4  5   6  7 
    Abin<int> A;
    A.insertarRaiz(1);
    A.insertarHijoDrcho(A.raiz(),3);
    A.insertarHijoIzqdo(A.raiz(),2);
    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()),7);
    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()),6);
    A.insertarHijoDrcho(A.hijoIzqdo(A.raiz()),5);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),4);
    //Llamamos a la función recursiva
    cout<<"Su altura es "<<numAltura(A);

}
*/