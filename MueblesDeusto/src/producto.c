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
		printf("CATEGORIA: %s]\n",
				obtenerNombreCategoria(lp.aProductos[i].tipo));
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
	printf("Descripcion: \n");
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
	fflush(stdout);
	fflush(stdin);
	fgets(get, 20, stdin);
	sscanf(get, "%d", &p.tipo);

//	gets(p.tipo);
	return p;
}
int buscarProductoCategoria() {
	int opcion;

	return opcion;
}

//int copiarProductoComprar(ListaProductos lp, char *codigoBuscado, Producto *productoEncontrado){
//    int i;
//    for (i = 0; i < lp.numProductos; i++) {
//        if (strcmp(codigoBuscado, lp.aProductos[i].cod_p) == 0) {
//            // Copia los valores del producto encontrado en el puntero productoEncontrado
//            strcpy(productoEncontrado->cod_p, lp.aProductos[i].cod_p);
//            strcpy(productoEncontrado->nombre, lp.aProductos[i].nombre);
//            strcpy(productoEncontrado->descripcion, lp.aProductos[i].descripcion);
//            productoEncontrado->cantidad = lp.aProductos[i].cantidad;
//            productoEncontrado->precio = lp.aProductos[i].precio;
//            productoEncontrado->tipo = lp.aProductos[i].tipo;
//            return 1; // Devuelve 1 para indicar que se ha encontrado el producto buscado
//        }
//    }
//    // Si no se encuentra el producto, se muestra un mensaje de error
//    printf("No existe un producto con ese código. \n");
//    fflush(stdout);
//    return 0; // Devuelve 0 para indicar que no se ha encontrado el producto buscado
//}

Producto buscarProd(ListaProductos lista, char *codigo) {
	Producto p;
	for (int i = 0; i < lista.numProductos; i++) {
		if (strcmp(lista.aProductos[i].cod_p, codigo) == 0) {
//			return lista.aProductos[i];
			strcpy(p.cod_p, lista.aProductos[i].cod_p);
			strcpy(p.nombre, lista.aProductos[i].nombre);
			strcpy(p.descripcion, lista.aProductos[i].descripcion);
			p.cantidad = lista.aProductos[i].cantidad;
			p.precio = lista.aProductos[i].precio;
			p.tipo = lista.aProductos[i].tipo;
		}
	}
	return p;
}

//ListaProductos agregarProductoLista(ListaProductos lista, Producto p) {
//    // Reallocar la memoria para aProductos
//    lista.aProductos = realloc(lista.aProductos, (lista.numProductos+1)*sizeof(Producto));
//    if (lista.aProductos == NULL) {
//        fprintf(stderr, "Error al reallocar memoria para lista.aProductos\n");
//        exit(1);
//    }
//
//    // Agregar el nuevo producto al final de la lista
//    lista.aProductos[lista.numProductos] = p;
//    lista.numProductos++;
//
//    return lista;
//}
//
//
//
//void borrarProductoFichero(char *codigo, char *nombreFichero, ListaProductos *lista) {
//    FILE *f = fopen(nombreFichero, "r");
//    if (f == NULL) {
//        printf("Error abriendo el archivo\n");
//        return;
//    }
//
//    int numProductos;
//    fscanf(f, "%d", &numProductos);
//
//    // Búsqueda del producto en el archivo
//    int encontrado = 0;
//    for (int i = 0; i < numProductos; i++) {
//        Producto p;
//        fscanf(f, "%s %s %s %d %lf %d", p.cod_p, p.nombre, p.descripcion, &p.cantidad, &p.precio, &p.tipo);
//        if (strcmp(p.cod_p, codigo) == 0) {
//            encontrado = 1;
//        } else {
//        	agregarProductoLista(p, lista);
//        }
//    }
//
//    fclose(f);
//
//    if (!encontrado) {
//        printf("No se ha encontrado el producto con el código %s\n", codigo);
//        return;
//    }
//
//    // Volcar la lista actualizada al archivo
//    f = fopen(nombreFichero, "w");
//    if (f == NULL) {
//        printf("Error abriendo el archivo\n");
//        return;
//    }
//
//    fprintf(f, "%d\n", lista->numProductos);
//    for (int i = 0; i < lista->numProductos; i++) {
//        Producto p = lista->aProductos[i];
//        fprintf(f, "%s %s %s %d %lf %d\n", p.cod_p, p.nombre, p.descripcion, p.cantidad, p.precio, p.tipo);
//    }
//
//    fclose(f);
//
//    printf("El producto con el código %s ha sido eliminado del archivo %s\n", codigo, nombreFichero);
//}
//
