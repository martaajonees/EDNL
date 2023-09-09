
# include "../../Prácticas/agen_enl.hpp"
#include<iostream>
using namespace std;

//Cabeceras


template<typename T>
bool similar(const Agen<T>& A, const Agen<T>& B);

template<typename T>
bool similarRec(const Agen<T>& A, const Agen<T>& B, typename Agen<T>::nodo a, typename Agen<T>::nodo b);

template<typename T>
bool hoja(const Agen<T>& A, typename Agen<T>::nodo a);

// Funciones


template<typename T>
bool similar(const Agen<T>& A, const Agen<T>& B){
    return similarRec(A, B, A.raiz(), B.raiz());
}

template<typename T>
bool similarRec(const Agen<T>& A, const Agen<T>& B, typename Agen<T>::nodo a, typename Agen<T>::nodo b) {
    if(a == Agen<T>::NODO_NULO && b == Agen<T>::NODO_NULO){
        return true; //Los dos árboles están vacíos
    } else if (a == Agen<T>::NODO_NULO || b == Agen<T>::NODO_NULO){
        return false; // Si uno está vacío y otro no, no son similares
    } else { // si ambos tienen elementos
        if(hoja(A, a) && hoja(B, b)){ 
            return A.elemento(a) == B.elemento(b); // Si son hojas, comprobamos los elementos
        } else { // Si no son hojas
            typename Agen<T>::nodo aux_a = A.hijoIzqdo(a);
            typename Agen<T>::nodo aux_b = B.hijoIzqdo(b);
            while(aux_a != Agen<T>::NODO_NULO && aux_b != Agen<T>::NODO_NULO){
                if(!similarRec(A, B, aux_a, aux_b)) return false;

                aux_a = A.hermDrcho(aux_a);
                aux_b = B.hermDrcho(aux_b);
            }
            return aux_a == Agen<T>::NODO_NULO && aux_b == Agen<T>::NODO_NULO;
            //Si un subarbol tiene más elementos que otro, es falso 
        }

    }
}
    
template<typename T>
bool hoja(const Agen<T>& A, typename Agen<T>::nodo a){
    int nhijo = 0;
    typename Agen<T>::nodo n = A.hijoIzqdo(a);
    while(n != Agen<T>::NODO_NULO){
        nhijo++;
        n = A.hermDrcho(n);
    }
    if(nhijo == 0) return true;
    else return false;
}
