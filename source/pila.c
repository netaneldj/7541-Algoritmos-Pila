#include "pila.h"
#include <stdlib.h>
#define TAM_INICIAL 10

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t capacidad;
    size_t cantidad;
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

//Crea una pila vacia de capacidad TAM_INICIAL 
pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));
	if(pila==NULL){
		return NULL;
	}
	pila->datos = malloc(TAM_INICIAL*sizeof(void*));
	if(pila->datos==NULL){
		free(pila);
		return NULL;
	}
	pila->capacidad=TAM_INICIAL;
	pila->cantidad=0;
	return pila;
}
//Redimenciona la pila ya sea para agrandar o achicar
bool pila_redimensionar(pila_t* pila, size_t tam_nuevo) {
    void* aux = realloc(pila->datos,tam_nuevo*sizeof(void*));
    if(tam_nuevo >0 && aux==NULL){
		return false;
	}
	pila->datos = aux;
	pila->capacidad = tam_nuevo;
	return true;
}
//Destruye la pila
void pila_destruir(pila_t* pila){
	free(pila->datos);
	free(pila);
}
//Devuelve si la pila esta vacia o no
bool pila_esta_vacia(const pila_t* pila){
	if(pila->cantidad==0){
		return true;
	}
	return false;
}
//Apila un elemento a la pila
bool pila_apilar(pila_t *pila, void* valor){
	if(pila->cantidad>=pila->capacidad-2){
		if(!pila_redimensionar(pila,pila->capacidad*2)){
			return false;
		}
	}
	pila->cantidad++;
	pila->datos[pila->cantidad]=valor;
	return true;
}
//Devuelve el elemento que se encuentra en el tope de la pila
void* pila_ver_tope(const pila_t *pila){
	if(pila->cantidad>0){
		return pila->datos[pila->cantidad];
	}
	return NULL;
}
//Desapila el elemento del tope y devuelve su valor
void* pila_desapilar(pila_t *pila){
	if(pila_esta_vacia(pila)){
		return NULL;
	}
	void* val=pila->datos[pila->cantidad];
	if(pila->cantidad<(pila->capacidad/4)){
		pila_redimensionar(pila,pila->capacidad/2);
	}
	pila->cantidad--;
	return val;
}
