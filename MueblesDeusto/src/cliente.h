#ifndef CLIENTE_H_
#define CLIENTE_H_

/*
 * Pueden ser tanto los administradores como los usuarios
 *
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


Cliente registro();	//Siempre va a ser un usuario, los administradores los metemos a mano en el sistema
void anadirClientesALista(ListaClientes *lc, Cliente nuevoCliente);
void imprimirListaClientes (ListaClientes lc);
void volcarFicheroAListaClientes(ListaClientes *lc, char *nombreFichero);
void volcarListaClientesAFichero(ListaClientes *lc, char *nombreFichero);
void liberarMemoria(ListaClientes *lc);

#endif /* CLIENTE_H_ */
