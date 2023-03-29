/*
 * DUDAS: en los menús, int o void -->
 */

#include "cliente.h"
#include <stdio.h>
#include <string.h>
#include "menus.h"


int menuInicio(){
	int opcion = 0;
	printf("\nMENÚ INICIO: \n");
	printf("---------------------- \n");
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
	int opcion = 0;
	printf("\nMENÚ ADMIN: \n");
	printf("---------------------- \n");
	printf("1. Anadir un producto \n");
	printf("2. Modificar un producto \n");
	printf("3. Eliminar un producto \n");
	printf("4. Estadisticas \n");
	printf("0. Salir \n");
	printf("Selecciona una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
int menuCliente(){
	int opcion = 0;
	printf("\nMENÚ CLIENTE: \n");
	printf("---------------------- \n");
	printf("1. Visualizar el carrito de la compra \n");	//HECHO
	printf("2. Devolver un producto \n"); //HECHO
	printf("3. Visualizar los productos de la tienda \n"); //HECHO
	printf("4. Buscar un producto \n");
	printf("0. Salir \n");
	printf("Selecciona una opción: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}

Cliente inicioSesion(){
	Cliente c;
	printf("\nIntroduce el nombre de usuario: ");
	fflush(stdout);
	fflush(stdin);
	gets(c.usuario);
	printf("Introduce la contrasenya: ");
	fflush(stdout);
	fflush(stdin);
	gets(c.contrasena);
	return c;
}
