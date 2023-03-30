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

void anadirProducto(ListaProductos *lp) {
	char get[20] = "";
	Producto p;
	printf("Codigo: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.cod_p);
	printf("Nombre: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.nombre);
	printf("Cantidad: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%d", &p.cantidad);
	printf("Precio: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%lf", &p.precio);
	//Categoria -- enum??
	printf("Categoria: \n"); //Podemos imprimir el enum con un numero asociado a cada uno y en función de su resultado, le pedimos el numero
	//Y le asignamos la categoria
	fflush(stdout);
	fflush(stdin);
//	gets(p.tipo);
}

ListaProductos buscarProducto(ListaProductos lp, CategoriaProducto c) {
	ListaProductos lpCategoria;
	lpCategoria.numProductos = 0;
	lpCategoria.aProductos = (Producto*) malloc(
			lp.numProductos * sizeof(Producto));
	for (int i = 0; i < lp.numProductos; i++) {
		printf("%d %d\n", lp.aProductos[i].tipo, c);
		if (lp.aProductos[i].tipo == c) {
			lpCategoria.aProductos[lpCategoria.numProductos++] =
					lp.aProductos[i];
		}
	}
	return lpCategoria;
}

//Que se pueda cambiar todo o codigo no? + como preguntar que producto modificar
void modificarProducto(Producto *p) {
//	printf("1. Modificar codigo");
	printf("1. Modificar nombre");
	printf("2. Modificar cantidad");
	printf("3. Modificar precio");
	printf("4. Modificar categoria");
	printf("0. Volver");
	fflush(stdout);
	fflush(stdin);
}

void eliminarProducto(Producto p, ListaProductos *lp) {

}
/*
 ----------------YO CREO QUE ASI SERIA MAS FACIL-------------------
 void ModificarProducto(Producto *p ){ CON UNA SOLA FUNCION MODIFICAS TODOS LOS ATRIBUTOS

 }
 */

//CLIENTE
void devolverProducto(ListaProductos *lp, Producto nombreProducto) {
	// Crear un objeto Producto dentro de la función
	Producto p;
	strcpy(p.nombre, nombreProducto.nombre); // Copiar el contenido de nombreProducto en p

	// Buscar el producto en la lista
	int i;
	for (i = 0; i < lp->numProductos; i++) {
		if (strcmp(lp->aProductos[i].nombre, p.nombre) == 0) {
			// Producto encontrado, aumentar cantidad y salir del bucle
			lp->aProductos[i].cantidad++;
			break;
		}
	}
	printf("\nDevolucion finalizada. \n");
	fflush(stdout);
}

void visualizarTienda(ListaProductos lp) {
	char nombres[4][30] = { "ELECTRONICA", "ROPA", "ALIMENTOS", "HOGAR" };
	int i;
	for (i = 0; i < lp.numProductos; i++) {
		printf("CÓDIGO DEL PRODUCTO: %s\n", lp.aProductos[i].cod_p);
		fflush(stdout);
		printf("NOMBRE: %s\n", lp.aProductos[i].nombre);
		fflush(stdout);
		printf("CANTIDAD: %d\n", lp.aProductos[i].cantidad);
		fflush(stdout);
		printf("PRECIO: %.2f\n", lp.aProductos[i].precio);
		fflush(stdout);
		printf("CATEGORIA: %s\n", nombres[lp.aProductos[i].tipo]); //Coger el codigo de la categoria e imprimir el nombre
		fflush(stdout);
	}
}

void imprimirListaProductos(ListaProductos lp) {
	printf("\nLista de productos de MueblesDeusto: \n");
	fflush(stdout);
	for (int i = 0; i < lp.numProductos; i++) {
		printf("[PRODUCTO %d: ", i + 1);
		fflush(stdout);
		printf("CODIGO: %s, ", lp.aProductos[i].cod_p);
		fflush(stdout);
		printf("NOMBRE: %s, ", lp.aProductos[i].nombre);
		fflush(stdout);
		printf("DESCRIPCION: %s, ", lp.aProductos[i].descripcion);
		fflush(stdout);
		printf("CANTIDAD: %d, ", lp.aProductos[i].cantidad);
		fflush(stdout);
		printf("PRECIO: %.2f, ", lp.aProductos[i].precio);
		fflush(stdout);
		printf("CATEGORIA: %d]\n", lp.aProductos[i].tipo);
		fflush(stdout);
	}
}

void volcarFicheroAListaProductos(ListaProductos *lp, char *nombreFichero) {
	FILE *pf;
	int tam;
	int cat;
	lp->numProductos = 0;
	pf = fopen(nombreFichero, "r");
	if (pf != (FILE*) NULL) {
		fscanf(pf, "%d", &tam);
		printf("TAM: %d\n", tam);
		fflush(stdout);
		lp->aProductos = (Producto*) malloc(tam * sizeof(Producto));
		while (fscanf(pf, "%s%s%s%d%lf%d",
				lp->aProductos[lp->numProductos].cod_p,
				lp->aProductos[lp->numProductos].nombre,
				lp->aProductos[lp->numProductos].descripcion,
				&(lp->aProductos[lp->numProductos].cantidad),
				&(lp->aProductos[lp->numProductos].precio), &cat) != EOF) {

			lp->aProductos[lp->numProductos].tipo = (CategoriaProducto) cat;
			lp->numProductos++;
		}
		fclose(pf);
	} else {	//Si el archivo está vacío
		lp->aProductos = NULL;
		return;
	}

}

Producto nombreProductoBorrar() {
	char get[20] = "";
	Producto p;
	printf(
			"\n¿Qué producto desea eliminar? (introduzca el nombre del producto): ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.nombre);
	return p;
}

Producto nombreProductoDevolver() {
	char get[20] = "";
	Producto p;
	printf(
			"\n¿Qué producto desea devolver? (introduzca el nombre del producto): ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.nombre);
	return p;
}

Producto codigoProductoBorrar() {
	char get[20] = "";
	Producto p;
	printf(
			"\n¿Qué producto desea eliminar? (introduzca el código del producto): ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.cod_p);
	return p;
}

int nuevaCantidadProducto() {
	int nuevaCantidad;
	char get[1000] = "";
	printf("Introduce la nueva cantidad del producto: ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 1000, stdin);
	sscanf(get, "%d", &nuevaCantidad);
	return nuevaCantidad;
}

Producto codigoProductoModificar() {
	char get[20] = "";
	Producto p;
	printf(
			"\n¿Qué producto desea modificar? (introduzca el código del producto): ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.cod_p);
	return p;
}

Producto anadirProductoBD() {
	char get[20] = "";
	Producto p;
	printf("Codigo: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.cod_p);
	printf("Nombre: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.nombre);
	printf("Nombre: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%s", p.descripcion);
	printf("Cantidad: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%d", &p.cantidad);
	printf("Precio: \n");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%lf", &p.precio);
	//Categoria -- enum??
	printf("Categoria: \n"); //Podemos imprimir el enum con un numero asociado a cada uno y en función de su resultado, le pedimos el numero
	//Y le asignamos la categoria
	fgets(get, 20, stdin);
	sscanf(get, "%lf", &p.tipo);
//	gets(p.tipo);
	return p;
}
