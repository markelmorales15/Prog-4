/*
 * DUDAS:
 * 	- La categoria hacemos un enum?
 * 	- Cómo le pedimos al usuario el código del producto a modificar? En la misma función o en una función buscarProducto?
 * 	- En modificar -- dejamos que se puedan modificar todos los campos o el codigo no?
 * 	- Devolver prudcto --> podemos escribirlo como lo hemos puesto?
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

//ADMINISTRADOR:

void anadirProducto(ListaProductos *lp){
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
	scanf("%i", &p.cantidad);
	printf("Precio: \n");
	fflush(stdout);
	fflush(stdin);
	scanf("%lf", &p.precio);
	//Categoria -- enum??
	printf("Categoria: \n");
	fflush(stdout);
	fflush(stdin);
//	gets(p.tipo);
}

Producto buscarProducto(ListaProductos lp){
	Producto p;
	printf("¿Que producto desea modificar?: ");
	fflush(stdout);
	fflush(stdin);
	gets(p.cod_p);
	return  p;
}

//Que se pueda cambiar todo o codigo no? + como preguntar que producto modificar
void modificarProducto(Producto *p){
//	printf("1. Modificar codigo");
	printf("1. Modificar nombre");
	printf("2. Modificar cantidad");
	printf("3. Modificar precio");
	printf("4. Modificar categoria");
	printf("0. Volver");
	fflush(stdout);
	fflush(stdin);
}

void eliminarProducto(Producto p, ListaProductos *lp){

}
/*
----------------YO CREO QUE ASI SERIA MAS FACIL-------------------
void ModificarProducto(Producto *p ){ CON UNA SOLA FUNCION MODIFICAS TODOS LOS ATRIBUTOS

}
 */


//CLIENTE
void devolverProducto(Producto *p){
	printf("Introduce el codigo del producto que quiera devolver: \n");
	fflush(stdout);
	fflush(stdin);
	gets(p->cod_p);
	p->cantidad++;	//Está bien escrito?
	printf("Devolucion finalizada. \n");
}
void visualizarTienda(ListaProductos lp){
	int i;
	for (i = 0; i < lp.numProductos; i++) {
		printf("CÓDIGO DEL PRODUCTO: %s\n", lp.aProductos[i].cod_p);
		printf("NOMBRE: %s\n", lp.aProductos[i].nombre);
		printf("CANTIDAD: %d\n", lp.aProductos[i].cantidad);
		printf("PRECIO: %.2f\n", lp.aProductos[i].precio);
//		printf("CATEGORIA: %d\n", lp.aProductos[i].tipo);	//Coger el codigo de la categoria e imprimir el nombre
	}
//	return 0;
}

void imprimirListaProductos (ListaProductos lp){
	printf("Lista de productos de MueblesDeusto: \n");
	for(int i=0; i<lp.numProductos; i++){
		printf("PRODUCTO %d: \n", i+1);
		fflush(stdout);
		printf("CODIGO: %s\n", lp.aProductos[i].cod_p);
		fflush(stdout);
		printf("NOMBRE: %s\n", lp.aProductos[i].nombre);
		fflush(stdout);
		printf("DESCRIPCION: %s\n", lp.aProductos[i].descripcion);
		fflush(stdout);
		printf("CANTIDAD: %d\n", lp.aProductos[i].cantidad);
		fflush(stdout);
		printf("PRECIO: %lf\n", lp.aProductos[i].precio);
		fflush(stdout);
		printf("CATEGORIA: %d\n", lp.aProductos[i].tipo);
		fflush(stdout);
	}
}

void volcarFicheroAListaProductos(ListaProductos *lp, char *nombreFichero) {
	FILE *pf;
	int tam;
	lp->numProductos = 0;
	pf = fopen(nombreFichero, "r");
	if (pf != (FILE*) NULL) {
		fscanf(pf, "%d", &tam);
		lp->aProductos = (Producto*) malloc(tam * sizeof(Producto));
		while (fscanf(pf, "%s %s %s %d %lf %u",
				lp->aProductos[lp->numProductos].cod_p,
				lp->aProductos[lp->numProductos].nombre,
				lp->aProductos[lp->numProductos].descripcion,
				&(lp->aProductos[lp->numProductos].cantidad),
				&(lp->aProductos[lp->numProductos].precio),
				&(lp->aProductos[lp->numProductos].tipo)) != EOF) {
			lp->numProductos++;
		}
		fclose(pf);
	} else{	//Si el archivo está vacío
		free(lp->aProductos);
		lp->aProductos = NULL;
		return;
	}
	free(lp->aProductos); // Liberar memoria
//	lp->aProductos = NULL; // Asignar un nuevo valor

}




