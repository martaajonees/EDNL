/*
Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice la poda de A a partir de x. 
Se asume que no hay elementos repetidos en A.
*/


#include<iostream>
#include "../imprimirAgen.cpp"
using namespace std;

void poda(Agen<int>, int);
void podaRec(Agen<int>, Agen<int>::nodo elemento);
Agen<int>::nodo buscar(Agen<int>, int);
Agen<int>::nodo buscarRec(Agen<int>, int, Agen<int>::nodo);
int numHijos(Agen<int> A, Agen<int>::nodo n);

void poda(Agen<int> A, int x){
    return podaRec(A, buscar(A, x));
}

void podaRec(Agen<int> A, Agen<int>::nodo elemento){
    Agen<int>::nodo hijo = A.hijoIzqdo(elemento);

    if(elemento != Agen<int>::NODO_NULO){
        if(elemento == A.raiz()){ A.eliminarRaiz(); return; } //Si el nodo es la raiz, la elimino
        
        while(hijo != Agen<int>::NODO_NULO && A.hijoIzqdo(hijo)==Agen<int>::NODO_NULO){ //Mientras que el hijo sea hoja
            A.eliminarHijoIzqdo(elemento);
            hijo = A.hijoIzqdo(elemento);
        }
        
        if(hijo != Agen<int>::NODO_NULO && A.hijoIzqdo(hijo)!=Agen<int>::NODO_NULO) //Si el hijo no es hoja
            podaRec(A, A.hijoIzqdo(hijo));
            A.eliminarHijoIzqdo(elemento);
    }
}



//Dado un árbol y un elemento, devuelve ese elemento
Agen<int>::nodo buscarRec(Agen<int> A, int x, Agen<int>::nodo n){
    if(A.elemento(n)== x) return n; //Elemento encontrado, devuelve el elemento
    else{ //Elemento no encontrado, devuelvo Nodo Nulo
        Agen<int>::nodo aux= A.hijoIzqdo(n);
        while (aux != Agen<int>::NODO_NULO) //Compruebo todos los hermanos
        {   
            Agen<int>::nodo res = buscarRec(A, x, aux);
            if(res != Agen<int>::NODO_NULO) return res; //Si no es nodo nulo, se ha encontrado y se devuelve
            aux = A.hermDrcho(aux); //Si no, se ha encontrado
        }
        return Agen<int>::NODO_NULO;
    }
}

Agen<int>::nodo buscar(Agen<int> A, int x){
    return buscarRec(A, x, A.raiz());
}


int main(){
    // Creamos un árbol con los valores del 1 al 7
    Agen<int> A; 
    A.insertarRaiz(1);
    A.insertarHijoIzqdo(A.raiz(), 2);
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), 3);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 4);
    A.insertarHermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), 5);
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), 6);
    A.insertarHermDrcho(A.raiz(), 7);
    
    // Imprimimos el árbol original
    cout << "Árbol original:" << endl;
    imprimirAgen(A);
    cout << endl;
    
    // Pedimos al usuario que indique el valor a partir del cual queremos podar el árbol
    int x;
    cout << "Introduzca el valor a partir del cual desea podar el árbol: ";
    cin >> x;
    
    // Poda el árbol a partir del valor x
    poda(A, x);
    
    // Imprimimos el árbol podado
    cout << "Árbol podado:" << endl;
    imprimirAgen(A);
    cout << endl;
    
    return 0;
}
