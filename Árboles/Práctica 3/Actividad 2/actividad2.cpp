template<typename T>
int Profundidad(const Agen<T>& A, typename Agen<T>::nodo n) {
    if(n == A.raiz()) return 0;
    else{
        return 1 + Profundidad(A, A.padre(n));
    }
}
