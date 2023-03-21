#ifndef CLIENTE_H_
#define CLIENTE_H_

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


#endif /* CLIENTE_H_ */
