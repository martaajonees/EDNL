/*
Contar el número de nodos de un árbol binario que son nostálgicos. Definimos un nodo 
nostálgico como  aquel que tiene más pasado que futuro, es decir son los nodos que 
tienen más antecesores propios que descendientes propios.
*/
#include "../abin.hpp"
//Dado un nodo, el número de antecesores
template<typename T>
int numAntecesores(Abin<T> A, typename Abin<T>::nodo n);
//Dado un nodo, el número de descendientes
template<typename T>
int numDescendientes(Abin<T> A, typename Abin<T>::nodo n);
template<typename T>
int nostalgico(Abin<T> A);
template<typename T>
int nostalgicoRec(Abin<T> A, typename Abin<T>::nodo n);
//Funciones---

template<typename T>
int numAntecesores(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO || n == A.raiz()) return 0;
    else return 1 + numAntecesores(A, A.padre(n));
}

template<typename T>
int numDescendientes(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else return 1+ numDescendientes(A, A.hijoDrcho(n))+ numDescendientes(A, A.hijoIzqdo(n));
}
template<typename T>
int nostalgico(Abin<T> A){
    return nostalgicoRec(A, A.raiz());
}
template<typename T>
int nostalgicoRec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else{
        if((numAntecesores(A,n)-1)>numDescendientes(A,n)) 
        return 1+ nostalgicoRec(A, A.hijoDrcho(n))+nostalgicoRec(A, A.hijoIzqdo(n));
        else return nostalgicoRec(A, A.hijoDrcho(n))+nostalgicoRec(A, A.hijoIzqdo(n));
    }
}

int main(){
     /*       1
            /  \ 
          2     3 
         / \    /\
        4  5   6  7
       / \
      8   9 */
    Abin<int> A;
    A.insertarRaiz(1);
    A.insertarHijoDrcho(A.raiz(),3);
    A.insertarHijoIzqdo(A.raiz(),2);
    //A.insertarHijoDrcho(A.hijoDrcho(A.raiz()),7);
    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()),6);
    A.insertarHijoDrcho(A.hijoIzqdo(A.raiz()),5);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),4);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),8);
    A.insertarHijoDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),9);

    //Llamamos a la función recursiva
    cout<<"tiene "<<numAntecesores(A, A.raiz())-1<<" antecesores"<<endl;
    cout<<"tiene "<<numDescendientes(A,A.raiz())<<" descendientes"<<endl;
    cout<<"hay "<<nostalgico(A)<<" nodos que cumplen la condicion"<<endl;
}
