/* 
Implementa un subprograma que determine el nivel de desequilibrio 
de un árbol binario, definido como el máximo desequilibrio de todos
sus nodos. El desequilibrio de un nodo se define como la diferencia 
entre las alturas de los subárboles del mismo. 
*/
#include "../abin.hpp"
#include "actividad2.cpp"
template<typename T>
int desequilibrio(Abin<T> A);
template<typename T>
int desequilibrioRec(Abin<T> A, typename Abin<T>::nodo n);

template<typename T>
int desequilibrio(Abin<T> A){
    return desequilibrioRec(A, A.raiz());
}

template<typename T>
int desequilibrioRec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else{
        int altder, altizq, maxim;
        altder = numAlturaRec(A, A.hijoDrcho(n));
        altizq = numAlturaRec(A, A.hijoIzqdo(n));
        maxim = max(desequilibrioRec(A,A.hijoDrcho(n)), desequilibrioRec(A, A.hijoIzqdo(n)));
        return  max(maxim, altder - altizq);
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
    cout<<"Su desequilibrio es: "<<desequilibrio(A);
}