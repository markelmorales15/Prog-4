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
	int tam;
	int numProductos;
	Cliente dni;
	float importeTotal;
} Carrito;//ES LO MISMO QUE COMPRA

void mostrarCarrito(Carrito c);//ver carrito de compra
void eliminarProductoCarrito(Carrito *carrito, Producto producto);//el puntero de nombre no es 100% correcrto, hasta que se pergunte a marian
void aniadirProductoCarrito(Carrito* carrito, Producto p);

#endif /* CARRITO_H_ */
