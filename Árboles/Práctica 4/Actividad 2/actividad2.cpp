// Cabecera ------------------------

template<typename T>
void inorden(Abb<T>& A, vector<T>& vect);

template<typename T>
void equilibrar(Abb<T>& A);

template<typename T>
void equilibrarRec(Abb<T>& A, vector<T>& vect, int inicio, int fin);

// Funciones -----------------------

template<typename T>
void inorden(Abb<T>& A, vector<T>& vect) {
    if(! A.vacio()){
        // Visitamos árbol izquierdo
        inorden(A.izqdo(), vect); 

        //Nodo actual
        vect.push_back(A.elemento());

        // Visitamos árbol derecho
        inorden(A.drcho(), vect);
    }
}


template<typename T>
void equilibrarRec(Abb<T>& A, vector<T>& vect, int inicio, int fin){
    if(!A.vacio() && inicio <= fin) {
        //Calculamos la mediana
        int mediana = (inicio + fin)/2;
        //Inserto la mediana
        A.insertar(vect[mediana]);
        // Construimos arbol
       equilibrarRec(A, vect, inicio, mediana-1);
       equilibrarRec(A, vect, mediana + 1, fin);
    }
}

template<typename T>
void equilibrar(Abb<T>& A){
    vector<T> vect;
    inorden(A, vect);//Rellenamos el vector con el recorrido en inorden
    Abb<T> A1; //Creamos arbol 
    equilibrarRec(A1, vect, 0, vect.size()-1);
}
