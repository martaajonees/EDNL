#ifndef _LISTAENLAZ_H
#define _LISTAENLAZ_H

#include <cassert>
template <typename T>
class listaenla {
    struct nodo; 
public:
    typedef nodo* posicion; // posición de un elemento
    listaenla(); // constructor, requiere ctor. T()
    listaenla(const listaenla<T>& l); // ctor. de copia, requiere ctor. T()
    listaenla<T>& operator=(const listaenla<T>& l); // asignación de listas
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // T requiere operador ==
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; // posición después del último
    ~listaenla(); // destructor
private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = 0)
            : elto(e)
            , sig(p)
        {}
    };
    nodo* L; // lista enlazada de nodos
    void copiar(const listaenla<T>& l);
};

template <typename T>
void listaenla<T>::copiar(const listaenla<T>& l){
    L = new nodo(T()); // crear el nodo cabecera nodo* q = L;
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig) {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

template <typename T>
inline listaenla<T>::listaenla() : L(new nodo(T()))
{} 

template <typename T>
inline listaenla<T>::listaenla(const listaenla<T>& l){
    copiar(l);
}

template <typename T>
listaenla<T>& listaenla<T>::operator=(const listaenla<T>& l){
    if (this != &l) { // evitar autoasignación
        this->~listaenla(); // vaciar la lista actual
        copiar(l);
    }
    return *this;
}

template <typename T>
inline void listaenla<T>::insertar(const T& x, listaenla<T>::posicion p){
    p->sig = new nodo(x, p->sig);
}
template <typename T>
inline void listaenla<T>::eliminar(listaenla<T>::posicion p){
    assert(p->sig); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
}

template <typename T>
inline const T& listaenla<T>::elemento(listaenla<T>::posicion p) const{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T>
inline T& listaenla<T>::elemento(listaenla<T>::posicion p){
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T>
typename listaenla<T>::posicion listaenla<T>::buscar(const T& x) const{
    nodo* q = L;
    bool encontrado = false;
    while (q->sig && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else
            q = q->sig;
    return q;
}

template <typename T>
inline typename listaenla<T>::posicion listaenla<T>::siguiente(listaenla<T>::posicion p) const{
    assert(p->sig); // p no es fin
    return p->sig;
}

template <typename T>
typename listaenla<T>::posicion listaenla<T>::anterior(listaenla<T>::posicion p) const {
    nodo* q;
    assert(p != L); // p no es la primera posición
    for (q = L; q->sig != p; q = q->sig);
    return q;
}

template <typename T>
inline typename listaenla<T>::posicion listaenla<T>::primera() const{
    return L;
}

template <typename T>
typename listaenla<T>::posicion listaenla<T>::fin() const{
    nodo* p;
    for (p = L; p->sig; p = p->sig);
    return p;
}

// Destructor: destruye el nodo cabecera y vacía la lista
template <typename T>
listaenla<T>::~listaenla(){
    nodo* q;
    while (L) {
        q = L->sig;
        delete L;
        L = q;
    }
}
#endif // _LISTAENLAZ_H