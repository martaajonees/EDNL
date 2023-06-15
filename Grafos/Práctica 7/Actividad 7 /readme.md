# Problema 7
Se dispone de dos grafos (matriz de costes) que representan los costes de viajar entre N ciudades españolas utilizando el tren (primer grafo) 
 y el autobús (segundo grafo). Ambos grafos representan viajes entre las mismas N ciudades. 

 Nuestro objetivo es hallar el camino de coste mínimo para viajar entre dos ciudades concretas del grafo, origen y destino, en las siguientes 
 condiciones: 
 - La ciudad origen sólo dispone de transporte por tren.
 - La ciudad destino sólo dispone de transporte por autobús.
 - El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga, por lo que únicamente es posible cambiar de
   transporte en dos ciudades del grafo, cambio1 y cambio2, donde las estaciones de tren y autobús están unidas. 
    
Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre las ciudades Origen y Destino en estas condiciones. 
