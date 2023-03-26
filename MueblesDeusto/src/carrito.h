/*
 * Carrito.h
 *
 *  Created on: 26 mar 2023
 *      Author: marke
 */

#ifndef CARRITO_H_
#define CARRITO_H_

typedef struct{
	Producto *aProductos;
	int tam;
	int numProductos;
	Cliente dni;
} Carrito;//ES LO MISMO QUE COMPRA

typedef struct{
	Carrito *carrito;
	int numCarrito;
	float importeTotal;
} ListaCarrito;

void mostrarCarrito(Carrito c);//ver carrito de compra
void EliminarProductoCarrito(Producto *lista, char *nombre);//el puntero de nombre no es 100% correcrto, hasta que se pergunte a marian
void AniadirProducto(Producto *lista, Producto p);

#endif /* CARRITO_H_ */
