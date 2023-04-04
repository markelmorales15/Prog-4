#ifndef CARRITO_H_
#define CARRITO_H_
#include "cliente.h"
#include "producto.h"

typedef struct{
	Producto *aProductos;
	int numProductos;
	char dni[10];
	float importeTotal;
} Carrito;

int mostrarCarrito(Carrito *c);
void imprimirCarrito(Carrito c);
void imprimirTicket (Carrito c, char *nombreFichero);
void eliminarProductoCarrito(Carrito *carrito, Producto producto);//el puntero de nombre no es 100% correcrto, hasta que se pergunte a marian
void aniadirProductoCarrito(Carrito* carrito, Producto p);
void comprarCarrito(Carrito *c);
int menuBuscar(Carrito *c, ListaProductos lp);


#endif /* CARRITO_H_ */
