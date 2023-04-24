#include "../abin_E-S.h"
#include "../abin.hpp"

/*
Se tiene un árbol binario en el que cada nodo representa una persona y tiene asociado 
un monto de dinero. El objetivo es implementar una función en C++ que reciba un nodo 
del árbol y reparta su herencia entre sus descendientes vivos, es decir, aquellos 
que están más abajo en el árbol y que no han sido marcados como muertos.

La función deberá eliminar el nodo pasado como argumento y repartir su dinero entre 
sus descendientes vivos. Si el nodo no tiene descendientes vivos, su dinero se pierde.

Para realizar la repartición de la herencia, se debe sumar el dinero del nodo y 
distribuirlo entre los descendientes vivos de manera equitativa. Si la división 
no es exacta, se debe asignar el dinero sobrante al primer descendiente en orden 
de recorrido en preorden que tenga menos dinero.

En todo momento se debe mantener la estructura del árbol binario, es decir, 
los descendientes de un nodo eliminado deben ser agregados como descendientes 
de su padre, si este existe.
*/

struct Persona{
    bool muerto;
    float dinero;
};

//
template<typename Persona>
void reparto(Abin<Persona>& A, typename Abin<Persona>::nodo n){
    float dinero_descendencia = A.elemento(n).dinero /descendencia(A, n);
    return repartoRec(A, n, dinero_descendencia);
}

void repartoRec(Abin<Persona>& A, typename Abin<Persona>::nodo n, float dinero_descendencia ){
    if(n != Abin<Persona>::NODO_NULO){ 
        if(!A.elemento(n).muerto){
        //Le reparte el dinero a los vivos
        A.elemento(n).dinero += dinero_descendencia;
        //Llamada recursiva a los hijos derecho e izquierdo
        repartoRec(A, A.hijoDrcho(n), dinero_descendencia);
        repartoRec(A, A.hijoIzqdo(n), dinero_descendencia);
        }else{
            //Llamada recursiva a los hijos derecho e izquierdo
            repartoRec(A, A.hijoDrcho(n), dinero_descendencia);
            repartoRec(A, A.hijoIzqdo(n), dinero_descendencia);
        }
    }
    
}


//Le da un nodo, calcula la descendencia del nodo
int descendencia(Abin<Persona>A, typename Abin<Persona>::nodo n){
    if(n == Abin<Persona>::NODO_NULO) return 0;
    else{
        return 1 + descendencia(A, A.hijoDrcho(n)) + descendencia(A, A.hijoIzqdo(n));
    }
}