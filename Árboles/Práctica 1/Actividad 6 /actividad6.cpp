#include "../abin.hpp"
#include "act2.cpp"

using namespace std;

template<typename T>
int desequilibrioRec(const Abin<T>& A, typename Abin<T>::nodo n);

template<typename T>
int desequilibrio(const Abin<T>& A) {
    return desequilibrioRec(A, A.raiz());
}

template<typename T>
int desequilibrioRec(const Abin<T>& A, typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO) return 0;
    else {
        return max(desequilibrioRec(A, A.hijoDrcho(n)), max(desequilibrioRec(A, A.hijoIzqdo(n)), abs(AlturaRec(A, A.hijoDrcho(n))- AlturaRec(A, A.hijoIzqdo(n)))));
    }
}
