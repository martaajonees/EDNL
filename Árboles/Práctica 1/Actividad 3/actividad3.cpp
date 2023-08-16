template<typename T>
int Profundidad(const Abin<T>& a, typename Abin<T>::nodo n){
    if(n == a.raiz()) return 0;
    else{
        return 1 + Profundidad(a, a.padre(n));
    }
}
