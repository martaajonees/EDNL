/*
El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de 
expresión. 

Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto de los 
nodos los operadores. 

a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar 
operadores y operandos. 

b) Implementa una función que tome un árbol binario de expresión (aritmética) y 
devuelva el resultado de la misma. 

Por simplificar el problema se puede asumir que el árbol representa una expresión correcta. 
Los operadores binarios posibles en la expresión aritmética serán suma, resta, 
multiplicación y división. 
*/
#include "../abin.hpp"
#include<iostream>
using namespace std;


struct NodoExpr{
    NodoExpr(char o):operador(o),esOperador(true){}
    NodoExpr(double o):operando(o),esOperador(false){}
    bool esOperador;
    char operador;
    double operando;
};


double expresionRec(Abin<NodoExpr> A, Abin<NodoExpr>::nodo n){
    if(A.hijoIzqdo(n)== Abin<NodoExpr>::NODO_NULO){
        return A.elemento(n).operando;
    }else{
        switch (A.elemento(n).operador)
        {
        case '+':
            return expresionRec(A, A.hijoIzqdo(n)) + expresionRec(A, A.hijoDrcho(n));
            break;
        case '-':
            return expresionRec(A, A.hijoIzqdo(n)) - expresionRec(A, A.hijoDrcho(n));
            break;
        case '*':
            return expresionRec(A, A.hijoIzqdo(n)) * expresionRec(A, A.hijoDrcho(n));
            break;
        case '/' :
            return expresionRec(A, A.hijoIzqdo(n)) / expresionRec(A, A.hijoDrcho(n));
            break;
        default:
            return 0;
            break;
        }
    }
}

double expresion(Abin<NodoExpr> A){
    assert(!A.arbolVacio());
    return expresionRec(A, A.raiz());
}