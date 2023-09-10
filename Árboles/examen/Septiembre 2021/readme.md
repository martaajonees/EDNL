# Ejercicio Septiembre 2021

Se tiene un árbol binario en el que cada nodo representa una persona y tiene asociado 
un montón de dinero. El objetivo es implementar una función en C++ que reciba un nodo 
del árbol y reparta su herencia entre sus descendientes vivos, es decir, aquellos 
que están más abajo en el árbol y que no han sido marcados como muertos.

La función deberá eliminar el nodo pasado como argumento y repartir su dinero entre 
sus descendientes vivos. Si el nodo no tiene descendientes vivos, su dinero se pierde.

Para realizar la repartición de la herencia, se debe sumar el dinero del nodo y 
distribuirlo entre los descendientes vivos de manera equitativa. Si la división 
no es exacta, se debe asignar el dinero sobrante al primer descendiente en orden 
de recorrido en preorden.

__Nota__: Es absolutamente necesario definir todos los tipos de datos que se usen para resolver el problema, así cómo los prototipos de las funciones usadas.
