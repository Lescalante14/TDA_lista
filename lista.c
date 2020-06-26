#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

#define EXITO 0
#define ERROR -1



typedef struct nodo{
	void* elemento;
	struct nodo* siguiente;
}nodo_t;

struct lista {
	nodo_t* primer_nodo;
	nodo_t* ultimo_nodo;
	int cantidad_elementos;
};

struct lista_iterador {
	lista_t* lista;
	nodo_t* nodo_actual;
};






lista_t* lista_crear(){

	return calloc(1, sizeof(lista_t));
}


size_t lista_elementos(lista_t* lista){

	if(!lista)
		return 0;
	return ((size_t)lista->cantidad_elementos);
}


int lista_insertar(lista_t* lista, void* elemento){

	if(!lista)
		return ERROR;

	nodo_t* nuevo_nodo=malloc(sizeof(nodo_t));
	if(!nuevo_nodo)
		return ERROR;

	nuevo_nodo->elemento=elemento;
	nuevo_nodo->siguiente=NULL;
	if(lista_elementos(lista)==0)
		lista->primer_nodo=nuevo_nodo;
	else
		lista->ultimo_nodo->siguiente=nuevo_nodo;
	
	lista->ultimo_nodo=nuevo_nodo;
	lista->cantidad_elementos++;
	
	return EXITO;
}


/* Enlaza el nodo anterior con el nuevo y ese con el siguiente
 *			 -->anterior-->nuevo-->siguiente-->
 */
void enlazar_nodos(nodo_t* nuevo, nodo_t* anterior, nodo_t* siguiente){

	nuevo->siguiente=siguiente;
	anterior->siguiente=nuevo;
}



int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){

	if(!lista)
		return ERROR;
	
	if(posicion>=lista_elementos(lista))
		return lista_insertar(lista, elemento);
	
	nodo_t* nuevo_nodo=malloc(sizeof(nodo_t));
	nuevo_nodo->elemento=elemento;
	nuevo_nodo->siguiente=lista->primer_nodo;
	
	if(posicion==0)
		lista->primer_nodo=nuevo_nodo;
	else{	
		for (int i = 0; i < posicion-1; i++)
			nuevo_nodo->siguiente=nuevo_nodo->siguiente->siguiente;
		enlazar_nodos(nuevo_nodo, nuevo_nodo->siguiente, nuevo_nodo->siguiente->siguiente);
	}
	lista->cantidad_elementos++;
	return EXITO;
}


int lista_borrar(lista_t* lista){

	if(!lista || lista_vacia(lista))
		return ERROR;

	free(lista->ultimo_nodo);
	lista->cantidad_elementos--;
	if(lista_vacia(lista)){
		lista->primer_nodo=NULL;
		lista->ultimo_nodo=NULL;
	}else{
		lista->ultimo_nodo=lista->primer_nodo;
		for(int i=0; i<lista_elementos(lista)-1; i++)
			lista->ultimo_nodo=lista->ultimo_nodo->siguiente;
		lista->ultimo_nodo->siguiente=NULL;
	}
	
	return EXITO;
}


int lista_borrar_de_posicion(lista_t* lista, size_t posicion){

	if(!lista)
		return ERROR;

	if(lista_vacia(lista) || posicion>=lista_elementos(lista)-1)
		return lista_borrar(lista);

	void* nodo_a_eliminar;
	nodo_t nodo_aux;
	if(posicion==0){
		nodo_a_eliminar=lista->primer_nodo;
		lista->primer_nodo=lista->primer_nodo->siguiente;
	}else{		
		nodo_aux.siguiente=lista->primer_nodo;
		for(int i = 0; i < posicion-1; i++)   							 //Saldrá del for con nodo_aux->siguiente
			nodo_aux.siguiente=nodo_aux.siguiente->siguiente;			 //apuntando al nodo anterior a eliminar
		
		nodo_a_eliminar=nodo_aux.siguiente->siguiente;
		nodo_aux.siguiente->siguiente = nodo_aux.siguiente->siguiente->siguiente; // enlazo el anterior con el  
		 													                      //siguiente del nodo a eliminar
	}
	free(nodo_a_eliminar);
	lista->cantidad_elementos--;
	return EXITO;
}


void* lista_ultimo(lista_t* lista){

	if(!lista || lista_elementos(lista)==0)
		return NULL;
	return lista->ultimo_nodo->elemento;
}


void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){

	if(!lista || posicion>=lista_elementos(lista))
		return NULL;

	nodo_t* nodo_aux;

	if(posicion+1==lista_elementos(lista))
		nodo_aux=lista->ultimo_nodo;
	else{	
		nodo_aux=lista->primer_nodo;
		for(int i = 0; i < posicion; i++){
			nodo_aux=nodo_aux->siguiente;
		}
	}

	return nodo_aux->elemento;
}


bool lista_vacia(lista_t* lista){

	return(lista_elementos(lista)==0);
}



int lista_apilar(lista_t* lista, void* elemento){
	
	return lista_insertar(lista, elemento);
}


int lista_desapilar(lista_t* lista){

	return lista_borrar(lista);
}

void* lista_tope(lista_t* lista){

	return lista_ultimo(lista);
}



int lista_encolar(lista_t* lista, void* elemento){

	return lista_insertar_en_posicion(lista, elemento, 0);
}


int lista_desencolar(lista_t* lista){

	return lista_borrar(lista);
}


void* lista_primero(lista_t* lista){

	return lista_ultimo(lista);
}




void lista_destruir(lista_t* lista){

	if(!lista)
		return;
	
	nodo_t* aux;
	for (int i = 0; i < lista_elementos(lista); i++){
		aux=lista->primer_nodo->siguiente;
		free(lista->primer_nodo);
		lista->primer_nodo=aux;
	}
	free(lista);
}



lista_iterador_t* lista_iterador_crear(lista_t* lista){

	if(!lista)
		return NULL;
	
	lista_iterador_t* iterador=malloc(sizeof(lista_iterador_t));
	if(!iterador)
		return NULL;

	iterador->lista=lista;
	iterador->nodo_actual=lista->primer_nodo;

	return iterador;
}


bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){

	if(!iterador)
		return false;

	return !(iterador->nodo_actual == NULL);
}


void* lista_iterador_siguiente(lista_iterador_t* iterador){

	if(!iterador || !iterador->nodo_actual)
		return NULL;

	void* elemento= iterador->nodo_actual->elemento; 
	iterador->nodo_actual=iterador->nodo_actual->siguiente;

	return elemento;
}


void lista_iterador_destruir(lista_iterador_t* iterador){

	free(iterador);
}


void lista_con_cada_elemento(lista_t* lista, void (*funcion)(void*, void*), void *contexto){

	if(!lista)
		return; 

	nodo_t* nodo_aux=lista->primer_nodo;
	for(int i=0; i<lista_elementos(lista); i++){
		funcion(nodo_aux->elemento, contexto);
		nodo_aux=nodo_aux->siguiente;
	}
}