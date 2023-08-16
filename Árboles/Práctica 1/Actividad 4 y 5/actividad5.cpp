/*IMPLEMENTACIÓN DE UN ARBOL BINARIO USANDO CELDAS ENLAZADAS*/
template <typename T> class Abin {
    struct celda;
    public: 
    typedef celda* nodo;
    static const nodo NODO_NULO;
    Abin();
    void insertarRaiz(const T& e);//Recibe lo que va a contener la raiz
    void insertarHijoIzqdo(nodo n, const T&e); //nombre del nodo padre y lo que contiene
    void insertarHijoDrcho(nodo n, const T& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();
    int profundidad(nodo n);
    int altura(nodo n);
    bool arbolVacio() const;
    const T& elemento(nodo n) const;
    T& elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    Abin(const Abin<T>& a); // ctor. de copia 
    Abin<T>& operator =(const Abin<T>& A); // asig.de árboles 
    ~Abin(); // destructor
    private:
        struct celda {
        T elto;
        nodo padre, hizq, hder;
        celda(const T& e, nodo p = NODO_NULO): elto(e),
        padre(p), hizq(NODO_NULO), hder(NODO_NULO) {} 
        };
        nodo r;   // nodo raíz del árbol
        void destruirNodos(nodo& n);
        nodo copiar(nodo n);
};
/* EJERCICIO 5 */
template<typename T>
int Abin<T>::profundidad(nodo n){
    if(n == raiz()) return 0;
    else {
        return 1 + profundidad(padre(n));
    }
}

template<typename T>
int Abin<T>::altura(nodo n){
    if(n == NODO_NULO) return 0;
    else {
        return 1 + max(altura(hijoDrcho(n)), altura(hijoIzqdo(n)));
    }
}
