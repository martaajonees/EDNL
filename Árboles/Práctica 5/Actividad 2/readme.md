# Actividad 2
Un __montículo min-max__ tiene una estructura similar a la de un montículo 
ordinario (árbol parcialmente ordenado), pero la ordenación parcial consiste en 
que los elementos que se encuentran en un nivel par (0, 2, 4,...) son menores o 
iguales que sus elementos descendientes, 
mientras que los elementos que se encuentran en un nivel impar (1, 3, 5,...) son mayores o 
iguales que sus descendientes. 

Esto quiere decir que para cualquier elemento e de un nivel par 
se cumple _abuelo ≤ e ≤ padre_ y para cualquier elemento e de un nivel impar _padre ≤ e ≤ abuelo_.  

Implementa una operación de orden logarítmico para 
añadir un elemento a un montículo min-max almacenado en un vector de posiciones relativas.
