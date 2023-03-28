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
#include "categoria.h"
typedef struct{
    char cod_p[10];
    char nombre[20];
    char descripcion[20];
    int cantidad;
    double precio;
    CategoriaProducto tipo;
} Producto;

typedef struct{
	Producto *aProductos;
	int numProductos;
} ListaProductos;

//ADMIN
void anadirProducto(ListaProductos *lp);
ListaProductos buscarProducto(ListaProductos lp, CategoriaProducto c);	//Categoria
void modificarProducto(Producto *p);
void eliminarProducto(Producto p, ListaProductos *lp);	//Solo lista o producto tambien?
void modificarNombre(Producto *p);
void modificarDescripcion(Producto *p);
void modificarCantidad(Producto *p);
void modificarPrecio(Producto *p);
void volcarFicheroAListaProductos(ListaProductos *lp, char *nombreFichero);
void imprimirListaProductos (ListaProductos lp);

//CLIENTE
void devolverProducto(ListaProductos *lp, Producto nombreProducto);	//Añadir a la lista de productos de la tienda (hacer más uno en su cantidad)
void visualizarTienda(ListaProductos lp);
Producto nombreProductoBorrar();
Producto nombreProductoDevolver();

//Estadisticas

#endif /* PRODUCTO_H_ */
