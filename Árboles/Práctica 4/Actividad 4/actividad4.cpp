// Cabecera ------------------------

typedef Abb<int> Conjunto;

Conjunto interseccion(const Conjunto& A, const Conjunto& B);

void interseccionRec(Conjunto& Inter, const Conjunto& A, const Conjunto& B);

// Funciones -----------------------

Conjunto interseccion(const Conjunto& A, const Conjunto& B) {
    Conjunto Inter(A);
    if(!B.vacio()){
        interseccionRec(Inter, A, B);
    }
    equilibrar(Inter);
    return Inter;
}

void interseccionRec(Conjunto& Inter, const Conjunto& A, const Conjunto& B){
    if(!B.buscar(A.elemento()).vacio()) Inter.insertar(A.elemento());
    if(!A.izqdo().vacio()) interseccionRec(Inter, A.izqdo(), B);
    if(!A.drcho().vacio()) interseccionRec(Inter, A.drcho(), B);
}
