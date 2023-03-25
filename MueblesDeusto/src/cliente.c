#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "funciones.h"

Cliente registro() {
	Cliente c;
	printf("\nIntroduce tu DNI: ");
	fflush(stdout);
	fflush(stdin);
	gets(c.dni);
	printf("Introduce el nombre de usuario: ");
	fflush(stdout);
	fflush(stdin);
	gets(c.usuario);
	printf("Introduce la contrasena: ");
	fflush(stdout);
	fflush(stdin);
	gets(c.contrasena);
	//Meter el cliente en la lista de clientes
//	menuCliente();
	return c;

}

//Llamamos a esta función cada vez que vayamos a registrar a un nuevo cliente
void anadirClientesALista(ListaClientes *lc, Cliente nuevoCliente){
	lc->aClientes = realloc(lc->aClientes, sizeof(Cliente) * (lc->numC+1));
	lc->aClientes[lc->numC] = nuevoCliente;
	lc->numC++;
}

void imprimirListaClientes (ListaClientes lc){
//	int i;
	printf("Lista de clientes de MueblesDeusto: \n");
	for(int i=0; i<lc.numC; i++){
		printf("Cliente %d: \n", i+1);
		printf("DNI: %s\n", lc.aClientes[i].dni);
		printf("USUARIO: %s\n", lc.aClientes[i].usuario);
		printf("CONTRASENA: %s\n", lc.aClientes[i].contrasena);

	}
}
