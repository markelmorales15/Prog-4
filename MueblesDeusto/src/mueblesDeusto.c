#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "menus.h"
#include "producto.h"
#include "carrito.h"

int main(void) {

	/*
	 * DUDAS:
	 * 	- Fichero Productos.txt no se lee correctamente
	 * 	- El cuarto método del menú cliente (4. Buscar un producto) no funciona
	 */

	int opcion = 10, opcion2 = 10, opcion3 = 10, opcion4 = 10;
	int i;
	int clienteExiste = 0, adminExiste = 0;
	ListaClientes lc;
	ListaClientes admin;
	lc.numC = 0;
	ListaProductos lp1;
	lp1.numProductos = 0;

	volcarFicheroAListaClientes(&lc, "Clientes.txt");
	volcarFicheroAListaClientes(&admin, "Administradores.txt");
	volcarFicheroAListaProductos(&lp1, "Productos.txt");
	imprimirListaProductos(lp1);
//	imprimirListaClientes(admin);
//	imprimirListaClientes(lc);

//	Producto* p = (Producto) malloc (1*sizeof(Producto));
//	p.cantidad = 1;
//	p.cod_p = "1";
//	p.descripcion = "p";
//	p.nombre = "prubea";
//	p.precio = 2.0;
//	p.tipo = "ROPA";
//
//	Carrito c;
//	c.numProductos = 0;
//	aniadirProductoCarrito(&c, p);
//	c.dni = "111A";

	Cliente cliente;
	strcpy(cliente.dni, "12345678A");
	strcpy(cliente.usuario, "usuario1");
	strcpy(cliente.contrasena, "contrasena1");

	Producto nombreProducto;
	CategoriaProducto categoria;
	ListaProductos productosCategoria;

	Producto *producto = malloc(sizeof(Producto));
	strcpy(producto->cod_p, "P1234");
	strcpy(producto->nombre, "Leche");
	strcpy(producto->descripcion, "Leche desnatada");
	producto->cantidad = 1;
	producto->precio = 0.80;
	producto->tipo = ELECTRONICA;

	Producto *producto2 = malloc(sizeof(Producto));
	strcpy(producto2->cod_p, "producto2");
	strcpy(producto2->nombre, "producto2");
	strcpy(producto2->descripcion, "producto2");
	producto2->cantidad = 2;
	producto2->precio = 5;
	producto2->tipo = ROPA;

	ListaProductos *lp = malloc(sizeof(ListaProductos));
	lp->aProductos = malloc(2 * sizeof(Producto));
	lp->numProductos = 2;
	lp->aProductos[0] = *producto;
	lp->aProductos[1] = *producto2;

	// Crear un nuevo carrito
	Carrito *carrito = malloc(sizeof(Carrito));
	carrito->aProductos = malloc(2 * sizeof(Producto)); // Aumentar el tamaño del array a 2
	carrito->aProductos[0] = *producto;
	carrito->aProductos[1] = *producto2; // Añadir el segundo producto
	carrito->numProductos = 2; // Actualizar el número total de productos
	strcpy(carrito->dni, cliente.dni);
	carrito->importeTotal = producto->precio + producto2->precio; // Calcular el importe total del carrito
//
//	imprimirCarrito(*carrito);
//	imprimirTicket(*carrito, "PruebaTicket.txt");
//	eliminarProductoCarrito(carrito, *producto);
//	imprimirCarrito(*carrito);
////	comprarCarrito(carrito);
////	imprimirCarrito(*carrito);
//
//	free(producto);
////	free(producto2);
//	free(carrito->aProductos);
//	free(carrito);

	//Escribir admins en un fichero y volcarlos. Volcar del array al fichero los clientes. y al revés.
	Cliente nuevoCliente;
	Cliente inicio;
	do {
		//Abrimos el menú de inicio
		opcion = menuInicio();
		switch (opcion) {
		case 1:	//Registrase
			nuevoCliente = registro();//Si el usuario no existe ya en la lista de clientes
			//Comprobamos si el usuario ya está registrado o no
			for (i = 0; i < lc.numC; i++) {
				if (strcmp(nuevoCliente.dni, lc.aClientes[i].dni) == 0) {//Compramos el dni del cliente nuevo con el resto de nuestros clientes
					clienteExiste = 1;
					break;
				}
			}
			//Si el cliente ya está registrado (ya existe en la lista de clientes):
			if (clienteExiste) {
				printf("\nEl cliente ya existe en la lista. \n");
				fflush(stdout);
				//Si el cliente no existe en la lista:
			} else {
				printf("\nUsuario realizado con exito. \n");
				//Añadimos el cliente a la lista
				anadirClientesALista(&lc, nuevoCliente);
				volcarListaClientesAFichero(&lc, "Clientes.txt");
				fflush(stdout);
				//Llamamos al menú cliente:

			}
			//Si el registro es correcto el usuario tiene que iniciar sesión.S

			break;
		case 2:	//Iniciar sesión
				//Tenemos que recorrer las dos listas: admin y clientes
				//Si el admin ya se conoce, se abre el menú de admin y si no el de cliente
			inicio = inicioSesion();
			//Comprobamos si el usuario ya está registrado o no
			for (i = 0; i < lc.numC; i++) {
				if ((strcmp(inicio.usuario, lc.aClientes[i].usuario) == 0)
						&& (strcmp(inicio.contrasena,
								lc.aClientes[i].contrasena) == 0)) {//Compramos el dni del cliente nuevo con el resto de nuestros clientes
					clienteExiste = 1;
					break;
				}
			}
			if (clienteExiste) {
				printf("\n¡Bienvenido a MueblesDeusto! \n");
				fflush(stdout);
				do {
					opcion3 = menuCliente();
					switch (opcion3) {
					case 1:
						opcion4 = mostrarCarrito(*carrito);	//Mirar que cuando salga de una opción no vuelva al menu de inicio, tiene que volver al del cliente
						break;
					case 2:
						//Imprimimos el carrito para comprobar que se ha borrado o al usuario no le interesa?
						imprimirCarrito(*carrito);
						imprimirListaProductos(*lp);
						nombreProducto = nombreProductoDevolver();
						devolverProducto(lp, nombreProducto);
						imprimirCarrito(*carrito);
						imprimirListaProductos(*lp);
						break;
					case 3:
						imprimirListaProductos(*lp);
						break;
					case 4:
						imprimirListaCategorias();
						buscarProducto(*lp, ROPA);

						printf(
								"Introduce una categoria (1 - ELECTRONICA, 2 - ROPA, 3 - ALIMENTOS): ");
						scanf("%d", &categoria);

						// Buscar los productos de la categoría ingresada
						productosCategoria = buscarProducto(*lp, categoria);
						imprimirListaProductos(productosCategoria);
						break;
					case 0:	//Salir
						printf("\nAgur! \n\n");
						fflush(stdout);
						break;
					}

				} while (opcion3 != 0);
				//Si el cliente no existe en la lista:
			} else {

				for (i = 0; i < admin.numC; i++) {
					if ((strcmp(inicio.usuario, admin.aClientes[i].usuario) == 0)
							&& (strcmp(inicio.contrasena,
									admin.aClientes[i].contrasena) == 0)) {	//Compramos el dni del cliente nuevo con el resto de nuestros clientes
						adminExiste = 1;
						break;
					}
				}
				if (adminExiste) {
					printf("\n¡Bienvenido a MueblesDeusto! \n");
					fflush(stdout);
					opcion3 = menuAdmin();
				} else {
					printf("\nAntes debe registrarse \n");
					fflush(stdout);
				}
			}
			break;
		case 0:
			printf("\nAgur! \n");
			fflush(stdout);
			break;
		default:
			printf("Error! \n");
			fflush(stdout);
			break;
		}
	} while (opcion != 0);

	liberarMemoria(&lc);
	return 0;

}
