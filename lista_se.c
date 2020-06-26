#include "lista.h"
#include "tda_pruebas.h"
#include "pruebas.h"



int main(){
	

	pruebas_t* pruebas=crear_pruebas();
	if(!pruebas){
		perror("Fallo al crear las pruebas");
		return 0;
	}

	printf("\t\tPRUEBAS DE LISTA.\n\n");
	probar_operaciones_lista(pruebas);
	printf(COLOR_NORMAL "\n\n");

	printf("\t\tPRUEBAS DE PILA.\n\n");
	probar_operaciones_pila(pruebas);
	printf(COLOR_NORMAL "\n\n");

	printf("\t\tPRUEBAS DE COLA.\n\n");
	probar_operaciones_cola(pruebas);
	printf(COLOR_NORMAL "\n\n");

	printf("\t\tPRUEBAS DE ITERADOR EXTERNO.\n\n");
	probar_iterador_externo(pruebas);
	printf(COLOR_NORMAL "\n\n");

	printf("\t\tPRUEBAS DE ITERADOR INTERNO.\n\n");
	probar_iterador_interno(pruebas);
	printf(COLOR_NORMAL "\n\n");

	mostrar_resultados(pruebas);
	destruir_pruebas(pruebas);


	return 0;
}

