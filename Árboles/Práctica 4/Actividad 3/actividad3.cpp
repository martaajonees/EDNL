// Cabecera ------------------------

typedef Abb<int> Conjunto;

Conjunto unionAbb(const Conjunto& A, const Conjunto& B);

Conjunto unionAbbRec(Conjunto& Union, const Conjunto& B);

// Funciones -----------------------

Conjunto unionAbb(const Conjunto& A, const Conjunto& B) {
    Conjunto Union(A);
    if(!B.vacio()) {
        unionAbbRec(Union, B);
    }
    equilibrar(Union);
    return Union;
}

Conjunto unionAbbRec(Conjunto& Union, const Conjunto& B) {
    if(!B.izqdo().vacio()) unionAbbRec(Union, B.izqdo());
    if(!B.drcho().vacio()) unionAbbRec(Union, B.drcho());

    Union.insertar(B.elemento());
}
