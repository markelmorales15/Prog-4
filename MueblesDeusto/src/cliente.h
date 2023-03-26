#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Producto.h"
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
} Cliente;


typedef struct{
	Cliente *aClientes;
	int numC;	//numero de clientes
}ListaClientes;




Cliente registro();
void anadirClientesALista(ListaClientes *lc, Cliente nuevoCliente);
void imprimirListaClientes (ListaClientes lc);
void aniadirProductoCarrito();

#endif /* CLIENTE_H_ */
