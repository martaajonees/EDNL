/*
Parcial 2020
*/
#include "../abin.hpp"

struct Proposicion{
    Proposicion(int o): operando(o), esOperador(false){}
    Proposicion(char o): operador(o), esOperador(true){}
    bool esOperador;
    char operador;
    int operando;
};

template<typename T>
bool solve_proposicion(Abin<Proposicion> A, typename Abin<Proposicion>::nodo n, const vector<bool>& valoraciones){
    // Si es una hoja (es decir, una variable proposicional), devolver su valor de verdad
    if(!A.elemento(n).esOperador) return valoraciones[A.elemento(n).operando];
    // Si es un nodo interno, aplicar la operación lógica correspondiente
    else{
        switch (A.elemento(n).operador)
        {
            case 'Y': return solve_proposicion(A, A.hijoIzqdo(n), valoraciones) && solve_proposicion(A, A.hijoDrcho(n), valoraciones);
            break;
            case 'O': return solve_proposicion(A, A.hijoIzqdo(n), valoraciones) || solve_proposicion(A, A.hijoDrcho(n), valoraciones);
            break;
            case 'N': return !solve_proposicion(A, A.hijoIzqdo(n), valoraciones);
            break;
            default:
            return false;
        }
    }
}
