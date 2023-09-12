# Examen Junio 2016
El archipiélago Grecolandia (Zelandia) está formado por 2 islas: Fobos y Deimos que tienen N1 y N2 cludades de las cuales C1 y C2 ciudades son costeras (C1 <= N1 y
C2<= N2).

También se dispone de los grafos Fobos y Deimos representados mediante sondas matrices de adyacencia. 
Si el valor es true entonces hay carretera y el coste de ella corresponderia con la distancia euclidea existente entre las ciudados origen y destino de la misma.


Nos planteamos construir un puente entre todas las posibles (ciudados costeras también) para conectar el archipiélago.
Los fondos vienen de fondos FEDER por lo que son irrelevantes. 
Sin embargo, el coste directo de viajar por el puente, igual que en el caso de una carretera coincidirá 
con su longitud (distancia ouclidea entre las poblaciones origen y destino de dicho puente).

De cara a poder decidir qué puente construir, es importante indicar que se van a realizar el mismo número de 
viajes entre cualesquiera de 2 ciudades del archipiélago, por lo que no existen ciudades más importantes 
que otras ni rutas más importantes que otras. 
Todos los posibles viajes origen-destino en el archipiélago son, por tanto, de igual importancia 
y en consecuencia, debemos escoger el puente que minimice el coste mínimo de viajar entre las ciudades 
del archipiélago, dado lo irrelevante del coste de construcción.

En estas condicionos implementa una función que devuelva el puente a construir,
dados:
1.    Matriz de adyacencia de Fobos.
2.    Matriz de adyacencia de Deimos.
3.    Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
4.    Lista de ciudades de Deimos representadas mediante sus coordenadas cartesianas.
5.    Lista de ciudades costeras de Fobos.
6.    Lista de ciudades costeras de Deimos.
