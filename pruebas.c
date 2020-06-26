#include "lista.h"
#include "pruebas.h"
#include "tda_pruebas.h"


void inicializa_vector(int vector[], int tope){

	for (int i = 0; i < tope; i++)
		vector[i]=i;
}



/////***FUNCIONES USADAS POR PROBAR LISTA***/////



void probar_lista_insertar_y_borrar(pruebas_t* pruebas, lista_t* lista){

	printf(COLOR_NORMAL "\n--PRUEBAS DE INSERTAR Y BORRAR\n\n");
	int elementos[2];
	inicializa_vector(elementos,2);

	validar_prueba(pruebas,"Se inserta un elemento correctamente.",
				   lista_insertar(lista, &elementos[0])==EXITO);
	
	validar_prueba(pruebas,"El elemento insertado es el correcto.",
				   *(int*)lista_ultimo(lista)==elementos[0]);
	
	validar_prueba(pruebas,"Se inserta un elemento correctamente al final.",
				   (lista_insertar(lista, &elementos[1])==EXITO && 
				   	*(int*)lista_ultimo(lista)==elementos[1]));
	
	validar_prueba(pruebas, "Se borra el ultimo elemento correctamente.",
				   lista_borrar(lista)==EXITO && 
				   *(int*)lista_ultimo(lista)==elementos[0]);
	
	validar_prueba(pruebas, "Se borra el ultimo elemento correctamente y lista queda vacia.",
				   lista_borrar(lista)==EXITO && lista_vacia(lista));
	
	validar_prueba(pruebas, "No se puede borrar en una lista vacia.",
				   lista_borrar(lista)==ERROR);
}


void probar_lista_insertar_en_posicion(pruebas_t* pruebas, lista_t* lista){

	printf(COLOR_NORMAL "\n--PRUEBAS DE INSERTAR EN POSICION\n\n");
	int elementos[10];
	inicializa_vector(elementos,10);

	for (int i = 0; i < 5; i++)
		lista_insertar(lista, &elementos[i]);

	validar_prueba(pruebas,"Se inserta un elemento en posicion 0.",
				   lista_insertar_en_posicion(lista, &elementos[5],0)==EXITO);
	
	validar_prueba(pruebas,"Se inserta un elemento en una posicion de la lista correctamente.",
				   lista_insertar_en_posicion(lista, &elementos[6],3)==EXITO &&
				   *(int*)lista_elemento_en_posicion(lista,3)==elementos[6]);
	
	validar_prueba(pruebas,"Se inserta un elemento dado una posicion inexistente.",
				   lista_insertar_en_posicion(lista, &elementos[0],100)==EXITO);
	
	validar_prueba(pruebas,"Se inserta un elemento al final dado una posicion inexistente.",
				   lista_insertar_en_posicion(lista, &elementos[1],100)==EXITO &&
				   *(int*)lista_ultimo(lista)==elementos[1]);
}


void probar_lista_borrar_de_posicion(pruebas_t* pruebas, lista_t* lista){

	printf(COLOR_NORMAL "\n--PRUEBAS DE BORRAR DE POSICION\n\n");
	int elementos[10];
	inicializa_vector(elementos,10);

	validar_prueba(pruebas, "No se puede borrar una posicion en una lista vacia.",
				   lista_borrar_de_posicion(lista,2)==ERROR);

	for (int i = 0; i < 10; i++)
		lista_insertar(lista, &elementos[i]);

	validar_prueba(pruebas, "Dado una posicion inexistente, borra el ultimo.",
				   lista_borrar_de_posicion(lista,20)==EXITO &&
				   *(int*)lista_ultimo(lista)==elementos[8]);

	validar_prueba(pruebas, "Se puede borrar el elemento de una posicion.",
				   lista_borrar_de_posicion(lista,5)==EXITO);

	validar_prueba(pruebas, "El elemento eliminado era el esperado",
				   *(int*)lista_elemento_en_posicion(lista,5)==elementos[6]);

	validar_prueba(pruebas, "Se borra correctamente el primer elemento",
				   lista_borrar_de_posicion(lista,0)==EXITO &&
				   *(int*)lista_elemento_en_posicion(lista,0)==elementos[1]);
}


void probar_lista_null(pruebas_t* pruebas, lista_t* lista){

	printf(COLOR_NORMAL "\n--PRUEBAS DE LISTA CON VALORES NULL\n\n");
	int elemento=10;

	lista_insertar(lista, &elemento);

	validar_prueba(pruebas,"No se puede insertar en lista NULL.",
				   lista_insertar(NULL, &elemento)==ERROR);

	validar_prueba(pruebas,"No se puede borrar en lista NULL.",
				   lista_borrar(NULL)==ERROR);

	validar_prueba(pruebas,"No se puede insertar en posicion en lista NULL.",
				   lista_insertar_en_posicion(NULL, &elemento, 1)==ERROR);

	validar_prueba(pruebas,"No se puede borrar de posicion en lista NULL.",
				   lista_borrar_de_posicion(NULL, 1)==ERROR);

	validar_prueba(pruebas,"Lista elemento en posicion devuelve  NULL si no existe la posicion",
				   lista_elemento_en_posicion(lista, 10)==NULL);

	validar_prueba(pruebas,"Lista NULL se considera vacia.",lista_vacia(NULL));

	validar_prueba(pruebas,"Se puede insertar en lista un elemento NULL.",
				   lista_insertar(lista, NULL)==EXITO);
}



/////***FUNCIONES USADAS POR PROBAR PILA***/////



void probar_lista_apilar(pruebas_t* pruebas, lista_t* pila){

	printf(COLOR_NORMAL "\n--PRUEBAS DE APILAR\n\n");
	int elementos[2];
	inicializa_vector(elementos,2);

	validar_prueba(pruebas,"Se apila un elemento correctamente",
				   lista_apilar(pila, &elementos[0])==EXITO);

	validar_prueba(pruebas,"Se apila otro elemento correctamente",
				   lista_apilar(pila, &elementos[1])==EXITO);
}


void probar_lista_desapilar(pruebas_t* pruebas, lista_t* pila){

	printf(COLOR_NORMAL "\n--PRUEBAS DE DESAPILAR\n\n");
	int elementos[2];
	inicializa_vector(elementos,2);

	for (int i = 0; i < 2; i++)
		lista_apilar(pila, &elementos[i]);

	validar_prueba(pruebas,"Se desapila un elemento correctamente",
				   lista_desapilar(pila)==EXITO);

	validar_prueba(pruebas,"Se desapila otro elemento correctamente",
				   lista_desapilar(pila)==EXITO);

	validar_prueba(pruebas,"No se puede desapilar de una pila vacia",
				   lista_desapilar(pila)==ERROR);
}


void probar_lista_tope(pruebas_t* pruebas, lista_t* pila){

	printf(COLOR_NORMAL "\n--PRUEBA LISTA TOPE\n\n");
	int elementos[2];
	inicializa_vector(elementos,2);

	validar_prueba(pruebas,"Lista tope devuelve NULL si pila esta vacia",
				   lista_tope(pila)==NULL);

	for (int i = 0; i < 2; i++)
		lista_apilar(pila, &elementos[i]);

	validar_prueba(pruebas,"Lista tope devuelve el tope",
				   *(int*)lista_tope(pila)==elementos[1]);
}



/////***FUNCIONES USADAS POR PROBAR COLA***/////



void probar_lista_encolar(pruebas_t* pruebas, lista_t* cola){

	printf(COLOR_NORMAL "\n--PRUEBAS DE ENCOLAR\n\n");
	int elementos[2];
	inicializa_vector(elementos,2);

	validar_prueba(pruebas,"Se encola un elemento correctamente",
				   lista_encolar(cola, &elementos[0])==EXITO);

	validar_prueba(pruebas,"Se encola otro elemento correctamente",
				   lista_encolar(cola, &elementos[1])==EXITO);
}


void probar_lista_desencolar(pruebas_t* pruebas, lista_t* cola){

	printf(COLOR_NORMAL "\n--PRUEBAS DE DESENCOLAR\n\n");
	int elementos[2];
	inicializa_vector(elementos,2);

	for (int i = 0; i < 2; i++)
		lista_encolar(cola, &elementos[i]);

	validar_prueba(pruebas,"Se desencola un elemento correctamente",
				   lista_desencolar(cola)==EXITO);

	validar_prueba(pruebas,"Se desencola otro elemento correctamente",
				   lista_desencolar(cola)==EXITO);

	validar_prueba(pruebas,"No se puede desencolar de una cola vacia",
				   lista_desencolar(cola)==ERROR);
}


void probar_lista_primero(pruebas_t* pruebas, lista_t* cola){

	printf(COLOR_NORMAL "\n--PRUEBA LISTA PRIMERO\n\n");
	int elementos[2];
	inicializa_vector(elementos,2);

	validar_prueba(pruebas,"Lista primero devuelve NULL si cola esta vacia",
				   lista_primero(cola)==NULL);

	for (int i = 0; i < 2; i++)
		lista_encolar(cola, &elementos[i]);

	validar_prueba(pruebas,"Lista primero devuelve el primero encolado",
				   *(int*)lista_primero(cola)==elementos[0]);
}



/////***FUNCION USADA POR PROBAR ITERADOR INTERNO***/////



void sumar_elementos(void* elemento, void* contador){

	if(elemento && contador)
		(*(int*)contador)+=(*(int*)elemento);
}



/////***FUNCIONES LLAMADAS EN EL MAIN***/////



void probar_operaciones_lista(pruebas_t* pruebas){
	
	{
		lista_t* lista=lista_crear();

		validar_prueba(pruebas,"Se creo la lista correctamente.",lista!=NULL);
		validar_prueba(pruebas,"Se creo la lista vacia.",lista_vacia(lista));

	
		probar_lista_insertar_y_borrar(pruebas, lista);
		lista_destruir(lista);
	}

	{
		lista_t* lista=lista_crear();
		probar_lista_insertar_en_posicion(pruebas, lista);
		lista_destruir(lista);
	}

	{
		lista_t* lista=lista_crear();
		probar_lista_borrar_de_posicion(pruebas, lista);
		lista_destruir(lista);
	}

	{
		lista_t* lista=lista_crear();
		probar_lista_null(pruebas, lista);
		lista_destruir(lista);
	}
}



void probar_operaciones_pila(pruebas_t* pruebas){

	{
		lista_t* pila=lista_crear();
		probar_lista_apilar(pruebas, pila);
		lista_destruir(pila);
	}

	{
		lista_t* pila=lista_crear();
		probar_lista_desapilar(pruebas, pila);
		lista_destruir(pila);
	}

	{
		lista_t* pila=lista_crear();
		probar_lista_tope(pruebas, pila);
		lista_destruir(pila);
	}
}



void probar_operaciones_cola(pruebas_t* pruebas){

	{
		lista_t* cola=lista_crear();
		probar_lista_encolar(pruebas, cola);
		lista_destruir(cola);
	}

	{
		lista_t* cola=lista_crear();
		probar_lista_desencolar(pruebas, cola);
		lista_destruir(cola);
	}

	{
		lista_t* cola=lista_crear();
		probar_lista_primero(pruebas, cola);
		lista_destruir(cola);
	}
}


void probar_iterador_externo(pruebas_t* pruebas){

//Pruebas con NULL
	validar_prueba(pruebas, "Dada lista NULL no se crea el iterador",
				   lista_iterador_crear(NULL)==NULL);

	validar_prueba(pruebas,"IT NULL no tiene siguiente",
				   !lista_iterador_tiene_siguiente(NULL)); 

	validar_prueba(pruebas,"IT NULL no devuelve elemento",
				   lista_iterador_siguiente(NULL)==NULL);
	
	lista_t* lista=lista_crear();
	int elementos[2];
	inicializa_vector(elementos,2);
	for (int i = 0; i < 2; i++)
		lista_insertar(lista, &elementos[i]);

	lista_iterador_t* iterador=lista_iterador_crear(lista);

	validar_prueba(pruebas,"El iterador se crea correctamente", iterador!=NULL);

	validar_prueba(pruebas,"Iterador tiene siguiente y devuelve true",
				   lista_iterador_tiene_siguiente(iterador));

	validar_prueba(pruebas,"Iterador siguiente devuelve el primer elemento en el primer llamado",
				   *(int*)lista_iterador_siguiente(iterador)==elementos[0]);

	validar_prueba(pruebas,"Iterador siguiente avanza correctamente",
				   *(int*)lista_iterador_siguiente(iterador)==elementos[1]);

//lista quedó vacía

	validar_prueba(pruebas,"Si lista esta vacia, iterador tiene siguiente devuelve false",
				   !lista_iterador_tiene_siguiente(iterador));

	validar_prueba(pruebas,"Si lista esta vacia, iterador siguiente devuelve NULL",
				   lista_iterador_siguiente(iterador)==NULL);


	lista_destruir(lista);
	lista_iterador_destruir(iterador);
}


void probar_iterador_interno(pruebas_t* pruebas){

	lista_t* lista=lista_crear();
	int contador=0;
	int suma_aux_vector=0;  // lo uso para despues comparar que el it interno sumó correctamente
	int elementos[5];
	inicializa_vector(elementos,5);
	for (int i = 0; i < 5; i++){
		lista_insertar(lista, &elementos[i]);
		suma_aux_vector+=i;
	}

	lista_con_cada_elemento(lista, sumar_elementos, &contador);

	validar_prueba(pruebas,"Sumar los enteros de una lista", contador==suma_aux_vector);

	lista_destruir(lista);
}