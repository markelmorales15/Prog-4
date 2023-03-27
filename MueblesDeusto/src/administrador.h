#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_
#include "producto.h"
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
} Admin;

typedef struct{
	Admin *aAdmin;
	int numC;	//Numero de adminstradores en la lista
}ListaAdmin;


void modificarNombre(Producto *p);
void modificarDescripcion(Producto *p);
void modificarCantidad(Producto *p);
void modificarPrecio(Producto *p);

#endif /* ADMINISTRADOR_H_ */
