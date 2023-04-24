/*
DESEQUILIBRIO DE UN ARBOL GENERAL EN EL QUE EL DESEQUILIBRIO 
ES LA MAXIMA DIFERENCIA DE PESOS DE LOS SUBARBOLES DE N Y EL 
PESO DE UN NODO ES EL NUMERO DE NODOS HOJAS
*/

#include "../agen.hpp"
template<typename T>
int desequilibrioagen(Agen<T> A, typename Agen<T>::nodo n){
    if(n == Agen<T>::NODO_NULO) return 0;
    else {
        int maxi =0, mini= 9999, maxim, pesoder=0, pesoizq =0;
       typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
       while(hijo != Agen<T>::NODO_NULO){ //peso de los subarboles derechos
            maxi = max(maxi, peso(A, hijo));
            mini = max(mini, peso(A, hijo));
            pesoder = max(pesoder,desequilibrioagen(A,hijo)); //maximo de los desequilibrios de todos sus hermanos
            hijo = A.hermDrcho(hijo);
       }
        pesoizq = peso(A, A.hijoIzqdo(n)); //peso del subarbol izq
        maxim = max(pesoder, desequilibrioagen(A,A.hijoIzqdo(n)));
       return max(maxim, maxi-mini);
    }
}

//Dado un nodo, calcula 
template<typename T>
int nhijos(Agen<T> A, typename Agen<T>::nodo n ){
    int cont =0;
    n = A.hijoIzqdo(n);
    while(n !=Agen<T>::NODO_NULO){
        cont++;
        n= A.hermDrcho(n);
    }
    return cont;
}

//Dado un nodo, calcula el peso de su subárbol
template<typename T>
int peso(Agen<T> A, typename Agen<T>::nodo n){
    int peso_ = 0;
    if (nhijos(A, n) == 0){ // Si el nodo es una hoja, su peso es 1
        peso_ = 1;
    } else {
        // Si el nodo no es una hoja, sumamos los pesos de sus hijos y añadimos 1
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO){ // Recorremos los hermanos derechos
            peso_ += peso(A, hijo); // Llamada recursiva para calcular el peso del hijo
            hijo = A.hermDrcho(hijo);
        }
    }
    // Llamamos recursivamente a la función para cada uno de los hijos del nodo y sumamos sus resultados
    return peso_;
}
