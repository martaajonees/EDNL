/*
Contar el número de nodos de un árbol binario que tienen el doble de nietos que de bisnietos
*/

#include "../abin.hpp"
//Dado un nodo, cuenta sus hijos
template<typename T>
int numHijos(Abin<T> A, typename Abin<T>::nodo n);
//Dado un nodo, cuenta sus nietos
template<typename T>
int numNietos(Abin<T> A, typename Abin<T>::nodo n);
//Dado un nodo, cuenta sus bisnietos
template<typename T>
int numBisnietos(Abin<T> A, typename Abin<T>::nodo n);
//1º llamada
template<typename T>
int nodosverdes(Abin<T> A);
template<typename T>
int nodosverdesRec(Abin<T> A, typename Abin<T>::nodo n);

//Funciones
template<typename T>
int numHijos(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else{
        int hijos=0;
        if(A.hijoDrcho(n)!= Abin<T>::NODO_NULO) hijos++;
        if(A.hijoIzqdo(n)!= Abin<T>::NODO_NULO) hijos++;
        return hijos;
    }
}

template<typename T>
int numNietos(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else return numHijos(A,A.hijoDrcho(n)) + numHijos(A,A.hijoIzqdo(n));
    
}
template<typename T>
int numBisnietos(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else return numNietos(A, A.hijoDrcho(n))+ numNietos(A, A.hijoIzqdo(n));
}

template<typename T>
int nodosverdes(Abin<T> A){return nodosverdesRec(A, A.raiz());}

template<typename T>
int nodosverdesRec(Abin<T> A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO) return 0;
    else{
        if(2*numBisnietos(A,n)==numNietos(A,n) && A.profundidad(n)>=3) return 1+ nodosverdesRec(A, A.hijoDrcho(n))+nodosverdesRec(A, A.hijoIzqdo(n));
        else return nodosverdesRec(A, A.hijoDrcho(n))+nodosverdesRec(A, A.hijoIzqdo(n));
    }
}

int main(){
     /*       1
            /  \ 
          2     3 
         / \    /\
        4  5   6  7
       / \  
      8   9  */
    Abin<int> A;
    A.insertarRaiz(1);
    A.insertarHijoDrcho(A.raiz(),3);
    A.insertarHijoIzqdo(A.raiz(),2);
    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()),7);
    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()),6);
    A.insertarHijoDrcho(A.hijoIzqdo(A.raiz()),5);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),4);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),8);
    A.insertarHijoDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),9);
    //A.insertarHijoDrcho(A.hijoDrcho(A.hijoIzqdo(A.raiz())),10);
    //Llamamos a la función recursiva
    cout<<"Tiene "<<numHijos(A,A.raiz())<<" hijos"<<endl;
    cout<<"tiene "<<numNietos(A,A.hijoIzqdo(A.raiz()))<<" nietos"<<endl;
    cout<<"tiene "<<numBisnietos(A,A.hijoIzqdo(A.raiz()))<<" bisnietos"<<endl;
    cout<<"hay "<<nodosverdes(A)<<" nodos que cumplen la condicion"<<endl;
}
