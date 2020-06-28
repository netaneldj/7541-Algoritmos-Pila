#include "pila.h"
#include "testing.h"
#include <stddef.h>
#define ELEMENTOS 150


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

/* *Recibe un array y una pila
   *Apila las direcciones de memoria de los elementos del array en la pila
   *Compara si la direccion que apilo es igual a la del array*/
void prueba_apilar_tope(int valores[],pila_t* mi_pila){
	for(int i=0;i<ELEMENTOS;i++){
		pila_apilar(mi_pila,&valores[i]);
		print_test("¿Son iguales apilado y tope?",pila_ver_tope(mi_pila)==&valores[i]);
	}
}
/* *Recibe un array y una pila
   *Desapila los elementos de la pila y compara si son iguales a las direcciones de memoria de los elementos del arrray 
   * Al finalizar verifica si la pila esta vacia*/
void prueba_desapilar_vacia(int valores[],pila_t* mi_pila){
	for(int i=0;i<ELEMENTOS;i++){
		print_test("¿Son iguales desapilado y vector?",pila_desapilar(mi_pila)==&valores[i]);
	}
	print_test("La pila esta vacia?",pila_esta_vacia(mi_pila));
}
/* *Recibe dos pilas
   *Apila en la segunda los elementos de la primera
   *Al finalizar verifica que la primer pila este vacia y que la segunda no lo este*/
void prueba_apilar_desapilar(pila_t* pila_1,pila_t* pila_2){
	for(int i=0;i<ELEMENTOS;i++){
		pila_apilar(pila_2,pila_desapilar(pila_1));
	}
	print_test("¿Esta vacia la pila 1?",pila_esta_vacia(pila_1));
	print_test("¿Contiene elementos la pila 2?",pila_esta_vacia(pila_2)==false);
}


void pruebas_pila_alumno(void) {
    //Creo un array para despues apilar las direcciones de memoria en la pila
    int valores[ELEMENTOS];
    for(int i=0;i<ELEMENTOS;i++){
		valores[i]=i;
	}
	//Creo dos pilas
    pila_t* pila_1 = pila_crear();
    pila_t* pila_2 = pila_crear();
    //Realizo las pruebas de apilar y ver tope...
    prueba_apilar_tope(valores,pila_1);
    //Prueba de apilar-desapilar
    prueba_apilar_desapilar(pila_1,pila_2);
    //Para finalizar realizo las pruebas de desapilar y esta vacia...
    prueba_desapilar_vacia(valores,pila_2);
    //Destruyo las pilas creadas
    pila_destruir(pila_1);
    pila_destruir(pila_2);
}
