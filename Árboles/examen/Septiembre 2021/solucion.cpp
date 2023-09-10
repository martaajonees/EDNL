
# include "../../Prácticas/abin.hpp"
#include <iostream>
using namespace std;

// Cabecera
struct Persona;

void repartir(const Abin<Persona>& A, Abin<Persona>::nodo n);

void repartir_equitativo(const Abin<Persona>& A, Abin<Persona>::nodo n, double dinero);

int descendientes_vivos(const Abin<Persona>& A, Abin<Persona>::nodo n);

// Funciones

struct Persona {
    mutable int dinero;
    mutable bool esta_vivo;
};

void herencia(const Abin<Persona>& A, Abin<Persona>::nodo h){
    if(h != Abin<Persona>::NODO_NULO){
        A.elemento(h).esta_vivo = false; //Eliminamos el nodo
        repartir(A, h); // Repartir dinero de la herencia
    }

}

int descendientes_vivos(const Abin<Persona>& A, Abin<Persona>::nodo n){
    if(n == Abin<Persona>::NODO_NULO){
        return 0; // Llegó al final
    } else {
        if(A.elemento(n).esta_vivo){
            return 1 + descendientes_vivos(A, A.hijoDrcho(n)) + descendientes_vivos(A, A.hijoIzqdo(n));
        } else {
             return 0 + descendientes_vivos(A, A.hijoDrcho(n)) + descendientes_vivos(A, A.hijoIzqdo(n));
        }
    }
}

void repartir(const Abin<Persona>& A, Abin<Persona>::nodo n){
    if(n == Abin<Persona>::NODO_NULO){
        return;
    } else {
        //Dividimos dinero
        int hijos = descendientes_vivos(A, n);

        if(hijos > 0){ // Los hijos deben ser mayor que 0 para repartirlos
            int dinero = A.elemento(n).dinero/hijos;
            repartir_equitativo(A, n, dinero);

            //El sobrante se lo repartimos al primer nodo en preorden
            int restante = A.elemento(n).dinero - (dinero * hijos);
            asignar_sobrante(A, n, restante);

        } else { // Si no tiene descendencia el dinero se pierde
            A.elemento(n).dinero = 0;
        }
    }
}

void repartir_equitativo (const Abin<Persona>& A, Abin<Persona>::nodo n, double dinero){
    if(n == Abin<Persona>::NODO_NULO){
        return;
    } else {
        if(A.elemento(n).esta_vivo){
            A.elemento(n).dinero += dinero;
        } else {
            repartir_equitativo(A, A.hijoDrcho(n), dinero);
            repartir_equitativo(A, A.hijoIzqdo(n), dinero);
        }
    }
}

void asignar_sobrante(const Abin<Persona>& A, Abin<Persona>::nodo n, double sobras){
     if(n == Abin<Persona>::NODO_NULO){
        return;
    } else {
        if(A.elemento(n).esta_vivo){
            A.elemento(n).dinero += sobras;
            return;
        } else {
            repartir_equitativo(A, A.hijoIzqdo(n), sobras);
            repartir_equitativo(A, A.hijoDrcho(n), sobras);
        }
    }
}
