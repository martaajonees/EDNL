/*Implementación vectorial de árboles generales mediante listas de hijos */

#ifndef AGEN_LIS_H
#define AGEN_LIS_H
#include <cassert>
#include "listaenla.hpp"
template <typename T> class Agen {
public:
   typedef size_t nodo; // Índice del vector entre 0 y maxNodos-1
   static const nodo NODO_NULO;
   
    explicit Agen(size_t maxNodos); // Ctor., requiere ctor. T() 
    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    void insertarHermDrcho(nodo n, const T& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHermDrcho(nodo n);
    void eliminarRaiz();
    const T& elemento(nodo n) const; // Lectura en Agen 
    const T& elemento(nodo n); // Lectura/escritura en Agen no-const
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hermDrcho(nodo n) const;
    Agen(const Agen<T>& A); // Ctor. de copia 
    Agen<T>& operator =(const Agen<T>& A); // Asignación de árboles
   ~Agen(); // Destructor
private:
   struct celda {
        T elto;
        nodo padre;
        Lista<nodo> hijos;
   };
celda *nodos; // Vector de nodos
size_t maxNodos; // Tamaño del vector
size_t numNodos; // Número de nodos del árbol
};
/* Operaciones ---------------------------------------------------------------*/
/* Definición del nodo nulo */
template <typename T>
const typename Agen<T>::nodo Agen<T>::NODO_NULO(SIZE_MAX);

template <typename T>
inline Agen<T>::Agen(size_t maxNodos) :
   nodos(new celda[maxNodos]),  // Se crean las listas de hijos vacías.
   maxNodos(maxNodos),
   numNodos(0)
{
   // Marcar todas las celdas como libres.
   for (nodo i = 0; i <= maxNodos-1; i++)
      nodos[i].padre = NODO_NULO;
}

template <typename T>
inline void Agen<T>::insertarRaiz(const T& e)
{
   assert(numNodos == 0);   // Árbol vacío.
   numNodos = 1;
   nodos[0].elto = e;
   // La lista de hijos está vacía.
}

template <typename T>
void Agen<T>::insertarHijoIzqdo(nodo n, const T& e)
{
   nodo hizqdo;
   assert(numNodos>0); //Árbol no vacío
   assert(n>=0 && n<maxNodos-1); //n es una celda del vector
   assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada. 
   assert(numNodos < maxNodos); // Árbol no lleno.

   // Añadir el nuevo nodo en la primera celda libre.
   for (hizqdo = 1; nodos[hizqdo].padre != NODO_NULO; hizqdo++); 
   nodos[hizqdo].elto = e;
   nodos[hizqdo].padre = n;

   // Insertar el nuevo nodo al inicio de la lista de hijos de n. 
   Lista<nodo>& Lh = nodos[n].hijos; // Lista de hijos. 
   Lh.insertar(hizqdo, Lh.primera());
   ++numNodos;

}

template<typename T>
void Agen<T>::insertarHermDrcho(nodo n, const T& e)
{
   nodo hdcho;
   assert(numNodos>0); //Árbol no vacío
   assert(n>=0 && n<); 
}

template<typename T>
void Agen<T>::eliminarHermDrcho(nodo n){
   nodo hdrcho;
   listaenla<nodo>::posicion p;

   assert(n >= 0 && <= maxNodos-1); //n es un nodo válido
   assert(nodos[n].padre != NODO_NULO); //n existe y no es la raiz

   /* Buscamos el hermano derecho de n en la lista de hijos del padre */
   listaenla<nodo>& Lhp = nodos[nodos[n].padre].hijos; //Lista de hijos del padre

   listaenla<nodo>::posicion p = Lhp.primera();
   while (n!= Lhp.elemento(p))
}

template <typename T>
Agen<T>& Agen<T>::operator =(const Agen<T>& A)
{
   if (this != &A) {   // Evitar autoasignación.
      // Destruir el vector y crear uno nuevo si es necesario.
      if (maxNodos != A.maxNodos) {
         delete[] nodos;
         maxNodos = A.maxNodos;
         nodos = new celda[maxNodos];
      }
      numNodos = A.numNodos;
      for (nodo n = 0; n <= maxNodos-1; n++) // Copiar el vector.
         nodos[n] = a.nodos[n];
   }
   return *this;
}

template <typename T>
inline Agen<T>::~Agen()
{
   delete[] nodos; // También destruye las listas de hijos.
}

#endif
