#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_
#include "producto.h"
/*
 * Atributos:
 * 	- dni
 * 	- usuario
 * 	- contraseña
 */

typedef struct{
    char dni[10];
    char usuario[20];
    char contrasena[20];
} Admin;

typedef struct{
	Admin *aAdmin;
	int numC;	//Numero de adminstradores en la lista
}ListaAdmin;


Producto anadirProducto(ListaProductos *lp);
Producto buscarProducto(ListaProductos lp);
Producto modificarProducto(Producto *p);
void modificarNombre(Producto *p);
void modificarDescripcion(Producto *p);
void modificarCantidad(Producto *p);
void modificarPrecio(Producto *p);
Producto eliminarProducto(Producto p, ListaProductos *lp);
#endif /* ADMINISTRADOR_H_ */
