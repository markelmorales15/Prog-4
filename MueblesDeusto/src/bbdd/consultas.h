#ifndef BBDD_CONSULTAS_H_
#define BBDD_CONSULTAS_H_

#include "sqlite3.h"
#include "../administrador.h"
#include "../carrito.h"
#include "../categoria.h"
#include "../cliente.h"
#include "../producto.h"

void insertarProductoBD(sqlite3* db, Producto p);
void cargarProductos(sqlite3* db, Almacen* al);
void modificarProductoBD(sqlite3* db, Producto p);
void eliminarProductoBD(sqlite3* db, Producto p);





#endif
