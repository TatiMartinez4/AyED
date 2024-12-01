/*Se quiere hacer un programa para administrar y realizar estadística de la contratación y asignación de viajes de una empresa de fletes que se pidieron para realizar viajes en el mes de septiembre. De cada uno de los camiones de la flota que posee la empresa se conoce el número de camión y la carga máxima que puede transportar (en kilogramos). Cada camión realiza un solo viaje por día.
Por cada viaje pedido para el mes de septiembre se conoce el dni de la persona que hace el pedido, el día del viaje, el número de camión pedido y los kilogramos a transportar. El viaje se acepta si la carga es menor o igual a la carga máxima del camión y si ese camión no tiene viaje contratado para ese día y respetando el orden en que fueron pedidos. Los viajes pedidos se encuentran en el archivo de datos (binario) “PedidiosViajesSept.dat”, ordenado por fecha de pedido.
El programa tiene las siguientes funciones:
cargarCamiones
En esta función se ingresan por teclado número de camión y carga máxima del camión. Estos datos se ingresan sin orden y se almacenan en un vector en memoria.
procesarPedidos
En esta función, con los datos del archivo de pedidos de viajes para el mes de septiembre, debe generar un archivo binario de datos con los pedidos aceptados y completar la/s estructura/s de datos necesarias para la función mostrarEstadistica.
mostrarEstadistica
Esta función, utilizando la/s estructura/s generadas en procesarPedidos, debe mostrar:
a)
Cantidad de viajes pedidos por cada camión para cada día del mes, de la siguiente forma:
Número de camión: XXX
Día 1: XX pedidos
Día 2: XX pedidos
….
Número de camión: XXX
…
b)
Cantidad de días para los que no hubo pedidos de viajes.
c)
Número de camión que tuvo la mayor cantidad de pedidos en total.
Se pide:
1)
Definir y justificar la/s estructura/s de datos usadas en el programa. Definir todos los struct necesarios.
2)
Declarar solo el prototipo de la función cargarCamiones
3)
Desarrollar la función procesarPedidios. Desarrollar también las funciones que ésta invoque.
4)
Desarrollar la función mostrarEstadistica. Desarrollar también las funciones que ésta invoque*/