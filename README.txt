README


SECCIÓN 1. DESARROLLO PRÁCTICO


	INTRODUCCIÓN:

		En el siguiente trabajo se desarrolló la implementación de los TDA´s:
			- Lista
			- Sus derivados Pila y Cola
			- Iterador externo
	y además un iterador interno.

		Aunado a esto también se implementó un TDA "tda_pruebas" el cual es usado 
	para testear todas las funciones implementadas en los TDA´s ya mencionados y
	mostrar los resultados obtenidos al final de estas. 


	COMPILACIÓN Y EJECUCIÓN:

		La linea de ejecución es igual que el ejemplo brindado por la cátedra:

			-Ejecución: valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se

		Ahora, la linea de compilación es el ejemplo brindado por la cátedra + el flag "-lm":

			-Compilación: gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0 -lm


	FUNCIONAMIENTO DE LA IMPLEMENTACION:

		Esta es una implementación encapsulada de la lista donde se guarda un 
	puntero al primer y último nodo y la cantidad de nodos. A su vez cada nodo 
	almacena un puntero a un elemento y otro puntero al siguiente nodo.

		Esta implementación fue elegida en base a mejorar la complejidad algoritmi-
	ca de varias funciones propuestas por la catedra, donde muchas de ellas, por
	ejemplo lista_insertar, lista_borrar, lista_ultimo, y varias más donde se de-
	be acceder al último elemento ó nodo de la lista, de esta manera se consigue
	una complejidad O(1), mientras que, si no se tuviera el puntero al último no-
	do estas funciones tendrían una complejidad O(n).



SECCIÓN 2. DESARROLLO TEÓRICO


	P1-¿Qué es lo que entendés por una lista? ¿Cuáles son las diferencias entre
		 ser simple o doblemente enlazada?

	Respuesta: Una lista es un tipo de dato abstracto (TDA) que almacena de forma
lineal y ordenada un conjunto de elementos, donde para poder acceder a estos e-
lementos se necesita un conjunto de funciones las cuales fueron implementadas.
	La diferencia principal entre una lista simplemente enlazada y un doblemente 
enlazada es que ambas tienen una referencia al siguiente nodo, pero la doble a-
demás le agrega una referencia al nodo anterior, lo cual permite implementar de
distintas formas en algunos casos más eficiente las funciones anteriormente di-
chas.

	P2-¿Cuáles son las características fundamentales de las Pilas y de las Colas?

	Respuesta: Las reglas "in-out" ó de entrada y salida de los elementos, donde
la pila sigue la regla LIFO "Last In First Out", que significa que el último 
elemento en entrar es el primero en salir, mientras que la cola sigue la regla
FIFO "First In First Out", que significa que el primero en entrar es el primero
en salir.

	P3-¿Qué es un iterador? ¿Cuál es su función?

	Respuesta: Un iterador es un puntero que es utilizado por un algoritmo para 
recorrer secuencialmente los elementos almacenados en un contenedor como un TDA

	P4-¿En qué se diferencia un iterador interno de uno externo?

	Respuesta: Un iterador interno permite recorrer todos los elementos de un TDA
sin tener que controlar el ciclo en el cual se recorre el mismo, ni la estruc-
tura misma del TDA.
	Por su parte el iterador externo es un tda que permite manejar la iteración 
mediante sus propias primitivas, además que este debe conocer la estructura a 
recorrer.
