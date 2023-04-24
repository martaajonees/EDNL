/*
En un videojuego de estrategia, el jugador tiene un castillo que está protegido por 
una serie de torres de defensa. Cada torre tiene un nivel de fortificación, que se 
representa por un valor entero positivo, y un alcance máximo, que se representa por 
otro valor entero positivo.

El jugador recibe ataques enemigos en oleadas, y cada oleada consta de un conjunto de 
unidades enemigas. Cada unidad enemiga tiene una posición en el campo de batalla y un 
nivel de ataque, que se representa por un valor entero positivo.

El objetivo del jugador es proteger su castillo de los ataques enemigos. Para ello, 
el jugador debe utilizar sus torres de defensa para atacar a las unidades enemigas. 
Cada torre de defensa puede atacar a todas las unidades enemigas que se encuentren 
dentro de su alcance máximo, y cada unidad enemiga puede ser atacada por varias torres 
de defensa.

Cada vez que una unidad enemiga es destruida por una torre de defensa, el jugador 
recibe una cantidad de puntos igual al nivel de fortificación de la torre de defensa. 
El jugador gana la partida si consigue destruir todas las unidades enemigas antes de 
que lleguen al castillo.

Escribe una función en C++ que reciba como parámetros un árbol binario que representa 
las torres de defensa y un vector de unidades enemigas, y calcule la cantidad de puntos 
que el jugador obtendría si destruye todas las unidades enemigas utilizando las torres 
de defensa. La posición de cada unidad enemiga se representa por un par de valores 
enteros que indican su coordenada x e y en el campo de batalla.
*/

#include "../abin.hpp"

#define num_enemigos 30

struct Torres{
    int fortificación;
    int alcance_max;
};

struct Enemigos{
    int posicion;
    int nivelAtaque;
};

int maxpuntos(Abin<Torres> A, Enemigos E[num_enemigos]){
    A.
}