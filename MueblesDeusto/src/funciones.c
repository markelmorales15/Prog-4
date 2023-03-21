/*
 * DUDAS: en los menús, int o void -->
 */

#include "funciones.h"

#include <stdio.h>
#include <string.h>


int menuInicio(){
	int opcion;
	printf("1. Registrarse \n");
	printf("2. Iniciar sesion \n");
	printf("0. Salir \n");
	printf("Selecciona una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
int menuAdmin(){
	int opcion;
	printf("1. Anadir un producto \n");
	printf("2. Modificar un producto \n");
	printf("3. Eliminar un producto \n");
	printf("4. Estadisticas \n");
	printf("0. Salir \n");
	fflush(stdout);
	fflush(stdin);
}
int menuCliente(){
	int opcion;
	printf("1. Visualizar el carrito de la compra \n");
	printf("2. Devolver un producto \n");
	printf("3. Visualizar los productos de la tienda \n");
	printf("4. Buscar un producto \n");
	printf("0. Salir \n");
	fflush(stdout);
	fflush(stdin);
}
