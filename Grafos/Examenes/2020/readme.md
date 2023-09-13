# Problema 2020

Un repartidor de una empresa de distribución de bebidas tiene que visitar a todos sus clientes cada día. Pero, al comenzar su jornada de trabajo, no conoce qué cantidad de bebidas tiene que servir a cada cliente, por lo que no puede planificar una ruta óptima para visitarlos a todos. Por tanto, nuestro repartidor decide llevar a cabo la siguiente estrategia:
1. El camión parte del almacén con la máxima carga permitida rumbo a su cliente más próximo.
2. El repartidor descarga las cajas de bebidas que le pide el cliente. Si no tiene suficientes cajas en el camión, le entrega todas las que tiene. Este cliente terminará de ser servido en algún otro momento a lo largo del día, cuando la estrategia de reparto vuelva a llevar al repartidor hasta él.
3. Después de servir a un cliente:
   -  Si quedan bebidas en el camión, el repartidor consulta su sistema de navegación basado en GPS para conocer la ruta que le lleva hasta su cliente más próximo pendiente de ser servido.
   - Si no quedan bebidas en el camión, vuelve al almacén por el camino más corto y otra vez carga el camión completamente.
4. Después de cargar el camión, el repartidor consulta su sistema de navegación y se va por el camino más corto a visitar al cliente pendiente de ser servido más próximo.
día por nuestro repartidor, a partir de lo siguiente:

Implementa un subprograma que calcule y devuelva la distancia total recorrida en un día por nuestro repartidor, a partir de lo siguiente:

1. Grafo representado mediante matriz de costes con las distancias de los caminos directos entre los clientes y entre ellos y la central.
1.    Capacidad máxima del camión (cantidad de cajas de bebidas).
2.    Asumiremos que existe una función 'int Pedido()' que devuelve el número de cajas que quedan por servir al cliente en el que se encuentra el repartidor.
