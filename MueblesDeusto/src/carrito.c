#include "carrito.h"
#include <stdio.h>

void mostraCarrito(Carrito c){
	//Mostrar productos cliente
	int opcion;
	printf("1. Comprar \n");
	printf("2. Eliminar producto \n");
	printf("0. Volver \n");
	fflush(stdout);
	fflush(stdin);
	printf("Introduce un número: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &opcion);

	do {
		switch (opcion) {
		case 1:
			//Codigo comprar
			break;
		case 2:
			//Codigo eliminar producto
			break;
		case 0:
			//Volver al menú del cliente
			break;
		default:
			printf("Error! \n");
			fflush(stdout);
			break;
		}
	} while (opcion != 0);
}
void eliminarProductoCarrito(Carrito *carrito, Producto producto){

}
void aniadirProductoCarrito(Carrito* carrito, Producto p){

}
