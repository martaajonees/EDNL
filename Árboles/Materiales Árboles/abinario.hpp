/*IMPLEMENTACIÓN VECTORIAL DE UN ARBOL BINARIO */
#include<stdio.h>
#include<iostream>
using namespace std;
 
#ifndef ABIN_VEC0_H
#define ABIN_VEC0_H

template<typename T>
class Abin{
public:
    typedef size_t nodo; //índice de la matriz entre 0 y maxNodos -1
    static const nodo NODO_NULO;
    explicit Abin(size_t maxNodos); //Constructor
    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    void insertarHijoDrcho(nodo n, const T& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();
    int profundidadRec(typename Abin<T>::nodo n);//Ejercicio 4
    int numAltura(nodo r); //Ejercicio 4
    bool arbolVacio() const;
    const T& elemento(nodo n) const; // acceso a elto, lectura 
    T& elemento(nodo n); // acceso a elto, lectura/escritura
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    Abin(const Abin<T>& A); // ctor. de copia 
    Abin<T>& operator =(const Abin<T>& A); // asig. de árboles
    ~Abin(); // destructor
private:
   struct celda {
      T elto;
      nodo padre, hizq, hder;
   };
    celda *nodos;   // vector de nodos
    size_t maxNodos;    // tamaño del vector
    size_t numNodos;    // número de nodos del árbol
};

/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(SIZE_MAX);

template<typename T>
inline Abin<T>::Abin(size_t maxNodos):nodos(new celda[maxNodos]),maxNodos(maxNodos),numNodos(0) {}

template<typename T>
inline void Abin<T>::insertarRaiz(const T& e){
    assert(numNodos==0); //Arbol vacío

    numNodos=1;
    nodos[0].elto=e;
    nodos[0].padre=NODO_NULO;
    nodos[0].hizq=NODO_NULO;
    nodos[0].hder=NODO_NULO;
}

template <typename T>
inline void Abin<T>::insertarHijoIzqdo(nodo n, const T& e) 
{
    assert(n >= 0 && n < numNodos); // Nodo válido 
    assert(nodos[n].hizq == NODO_NULO); // n no tiene hijo izqdo. 
    assert(numNodos < maxNodos); // Árbol no lleno

    // Añadir el nuevo nodo al final de la secuencia.
    nodos[n].hizq = numNodos;  //En el campo hizq enumeramos el hijo 
    nodos[numNodos].elto = e;  //Insertamos el contenido que nos dan en el nodo
    nodos[numNodos].padre = n; //Insertamos su padre
    nodos[numNodos].hizq = NODO_NULO; //Ponemos a NULO los hijos (de momento es una hoja)
    nodos[numNodos].hder = NODO_NULO; 
    ++numNodos; //Incrementamos el número de nodos una posición
}

template <typename T>
inline void Abin<T>::insertarHijoDrcho(nodo n, const T& e) 
{
    assert(n >= 0 && n < numNodos); // Nodo válido 
    assert(nodos[n].hder == NODO_NULO); // n no tiene hijo drcho. 
    assert(numNodos < maxNodos); // Árbol no lleno
   // Añadir el nuevo nodo al final de la secuencia.
    nodos[n].hder = numNodos; 
    nodos[numNodos].elto = e; 
    nodos[numNodos].padre = n; 
    nodos[numNodos].hizq = NODO_NULO; 
    nodos[numNodos].hder = NODO_NULO; 
    ++numNodos;
}

template<typename T>
void Abin<T>::eliminarHijoIzqdo(nodo n)
{
    nodo hijoizqdo;

    assert(n>=0 && n<numNodos);//Nodo válido

    hijoizqdo= nodos[n].hizq;

    assert(hijoizqdo != NODO_NULO); //Existe el hijo izquierdo

    assert(nodos[hijoizqdo].hizq == NODO_NULO && nodos[hijoizqdo].hder == NODO_NULO);
    //El hijo izquierdo de n es hoja
    
    if(hijoizqdo != numNodos-1)
    { 
        nodos[hijoizqdo]=nodos[numNodos-1]; //Movemos el último nodo a la posición que queremos borrar
        if(nodos[nodos[hijoizqdo].padre].hizq== numNodos-1) //Actualizamos el valor del nodo padre del que acabamos de mover
            nodos[nodos[hijoizqdo].padre].hizq= hijoizqdo; //Si es el hijo izq actualizamos el valor
        else
            nodos[nodos[hijoizqdo].padre].hder=hijoizqdo; //Si es el hijo dcho, actualizamos su valor
        
        if(nodos[hijoizqdo].hizq != NODO_NULO)
            nodos[nodos[hijoizqdo].hizq].padre=hijoizqdo;
        if(nodos[hijoizqdo].hder != NODO_NULO)
            nodos[nodos[hijoizqdo].hder].padre=hijoizqdo;
    }
    nodos[n].hizq=NODO_NULO;
    --numNodos;
}

template <typename T>
void Abin<T>::eliminarHijoDrcho(nodo n)
{
    nodo hdrcho;

    assert(n >= 0 && n < numNodos); // Nodo válido
    hdrcho = nodos[n].hder;
    assert(hdrcho != NODO_NULO); // Existe hijo drcho. de n. 
    assert(nodos[hdrcho].hizq == NODO_NULO && nodos[hdrcho].hder == NODO_NULO);// Hijo drcho. de n es hoja.
   
    if (hdrcho != numNodos-1)
    {
        // Mover el último nodo a la posición del hijo drcho.
        nodos[hdrcho] = nodos[numNodos-1];
        // Actualizar la posición del hijo (izquierdo o derecho) // en el padre del nodo movido.
        if (nodos[nodos[hdrcho].padre].hizq == numNodos-1)
            nodos[nodos[hdrcho].padre].hizq = hdrcho; 
        else
            nodos[nodos[hdrcho].padre].hder = hdrcho;
        // Si el nodo movido tiene hijos,
        // actualizar la posición del padre. 
        if (nodos[hdrcho].hizq != NODO_NULO)
            nodos[nodos[hdrcho].hizq].padre = hdrcho;  
        if (nodos[hdrcho].hder != NODO_NULO) 
            nodos[nodos[hdrcho].hder].padre = hdrcho;
    }
    nodos[n].hder = NODO_NULO; 
    --numNodos;

}

template <typename T>
inline void Abin<T>::eliminarRaiz()
{
    assert(numNodos == 1);
    numNodos = 0; 
}

template <typename T>
inline bool Abin<T>::arbolVacio() const 
{
   return (numNodos == 0);
}

template <typename T>
inline const T& Abin<T>::elemento(nodo n) const 
{
   assert(n >= 0 && n < numNodos);
   return nodos[n].elto;
}

template <typename T>
inline T& Abin<T>::elemento(nodo n) {
   assert(n >= 0 && n < numNodos);
   return nodos[n].elto;
}

template <typename T>
inline typename Abin<T>::nodo Abin<T>::raiz() const 
{
    return (numNodos > 0) ? 0 : NODO_NULO; 
}


template <typename T> inline
typename Abin<T>::nodo Abin<T>::padre(nodo n) const 
{
   assert(n >= 0 && n < numNodos);
   return nodos[n].padre;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdo(nodo n) const 
{
   assert(n >= 0 && n < numNodos);
   return nodos[n].hizq;
}
template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrcho(nodo n) const 
{
   assert(n >= 0 && n < numNodos);
   return nodos[n].hder;
}

template <typename T> Abin<T>::Abin(const Abin<T>& A) : nodos(new celda[A.maxNodos]), maxNodos(A.maxNodos), numNodos(A.numNodos)
{
    // Copiar el vector.
    for (nodo n = 0; n <= numNodos-1; n++) nodos[n] = A.nodos[n];
}

template <typename T>
inline Abin<T>::~Abin()
{
   delete[] nodos;
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& A) 
{
    if (this != &A) // Evitar autoasignación. 
    {
        // Destruir el vector y crear uno nuevo si es necesario.
        if (maxNodos != A.maxNodos){
            delete[] nodos;
            maxNodos = A.maxNodos;
            nodos = new celda[maxNodos];
        }
      // Copiar el vector.
    numNodos = A.numNodos;
    for (nodo n = 0; n <= numNodos-1; n++)
        nodos[n] = A.nodos[n];
    }
   return *this;
}

#endif