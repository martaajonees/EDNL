/*
Contar el número de nodos de un árbol binario que tienen exactamente 3 nietos
*/

#include "../abin.hpp"
//Cabeceras-------
template<typename T>
int nodoverde(Abin<T> A); //1º llamada
template<typename T>
int nodoverdeRec(Abin<T> A, typename Abin<T>::nodo n);
template<typename T>
int numNietos(Abin<T> A, typename Abin<T>::nodo n);
template<typename T>
int numHijos(Abin<T> A, typename Abin<T>::nodo n);

//Funciones----

template<typename T>
int nodoverde(Abin<T> A){
    return nodoverdeRec(A,A.raiz());
}
//Dado un árbol, contar cuantos nodos cumplen que tienen mas de 3 nietos
template<typename T>
int nodoverdeRec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0; //Si el nodo actual es nulo, devuelve 0
    else{ 
        if(numNietos(A,n)==3) return 1+nodoverdeRec(A, A.hijoDrcho(n))+nodoverdeRec(A, A.hijoIzqdo(n));
        else return nodoverdeRec(A, A.hijoDrcho(n))+nodoverdeRec(A, A.hijoIzqdo(n));
    }
}

//Dado un nodo, cuenta sus nietos
template<typename T>
int numNietos(Abin<T> A, typename Abin<T>::nodo n){
    if(n==Abin<T>::NODO_NULO)return 0; //Si el nodo es nulo, devuelve 0
    else{
        return numHijos(A, A.hijoDrcho(n))+ numHijos(A, A.hijoIzqdo(n));
    }
}


//Dado un nodo, cuenta sus hijos.
template<typename T>
int numHijos(Abin<T> A, typename Abin<T>::nodo n){
   if(n==Abin<T>::NODO_NULO) return 0;
   else{
    int hijos =0;
    if(A.hijoDrcho(n)!=Abin<T>::NODO_NULO) hijos++;
    if(A.hijoIzqdo(n)!= Abin<T>::NODO_NULO) hijos++;
    return hijos;
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
    cout<<"tiene "<<numHijos(A,A.hijoDrcho(A.raiz()))<<" hijos"<<endl;
    cout<<"tiene "<<numNietos(A,A.raiz())<<" nietos"<<endl;
    cout<<"hay "<<nodoverde(A)<<" nodos que cumplen la condicion"<<endl;
}
