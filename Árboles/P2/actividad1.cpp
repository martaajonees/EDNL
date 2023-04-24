/*
Dos árboles binarios son similares cuando tienen idéntica estructura 
de ramificación, es decir, ambos son vacíos, o en caso contrario, 
tienen subárboles izquierdo y derecho similares. Implementa un 
subprograma que determine si dos árboles binarios son similares. 
*/

#include "../abin.hpp"
template<typename T>
bool similar(Abin<T> A, Abin<T> B);
template<typename T>
bool similarRec(Abin<T> A, Abin<T> B, typename Abin<T>::nodo n1,typename Abin<T>::nodo n2);

template<typename T>
bool similar(Abin<T> A, Abin<T> B){
    return similarRec(A, B, A.raiz(), B.raiz());
}

template<typename T>
bool similarRec(Abin<T> A, Abin<T> B, typename Abin<T>::nodo n1,typename Abin<T>::nodo n2){
    if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO) return true;
    else if(n1 == Abin<T>::NODO_NULO || n2 == Abin<T>::NODO_NULO) return false;
   else return similarRec(A, B, A.hijoDrcho(n1), B.hijoDrcho(n2)) && similarRec(A, B, A.hijoIzqdo(n1), B.hijoIzqdo(n2));
}

int main(){
    /*
     1                 4
    / \               / \
   2   3             5   6
    */
   
    Abin<int> A;
    A.insertarRaiz(1);
    A.insertarHijoDrcho(A.raiz(),3);
    A.insertarHijoIzqdo(A.raiz(),2);
    Abin<int> B;
    B.insertarRaiz(4);
    B.insertarHijoDrcho(B.raiz(),6);
    //B.insertarHijoIzqdo(B.raiz(),5);

    if(similar(A,B)) cout<<"Similar"<<endl;
    else cout<<"No similar"<<endl;
}