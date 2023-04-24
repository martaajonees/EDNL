/*
Un árbol binario de búsqueda se puede equilibrar realizando el 
recorrido en inorden del árbol para obtener el listado ordenado 
de sus elementos y a continuación, repartir equitativamente los 
elementos a izquierda y derecha colocando la mediana en la raíz y 
construyendo recursivamente los subárboles izquierdo y derecho de cada nodo. 

Implementa este algoritmo para equilibrar un ABB. 
*/

#include "../abb.hpp"

template<typename T>
vector<T> equilibrarAbb(Abb<T>* nodo, vector<T>& lista){
    if(!A.vacio()){return; }
    else{
        //Metemos en la lista el valor de los elementos en inorden
        lista = inorden(nodo, lista);
        //calculando la mediana
        int v;
        float mediana;
        v=lista.size()/2;
        if(lista.size()%2==0){
        mediana=(A[v]+A[v-1])/2;
        }else{ mediana=A[v]; }
        //Construimos arbol
        nodo->insertar(mediana);
        
        Abb<T>* nodo_mediana = new Abb<T>(mediana);
        
        // Insertamos los elementos menores que la mediana en el subárbol izquierdo
        vector<T> izqdo_lista(lista.begin(), lista.begin() + v);
        nodo_mediana->izqdo() = equilibrarAbb(nodo, izqdo_lista);
        
        // Insertamos los elementos mayores que la mediana en el subárbol derecho
        vector<T> dcho_lista(lista.begin() + v + 1, lista.end());
        nodo_mediana->drcho() = equilibrarAbb(nodo, dcho_lista);
        
        return nodo_mediana;
    }
}
template<typename T>
vector<T> insercionAbb(Abb<T>* nodo, vector<T>& lista, float mediana){
    nodo->insertar(mediana);
    for(int i =0; i<lista.size(); i++){
        if(lista[i]>mediana){
            lista.insert(lista.end(), )}
    }
}

template<typename T>
Abb<T>& inorden(Abb<T>* nodo, vector<T>& lista){
   if(!A.vacio()){return; }
    else{
        //1º visitamos árbol izquierdo
        vector<T> izqdo = inorden(nodo->izqdo(), lista);
        lista.insert(lista.end(), izqdo.begin(), izqdo.end());
        
        //Visitamos nodo actual
        lista.push_back(nodo->elemento());

        //Recorremos árbol derecho
        vector<T> dcho = inorden(nodo->drcho(), lista);
        lista.insert(lista.end(), dcho.begin(), dcho.end());
        return lista;
    }
}