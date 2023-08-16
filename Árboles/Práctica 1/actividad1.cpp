template<typename T>
int numNodos(const Abin<T>& a);

template<typename T>
int numNodosRec(const Abin<T>&, typename Abin<T>::nodo);

template<typename T>
int numNodos(const Abin<T>& a){
    return numNodosRec(a, a.raiz());
}

template<typename T>
int numNodosRec(const Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        return 1 + numNodosRec(A, A.hijoDrcho(n)) + numNodosRec(A, A.hijoIzqdo(n));
    }
}

int main(){
    /*       1
            /  \ 
          2     3 
         / \    /\
        4  5   6  7 */
    Abin<int> A;
    A.insertarRaiz(1);
    A.insertarHijoDrcho(A.raiz(),3);
    A.insertarHijoIzqdo(A.raiz(),2);
    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()),7);
    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()),6);
    A.insertarHijoDrcho(A.hijoIzqdo(A.raiz()),5);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),4);
    //Llamamos a la función recursiva
    cout<<"Tiene "<< numNodos(A) <<" nodos";

}
