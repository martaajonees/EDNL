/*
Dado un árbol binario de enteros donde el valor de cada nodo es menor que el de sus hijos, 
implementa un subprograma para eliminar un valor del mismo preservando la propiedad 
de orden establecida. Explica razonadamente la elección de la estructura de datos. 
*/

#include "../abin.hpp"
#include "../abin_E-S.h"

/* CABECERAS --------------*/
template<typename T>
void eliminar(Abin<T>& A,int x);

template<typename T>
void eliminarRec(Abin<T>& A,typename Abin<T>::nodo n);

template<typename T>
typename Abin<T>::nodo buscar(Abin<T>& A, int x);

template<typename T>
typename Abin<T>::nodo buscarRec(Abin<T>& A, typename Abin<T>::nodo n ,int x);

template<typename T>
void intercambiar(Abin<T>& A,typename Abin<T>::nodo& n1, typename Abin<T>::nodo& n2);

/* FUNCIONES ----------------------------------*/

template<typename T>
void eliminar(Abin<T>& A,int x){
    return eliminarRec(A, buscar(A,x));
}

template<typename T>
void eliminarRec(Abin<T>& A,typename Abin<T>::nodo n){
    //Si es hoja, eliminamos el nodo
    if(n != Abin<T>::NODO_NULO){ //n no es nulo
        if(A.hijoDrcho(n)!= Abin<T>::NODO_NULO && A.hijoIzqdo(n)!= Abin<T>::NODO_NULO){
        //Si es menor el derecho
            if(A.elemento(A.hijoDrcho(n))< A.elemento(A.hijoIzqdo(n))){ 
                intercambiar(A, A.hijoDrcho(n), n);
                eliminarRec(A,A.hijoDrcho(n));
            }else if(A.elemento(A.hijoDrcho(n))> A.elemento(A.hijoIzqdo(n))){
                intercambiar(A, A.hijoIzqdo(n), n);
                eliminarRec(A,A.hijoIzqdo(n));
            }
        }else if(A.hijoDrcho(n)== Abin<T>::NODO_NULO && A.hijoIzqdo(n)== Abin<T>::NODO_NULO){
            EliminarNodo(A,n);
        }else if (A.hijoDrcho(n)!= Abin<T>::NODO_NULO && A.hijoIzqdo(n)== Abin<T>::NODO_NULO)
        {
            intercambiar(A, A.hijoDrcho(n), n);
            eliminarRec(A,A.hijoDrcho(n));
        }else{
            intercambiar(A, A.hijoIzqdo(n), n);
            eliminarRec(A,A.hijoIzqdo(n));
        }
        
    }
}
template<typename T>
void intercambiar(Abin<T>& A,typename Abin<T>::nodo& n1, typename Abin<T>::nodo& n2){
    int valor;
    valor = A.elemento(n2);
    A.elemento(n2) = A.elemento(n1);
    A.elemento(n1)= valor;

}

//Dado un elemento y un arbol buscamos
template<typename T>
typename Abin<T>::nodo buscar(Abin<T>& A, int x){
    typename Abin<T>::nodo n;
    return buscarRec(A, A.raiz(), x);
}

template<typename T>
typename Abin<T>::nodo buscarRec(Abin<T>& A, typename Abin<T>::nodo n ,int x){
    if(A.elemento(n) == x) return n; //Si encontramos el elemento, lo devolvemos
    else{
        buscarRec(A, A.hijoDrcho(n), x);  
        buscarRec(A, A.hijoIzqdo(n), x);
        return Abin<T>::NODO_NULO;
    }
}
 //Dado un nodo, lo eliminamos
template<typename T>
void EliminarNodo(Abin<T>& A, typename Abin<T>::nodo n){
    typename Abin<T>::nodo padre = A.padre(n);
    if(A.hijoDrcho(padre)==n) A.eliminarHijoDrcho(padre);
    else A.eliminarHijoIzqdo(padre);
}

int main() {
    // Creamos un árbol binario con los valores 1, 2, 3, 4, 5, 6
    Abin<int> arbol;
    arbol.insertarRaiz(1);
    arbol.insertarHijoIzqdo(arbol.raiz(), 2);
    arbol.insertarHijoDrcho(arbol.raiz(), 3);
    arbol.insertarHijoIzqdo(arbol.hijoIzqdo(arbol.raiz()), 4);
    arbol.insertarHijoDrcho(arbol.hijoDrcho(arbol.raiz()), 5);
    arbol.insertarHijoDrcho(arbol.hijoDrcho(arbol.hijoDrcho(arbol.raiz())), 6);
    
    // Imprimimos el árbol original
    cout << "Arbol original:" << endl;
    imprimirAbin(arbol);
    
    // Eliminamos el valor 5
    eliminar(arbol, 5);
    
    // Imprimimos el árbol resultante
    cout << "Arbol resultante:" << endl;
    imprimirAbin(arbol);
    
    return 0;
}