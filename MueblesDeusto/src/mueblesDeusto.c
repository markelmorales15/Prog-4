#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void) {

	int opcion;

	printf("Pantalla inicio");
	do{
		opcion = menu();


		switch (opcion) {
		case 1:
			//Función registro
			break;
		case 2:
			//Función inicio sesión
			break;
		case 0:
			printf ("Agur! \n"); fflush(stdout);
			break;
		default:
			printf("Error! \n"); fflush(stdout);
			break;
		}
	} while (opcion != 0);



	return 0;

}
