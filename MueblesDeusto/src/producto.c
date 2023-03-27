/*
 * DUDAS:
 * 	- La categoria hacemos un enum?
 * 	- Cómo le pedimos al usuario el código del producto a modificar? En la misma función o en una función buscarProducto?
 * 	- En modificar -- dejamos que se puedan modificar todos los campos o el codigo no?
 * 	- Devolver prudcto --> podemos escribirlo como lo hemos puesto?
 *
 */

#include <stdio.h>
#include <string.h>
#include "producto.h"

//ADMINISTRADOR:

Producto anadirProducto(ListaProductos *lp){
	Producto p;
	printf("Codigo: \n");
	fflush(stdout);
	fflush(stdin);
	gets(p.cod_p);
	printf("Nombre: \n");
	fflush(stdout);
	fflush(stdin);
	gets(p.nombre);
	printf("Cantidad: \n");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", p.cantidad);
	printf("Precio: \n");
	fflush(stdout);
	fflush(stdin);
	scanf("%.2f", p.precio);
	//Categoria -- enum??
	printf("Categoria: \n");
	fflush(stdout);
	fflush(stdin);
	gets(p.cod_c);
	return p;
}

//Producto buscarProducto(){
//	printf("¿Que producto desea modificar?: ")
//	fflush(stdout);
//	fflush(stdin);
//	gets(p.cod_p);
//}

//Que se pueda cambiar todo o codigo no? + como preguntar que producto modificar
Producto modificarProducto(Producto *p){
//	printf("1. Modificar codigo");
	printf("1. Modificar nombre");
	printf("2. Modificar cantidad");
	printf("3. Modificar precio");
	printf("4. Modificar categoria");
	printf("0. Volver");
	fflush(stdout);
	fflush(stdin);
}

/*Para hacer esto igual es mejor tener un "almacen" con lista de productos que hay el num de productos de
 * ese array
 * Luego hacemos lo de pos=0 y enc=0 (lo mismo con los demás modificar).
 */


void modificarNombre(Almacen *a){
	int enc=0, pos = 0;
	while(enc != 0)
		for (int i = 0; i<a->numP; i++){

	}

}
/*
void modificarDescripcion(Producto *p){

}

void modificarCantidad(Producto *p){

}

void modificarPrecio(Producto *p){

}


Producto eliminarProducto(Producto p, ListaProductos *lp){

}
----------------YO CREO QUE ASI SERIA MAS FACIL-------------------
void ModificarProducto(Producto *p ){ CON UNA SOLA FUNCION MODIFICAS TODOS LOS ATRIBUTOS

}
 */


//CLIENTE
Carrito visualizarCarrito(Carrito c){
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
	scanf("%i", opcion);

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
void devolverProducto(Producto *p){
	printf("Introduce el codigo del producto que quiera devolver: \n");
	fflush(stdout);
	fflush(stdin);
	gets(p->cod_p);
	p->cantidad++;	//Está bien escrito?
	printf("Devolucion finalizada. \n");
}
ListaProductos visualizarTienda(ListaProductos lp){
	int i;
	for (i = 0; i < lp.numProductos; i++) {
		printf("CÓDIGO DEL PRODUCTO: %s\n", lp.aProductos[i].cod_p);
		printf("NOMBRE: %s\n", lp.aProductos[i].nombre);
		printf("CANTIDAD: %d\n", lp.aProductos[i].cantidad);
		printf("PRECIO: %s\n", lp.aProductos[i].precio);
		printf("CATEGORIA: %d\n", lp.aProductos[i].cod_c);	//Coger el codigo de la categoria e imprimir el nombre
	}
	return 0;
}


