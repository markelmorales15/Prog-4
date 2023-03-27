/*
 * DUDAS:
 * 	- elimminarProducto() --> Solo la lista de productos o el producto que va a borrar también? --> se puede de las dos formas
 * 	- estructura de carrito tiene que tener el dni del cliente o cómo lo hacemos? --> Si, está bien con el DNI.
 * 	- * en las estructuras, cómo es mejor ponerlo? --> lo podemos dejar con *
 * 	- Cómo hacemos las estadísitcas?
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#include "categoria.h"
#include "cliente.h"

/*
 * Atributos:
 * 	- cod_p
 * 	- nombre
 * 	- descripción
 * 	- cantidad
 * 	- precio
 * 	- cod_c (Categoria)
 */

typedef struct{
    char cod_p[10];
    char nombre[20];
    char descripcion[20];
    int cantidad;
    double precio;
    enum Categoria tipo;
} Producto;

typedef struct{
	Producto *aProductos;
	int tam;
	int numProductos;
} ListaProductos;

//ADMIN
void anadirProducto(ListaProductos *lp);
Producto buscarProducto(ListaProductos lp);
void modificarProducto(Producto *p);
void eliminarProducto(Producto p, ListaProductos *lp);	//Solo lista o producto tambien?

//CLIENTE
void devolverProducto(Producto *p);
ListaProductos visualizarTienda(ListaProductos lp);

//Estadisticas

#endif /* PRODUCTO_H_ */
