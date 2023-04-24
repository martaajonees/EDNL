#include<iostream>
using namespace std;

/*IMPLEMENTACIÓN DE UN ARBOL BINARIO USANDO CELDAS ENLAZADAS*/
#ifndef ABIN_H
#define ABIN_H
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
    int profundidad(nodo n); //Ejercicio 5
    int altura(nodo n); //Ejercicio 5
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

/*Definición del nodo nulo*/
template<typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(nullptr);

template <typename T>
inline Abin<T>::Abin() : r(NODO_NULO) {} //Inicializamos raiz a NODO_NULO

template <typename T>
inline void Abin<T>::insertarRaiz(const T& e) {
   assert(r == NODO_NULO);   // Árbol vacío
   r = new celda(e);        //Creamos nueva celda a la raiz e dada
}
template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e) {
    assert(n != NODO_NULO); //Existe
    assert(n->hizq == NODO_NULO); //No tenga hijo izquierdo
    n->hizq = new celda(e, n); //Creamos nueva celda al nodo e cuyo padre sea n
}
template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e) {
    assert(n != NODO_NULO); //existe
    assert(n->hder == NODO_NULO); // No tenga hijo drcho. 
    n->hder = new celda(e, n); 
}
template <typename T>
inline void Abin<T>::eliminarHijoIzqdo(nodo n) {
    assert(n != NODO_NULO); //Existe
    assert(n->hizq != NODO_NULO); //Existe hijo izqdo.
    assert(n->hizq->hizq == NODO_NULO && n->hizq->hder == NODO_NULO); //No tenga hijos ni izquierdo ni derecho
    delete n->hizq;     //Eliminamos el hijo izquierdo
    n->hizq = NODO_NULO; //Ponemos a nulo la celda.
}

template <typename T>
inline void Abin<T>::eliminarHijoDrcho(nodo n) {
    assert(n != NODO_NULO);
    assert(n->hder != NODO_NULO); // Existe hijo drcho.
    assert(n->hder->hizq == NODO_NULO && n->hder->hder == NODO_NULO);
    delete n->hder;
    n->hder = NODO_NULO;
}


template <typename T>
inline void Abin<T>::eliminarRaiz()
{
   assert(r != NODO_NULO);   // Árbol no vacío.
   assert(r->hizq == NODO_NULO && r->hder == NODO_NULO); //La raiz debe ser una hoja
   delete r;
   r = NODO_NULO;
}

template <typename T> 
inline bool Abin<T>::arbolVacio() const { 
    return (r == NODO_NULO); 
}

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const {
   assert(n != NODO_NULO); //Existe n
    return n->elto; 
}

template <typename T>
inline T& Abin<T>::elemento(nodo n)
{
   assert(n != NODO_NULO);
   return n->elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const { 
    return r; 
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(nodo n) const {
   assert(n != NODO_NULO);
   return n->padre;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const {
   assert(n != NODO_NULO);
   return n->hizq;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const {
   assert(n != NODO_NULO);
   return n->hder;
}

template <typename T>
inline Abin<T>::Abin(const Abin<T>& A)
{
r = copiar(A.r); // Copiar raíz y descendientes. 
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& A) {
if (this != &A) // Evitar autoasignación. 
{
    this->~Abin();   // Vaciar el árbol.
    r = copiar(A.r); // Copiar raíz y descendientes. 
}
   return *this;
}
template <typename T>
Abin<T>::~Abin(){
    destruirNodos(r); //Vaciar el arbol
}

/*Métodos privados*/
template <typename T>
void Abin<T>::destruirNodos(nodo& n){ //destruye el nodo y todo lo que hay por debajo
    if(n!= NODO_NULO)                  //Si dicho nodo es justamente la raíz, se elimina el árbol entero
    {
        destruirNodos(n->hizq);
        destruirNodos(n->hder);
        delete n; //delete libera las posiciones ocupadas
        n=NODO_NULO;
    }
}

template<typename T>
typename Abin<T>::nodo Abin<T>::copiar(nodo n){
    nodo m= NODO_NULO;
    if(n!=NODO_NULO){
        m= new celda(n->elto); //Copiar n
        m->hizq= copiar(n->hizq);//Copiamos su subarbol izquierdo
        if(m->hizq != NODO_NULO) m->hizq->padre = m;
        m->hder=copiar(n->hder);//Copiamos su subarbol derecho
        if(m->hder != NODO_NULO) m->hder->padre = m;
    }
    return m;
}

template<typename T>
int Abin<T>::profundidad(nodo n){
    if(n == NODO_NULO) return -1;
    else{
        return 1 + max(profundidad(n->hder), profundidad(n->hizq));
    }
}

template<typename T>
int Abin<T>::altura(nodo n){
    if(n==NODO_NULO) return 0;
    else{
        return 1 + altura(n->padre);
    }
}
#endif