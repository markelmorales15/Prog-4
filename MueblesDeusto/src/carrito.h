/*
 * Carrito.h
 *
 *  Created on: 26 mar 2023
 *      Author: marke
 */

#ifndef CARRITO_H_
#define CARRITO_H_
#include "cliente.h"
#include "producto.h"

typedef struct{
	Producto *aProductos;
	int numProductos;
	Cliente dni[15];
	float importeTotal;
} Carrito;//ES LO MISMO QUE COMPRA

int mostrarCarrito(Carrito c);//ver carrito de compra
void imprimirCarrito(Carrito c);
void eliminarProductoCarrito(Carrito *carrito, Producto producto);//el puntero de nombre no es 100% correcrto, hasta que se pergunte a marian
void aniadirProductoCarrito(Carrito* carrito, Producto p);
void comprarCarrito(Carrito *c);
void imprimirTicket (Carrito c, char *nombreFichero);


#endif /* CARRITO_H_ */
