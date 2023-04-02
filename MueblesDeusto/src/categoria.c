#include <stdio.h>
#include "categoria.h"

int imprimirListaCategorias() {
	int categoria;
	char get[2] ="";
	printf("Introduce una categoria (1 - MESAS, 2 - SILLAS, 3 - SOFAS): ");
	fflush(stdout);
	fflush(stdin);
	fgets(get, 2, stdin);
	sscanf(get, "%d", &categoria);
	return categoria;
}

