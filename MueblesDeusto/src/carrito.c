#include "carrito.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int mostrarCarrito(Carrito c) {
	Producto p;
	imprimirCarrito(c);
	int opcion;

	do {
		printf("\n1. Comprar \n");
		fflush(stdout);
		printf("2. Eliminar producto \n");
		fflush(stdout);
		printf("0. Volver \n");
		fflush(stdout);
		fflush(stdin);
		printf("Selecciona una opción: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%i", &opcion);
		switch (opcion) {
		case 1:
			//tenemos que vaciar el carrito
			imprimirTicket(c, "Ticket");//Cambiar el nombre para cada cliente
			printf("\nLa compra se ha realizado con éxito y su ticket de la compra ha sido generado.\n");
			break;
		case 2:
			p = nombreProductoBorrar();
			eliminarProductoCarrito(&c, p);
			imprimirCarrito(c);
			break;
		case 0:
			printf("\nAgur! \n");
			fflush(stdout);
			break;
		default:
			printf("Error! \n");
			fflush(stdout);
			break;

		}
	} while (opcion != 0);
	return opcion;
}

void imprimirCarrito(Carrito c) {
	printf("\nCarrito del usuario %s:\n", c.dni);
	fflush(stdout);
	for (int i = 0; i < c.numProductos; i++) {
		printf("[PRODUCTO %d: ", i + 1);
		fflush(stdout);
		printf("NOMBRE: %s, ", c.aProductos[i].nombre);
		fflush(stdout);
		printf("CANTIDAD: %d, ", c.aProductos[i].cantidad);
		fflush(stdout);
		printf("PRECIO: %.2f]\n", c.aProductos[i].precio);
		fflush(stdout);
	}
}

void imprimirTicket(Carrito c, char *nombreFichero) {
	FILE *f = fopen(nombreFichero, "w");
	if (f == NULL) {
		printf("Error al abrir el archivo\n");
		return;
	}

	// Escribir cabecera del ticket
//    time_t t = time(NULL);
//    struct tm tm = *localtime(&t);
	fprintf(f, "TICKET DE COMPRA\n");
//    fprintf(f, "Fecha: %02d/%02d/%04d %02d:%02d:%02d\n",
//            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
//            tm.tm_hour, tm.tm_min, tm.tm_sec);
	fprintf(f, "Cliente: %s\n", c.dni);
	fprintf(f, "-----------------------------\n");

	// Escribir información de productos
	for (int i = 0; i < c.numProductos; i++) {
		fprintf(f, "Producto %d:\n", i + 1);
		fprintf(f, "Nombre: %s\n", c.aProductos[i].nombre);
		fprintf(f, "Descripción: %s\n", c.aProductos[i].descripcion);
		fprintf(f, "Cantidad: %d\n", c.aProductos[i].cantidad);
		fprintf(f, "Precio: %.2f €\n", c.aProductos[i].precio);
		fprintf(f, "-----------------------------\n");
	}

	// Escribir importe total
	fprintf(f, "Importe total: %.2f €\n", c.importeTotal);

	// Cerrar archivo
	fclose(f);
}


void eliminarProductoCarrito(Carrito *carrito, Producto producto) {
	int i;
	int encontrado = 0;

	for (i = 0; i < carrito->numProductos; i++) {
		if (strcmp(carrito->aProductos[i].nombre, producto.nombre) == 0) {
			// Producto encontrado, eliminamos y actualizamos el importe total
			carrito->importeTotal -= carrito->aProductos[i].precio;
			for (int j = i; j < carrito->numProductos - 1; j++) {
				carrito->aProductos[j] = carrito->aProductos[j + 1];
			}
			carrito->numProductos--;
			i--; // Decrementamos i para que se compruebe el producto en la nueva posición i
			encontrado = 1;
		}
	}
	if(carrito->numProductos == 0){
			printf("Su carrito está vacio.\n");
			fflush(stdout);
			fflush(stdin);
	}else if (encontrado == 0) {
		printf("\nEl producto que desea borrar no está en su carrito. \n");
		fflush(stdout);
		fflush(stdin);
	}

}

void aniadirProductoCarrito(Carrito *carrito, Producto p) {
	carrito->numProductos++;
	carrito->aProductos = realloc(carrito->aProductos, carrito->numProductos * sizeof(Producto));
	carrito->aProductos[carrito->numProductos - 1] = p;
}

void comprarCarrito(Carrito *carrito) {
    carrito->numProductos = 0;
    free(carrito->aProductos);
    carrito->aProductos = NULL;
    carrito->importeTotal = 0.0;
}

