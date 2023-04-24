/*
En un videojuego de aventuras, el jugador avanza a través de niveles que están 
organizados en un árbol binario. Cada nivel tiene una dificultad asignada, representada 
por un valor entero positivo. Cada vez que el jugador completa un nivel, recibe una 
cantidad de puntos igual a la dificultad del nivel.

El objetivo del jugador es obtener la mayor cantidad de puntos posible al completar 
todos los niveles. Sin embargo, el jugador solo puede avanzar a un nivel si ha completado 
exitosamente sus dos niveles hijos (en caso de tenerlos). Si el jugador falla en completar 
un nivel, no podrá avanzar a los siguientes niveles.

Escribe una función en C++ que reciba un árbol binario que representa los niveles del 
videojuego y determine la mayor cantidad de puntos que el jugador puede obtener al 
completar todos los niveles posibles. 
*/
#include "../abin.hpp"

struct Nivel{
    int numNivel;
    int dificultad;
    bool exito;
};

template<typename Nivel>
int maxpuntos(Abin<Nivel> A){
    return maxpuntosRec(A, A.raiz());
}

template<typename Nivel>
int maxpuntosRec(Abin<Nivel> A, typename Abin<Nivel>::nodo n){
    if(n == Abin<Nivel>::NODO_NULO) return 0;
    else{
        // Compruebo que se han completado los niveles anteriores
        if(nivelAntes(A,n, A.elemento(n).numNivel)) {
            return A.elemento(n).dificultad + maxpuntosRec(A, A.hijoDrcho(n)) + maxpuntosRec(A, A.hijoIzqdo(n));
        }else return 0;
    }
}

template<typename Nivel>
bool nivelAntes(Abin<Nivel> A, typename Abin<Nivel>::nodo n, int numNivel){
    if(A.elemento(n).numNivel == numNivel) return true;
    else{
        if(A.elemento(n).numNivel < numNivel){
            return A.elemento(n).exito && nivelAntes(A, A.hijoDrcho(n), numNivel) && nivelAntes(A, A.hijoIzqdo(n), numNivel);
            
        }else{
            return nivelAntes(A, A.hijoDrcho(n), numNivel) && nivelAntes(A, A.hijoIzqdo(n), numNivel)
        }
    }
}