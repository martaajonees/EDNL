# Problema 3
Eres el orgulloso dueño de una empresa de distribución. 
Tu misión radica en distribuir todo tu stock entre las diferentes 
ciudades en las que tu empresa dispone de almacén.

Tienes un grafo representado mediante la matriz de costes, en el que 
aparece el coste (por unidad de producto) de transportar los productos 
entre las diferentes ciudades del grafo.

Pero además resulta que los Ayuntamientos de las diferentes ciudades en 
las que tienes almacén están muy interesados en que almacenes tus productos 
en ellas, por lo que están dispuestos a subvencionarte con un porcentaje de 
los gastos mínimos de transporte hasta la ciudad.

Para facilitar el problema, consideraremos despreciables los costes de 
volver el camión a su base (centro de producción).

He aquí tu problema. Dispones de:

- El centro de producción, nodo origen en el que tienes tu producto (no tiene almacén).
- Una cantidad de unidades de producto (cantidad).
- La matriz de costes del grafo de distribución con N ciudades.
- La capacidad de almacenamiento de cada una de ellas.
- El porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada Ayuntamiento.

Las diferentes ciudades (almacenes) pueden tener distinta capacidad, y además la capacidad 
total puede ser superior a la cantidad disponible de producto, por lo que debes decidir 
cuántas unidades de producto almacenas en cada una de las ciudades. Debes tener en cuenta 
además las subvenciones que recibirás de los diferentes Ayuntamientos, las cuales pueden 
ser distintas en cada uno y estarán entre el 0% y el 100% de los costes mínimos.

La solución del problema debe incluir las cantidades a almacenar en cada ciudad bajo 
estas condiciones y el coste mínimo total de la operación de distribución para tu empresa
