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

ListaProductos buscarProducto(ListaProductos lp, CategoriaProducto c) {
    ListaProductos lpCategoria;
    lpCategoria.numProductos = 0;
    for (int i = 0; i < lp.numProductos; i++) {
        if (lp.aProductos[i].tipo == c) {
            lpCategoria.aProductos[lpCategoria.numProductos++] = lp.aProductos[i];
        }
    }
    return lpCategoria;
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
void devolverProducto(ListaProductos *lp, Producto nombreProducto){
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
		printf("PRECIO: %.2f\n", lp.aProductos[i].precio);
		fflush(stdout);
		printf("CATEGORIA: %d\n", lp.aProductos[i].tipo);
		fflush(stdout);
	}
}

void volcarFicheroAListaProductos(ListaProductos *lp, char *nombreFichero) {
	FILE *pf;
	int tam;
	char cat[200];
	lp->numProductos = 0;
	pf = fopen(nombreFichero, "r");
	if (pf != (FILE*) NULL) {
		fscanf(pf, "%d", &tam);
		printf("TAM: %d\n",tam);fflush(stdout);
		lp->aProductos = (Producto*) malloc(tam * sizeof(Producto));
		while (fscanf(pf, "%s %s %s %d %f %s",
				lp->aProductos[lp->numProductos].cod_p,
				lp->aProductos[lp->numProductos].nombre,
				lp->aProductos[lp->numProductos].descripcion,
				&(lp->aProductos[lp->numProductos].cantidad),
				&(lp->aProductos[lp->numProductos].precio),
				cat) != EOF) {
			lp->numProductos++;
		}
		fclose(pf);
	} else{	//Si el archivo está vacío
		lp->aProductos = NULL;
		return;
	}

}

Producto nombreProductoBorrar(){
    Producto p;
    printf("¿Qué producto desea eliminar?: ");
    fflush(stdout);
    fflush(stdin);
    fgets(p.nombre, sizeof(p.nombre), stdin);
    p.nombre[strcspn(p.nombre, "\n")] = '\0';  // Elimina el salto de línea final de fgets
    return p;
}

Producto nombreProductoDevolver(){
    Producto p;
    printf("¿Qué producto desea devolver?: ");
    fflush(stdout);
    fflush(stdin);
    fgets(p.nombre, sizeof(p.nombre), stdin);
    p.nombre[strcspn(p.nombre, "\n")] = '\0';  // Elimina el salto de línea final de fgets
    return p;
}





