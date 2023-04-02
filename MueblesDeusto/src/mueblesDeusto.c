#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "menus.h"
#include "producto.h"
#include "carrito.h"
#include "bbdd/consultas.h"

int main(void) {

	/*
	 * DUDAS:
	 * 	1. - Fichero Productos.txt no se lee correctamente
	 * 	2. - El cuarto método del menú cliente (4. Buscar un producto) no funciona
	 * 	3. - El método de borrar carrito (en carrito.c) no nos funciona bien. Si le damos a borrar y luego le damos a eliminar producto,
	 * 		nos vuelve a salir la lista de productos y no deberia, deber	ía de quedarse vacía.
	 * 	4. - Cuando en el main llamamos al método devolver un producto, imprimimos el carrito para comprobar que se ha borrado o al usuario no le interesa?
	 */

	// Abrir la base de datos
	sqlite3 *db;
	int rc = sqlite3_open("MueblesDeusto.db", &db);
	if (rc != SQLITE_OK) {
		printf("Error abriendo la base de datos: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}

	// Crear la tabla producto si no existe
	crearTablaProducto("MueblesDeusto.db");

	ListaProductos productosFichero;
	ListaProductos productosBD;
	volcarFicheroAListaProductos(&productosFichero, "Productos.txt");
//	sqlite3_open("MueblesDeusto.db", &db);
//	volcarProductosBDALista(db, &productosBD);
	volcarListaProductosABD(db, &productosFichero);
//	sqlite3_close(db);
	imprimirListaProductos(productosBD);
//	mostrarProductosBD(db);

//	obtenerProductosBD(db, &productosBD);

	// Insertar un nuevo producto en la tabla
	Producto nuevoProducto;
	strcpy(nuevoProducto.cod_p, "P002");
	strcpy(nuevoProducto.nombre, "Silla");
	strcpy(nuevoProducto.descripcion, "Silla de madera");
	nuevoProducto.cantidad = 10;
	nuevoProducto.precio = 50.0;
	nuevoProducto.tipo = 0;

	// Modificar cantidad del producto con código P001 a 20

//	borrarProductoBD(db, nuevoProducto.cod_p);
//	modificarCantidadProductoBD(db, nuevoProducto.cod_p, 123);

// Cerrar la base de datos
	sqlite3_close(db);

	int opcion = 10, opcion2 = 10, opcion3 = 10, opcion4 = 10;
	int i, clienteExiste = 0, adminExiste = 0, cat, nuevaCantidad = 0;
//	char get[20] = "";
	ListaClientes lc;
	ListaClientes admin;
	lc.numC = 0;
	ListaProductos lp1;
//	ListaProductos lpb;
//	char seguro[3] = "";

//	Producto *producto = malloc(sizeof(Prosducto));
//		strcpy(producto->cod_p, "P1234");
//		strcpy(producto->nombre, "Leche");
//		strcpy(producto->descripcion, "Leche desnatada");
//		producto->cantidad = 1;
//		producto->precio = 0.80;
//		producto->tipo = ELECTRONICA;

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
//	CategoriaProducto categoria;
	ListaProductos productosCategoria;

	Producto *producto = malloc(sizeof(Producto));
	strcpy(producto->cod_p, "P1234");
	strcpy(producto->nombre, "Leche");
	strcpy(producto->descripcion, "Leche desnatada");
	producto->cantidad = 1;
	producto->precio = 0.80;
	producto->tipo = MESAS;

	Producto *producto2 = malloc(sizeof(Producto));
	strcpy(producto2->cod_p, "producto2");
	strcpy(producto2->nombre, "producto2");
	strcpy(producto2->descripcion, "producto2");
	producto2->cantidad = 2;
	producto2->precio = 5;
	producto2->tipo = SILLAS;

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
//	inicio.contrasena = "";
//	inicio.contrasena = "";
//	inicio.dni = "";
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
				printf("\nUsuario registrado con exito. \n");
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
//					printf(inicio.usuario);
//					fflush(stdout);
					clienteExiste = 1;
					break;
				}
			}
			if (clienteExiste) {
				printf("\n¡Bienvenido a MueblesDeusto! \n");
				fflush(stdout);
				strcpy(inicio.dni, buscarDniUsuario(lc, inicio.usuario));

				do {
					opcion2 = menuCliente();
					Carrito *carritocliente = malloc(sizeof(Carrito));
					carritocliente->aProductos = NULL;
					carritocliente->numProductos = 0; // Actualizar el número total de productos
					strcpy(carritocliente->dni, inicio.dni);
					carritocliente->importeTotal = 0;
					switch (opcion2) {
					case 1:
						opcion3 = mostrarCarrito(*carrito);	//Mirar que cuando salga de una opción no vuelva al menu de inicio, tiene que volver al del cliente
						break;
					case 2:
						//Imprimimos el carrito para comprobar que se ha borrado o al usuario no le interesa?
						imprimirCarrito(*carritocliente);
						imprimirListaProductos(*lp);
						nombreProducto = nombreProductoDevolver();
						devolverProducto(lp, nombreProducto);
						imprimirCarrito(*carritocliente);
						imprimirListaProductos(*lp);
						break;
					case 3:
						imprimirListaProductos(*lp);
						break;
					case 4:
						cat = imprimirListaCategorias();
						productosCategoria = buscarProducto(*lp, cat);
						imprimirListaProductos(productosCategoria);
						opcion4 = menuBuscar(*carritocliente, lp1);
						break;
					case 0:	//Salir
						printf("\nAgur! \n\n");
						fflush(stdout);
						break;
					}

				} while (opcion2 != 0);
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
					do {
						opcion2 = menuAdmin();
						switch (opcion2) {
						case 1:	//Añadir producto
							//Método para pedir el producto
							nuevoProducto = anadirProductoBD();
							sqlite3_open("MueblesDeusto.db", &db);
							insertarProductoBD(db, nuevoProducto);
							sqlite3_close(db);
							break;
						case 2:	//Modificar producto -- falta arreglarlo
							imprimirListaProductos(lp1);
							nombreProducto = codigoProductoModificar();
							nuevaCantidad = nuevaCantidadProducto();
							sqlite3_open("MueblesDeusto.db", &db);
							modificarCantidadProductoBD(db,
									nombreProducto.cod_p, nuevaCantidad);
							sqlite3_close(db);
							break;
						case 3:
							imprimirListaProductos(lp1);
//							printf(
//									"\nEstás seguro de que deseas modificar un producto?(s/n): \n");
//							fflush(stdout);
//							fgets(get, 3, stdin);
//							sscanf(get, "%s", &seguro);
//							printf(seguro);
//							fflush(stdout);
//							if (strcmp(seguro, "s")) {
							nombreProducto = codigoProductoBorrar();
							sqlite3_open("MueblesDeusto.db", &db);

							borrarProductoBD(db, nombreProducto.cod_p);
							sqlite3_close(db);
//							borrarProductoFichero(nombreProducto.cod_p,"Productos.txt", &lp1);
//							}
							break;
						case 4: //mostrar productos -- falta arreglar
							sqlite3_open("MueblesDeusto.db", &db);
							mostrarProductosBD(db);
							sqlite3_close(db);
							break;
						case 5:
							sqlite3_open("MueblesDeusto.db", &db);
							printf("\nProducto más caro de la tienda: \n");
							fflush(stdout);
							buscarProductoCaro(db);
							sqlite3_close(db);

							sqlite3_open("MueblesDeusto.db", &db);
							printf(
									"\nEl número de productos en cada categoria es el siguiente: \n");
							fflush(stdout);
							numeroProductosCategoria(db);
							sqlite3_close(db);

							sqlite3_open("MueblesDeusto.db", &db);
							printf("\nEl producto con mayor cantidad en la tienda es el siguiente: \n");
							fflush(stdout);
							productoMayorCantidad(db);
							sqlite3_close(db);

							break;
						case 0:	//Salir
							printf("\nAgur! \n\n");
							fflush(stdout);
							break;
						}

					} while (opcion2 != 0);

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
