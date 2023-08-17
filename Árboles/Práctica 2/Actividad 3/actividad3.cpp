
// Cabeceras -----------------------

double expresion(const Abin<NodoExpr>& A);
double expresionRec(const Abin<NodoExpr>& A, Abin<NodoExpr>::nodo n);

// Funciones ------------------------

struct NodoExpr {
    NodoExpr(char c): esOperador(true), operador(c){}
    NodoExpr(double d): esOperador(false), operando(d){}
    bool esOperador; // Indica si es operador (true) o operando (false)
    char operador;
    double operando;
};

double expresion(const Abin<NodoExpr>& A) {
    return expresionRec(A, A.raiz());
}

double expresionRec(const Abin<NodoExpr>& A, Abin<NodoExpr>::nodo n){
    if(n == Abin<NodoExpr>::NODO_NULO) return A.elemento(n).operando;
    else {
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
        case '/':
            return expresionRec(A, A.hijoIzqdo(n)) / expresionRec(A, A.hijoDrcho(n));
            break;
        default:
            break;
        }
    }
}
