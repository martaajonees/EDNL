
// Cabecera ------------------------
typedef Abb<int> Conjunto;

Conjunto operador(const Conjunto& A, const Conjunto& B);

Conjunto diferencia(const Conjunto& A, const Conjunto& B);

void diferenciaRec(const Conjunto& A, const Conjunto& B);

bool pertenece(const Conjunto& A, int elto);

// Funciones -----------------------

bool pertenece(const Conjunto& A, int elto){
    return !(A.buscar(elto).vacio());
}

Conjunto diferencia(const Conjunto& A, const Conjunto& B){
    Conjunto Diferencia(A);
    if(!B.vacio()){
        diferenciaRec(Diferencia, B);
    }
    return Diferencia;
}

void diferenciaRec(Conjunto& Diferencia, const Conjunto& B){
    if(pertenece(Diferencia, B.elemento())) Diferencia.eliminar(B.elemento());

    if(!B.izqdo().vacio()) diferenciaRec(Diferencia, B.izqdo());

    if(!B.drcho().vacio()) diferenciaRec(Diferencia, B.drcho());
    
}

Conjunto operador(const Conjunto& A, const Conjunto& B){
    return diferencia(A, B);
}

