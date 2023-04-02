#include "consultas.h"
#include <stdio.h>
#include <string.h>

int abrirBD(sqlite3 **db) {
    int rc = sqlite3_open("MueblesDeusto.db", db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n",
                sqlite3_errmsg(*db));
        sqlite3_close(*db);
        return rc;
    }
    return SQLITE_OK;
}


int crearTablaProducto(char *nombreBaseDatos) {
	sqlite3 *db;
	char *errMsg = NULL;
	int rc;

	// Abrir la base de datos
	rc = sqlite3_open(nombreBaseDatos, &db);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "Error al abrir la base de datos: %s\n",
				sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}

	// Crear la tabla producto
	char *sql =
			"CREATE TABLE if not exists producto (cod_p VARCHAR(10) PRIMARY KEY, nombre VARCHAR(20) NOT NULL, descripcion VARCHAR(20), cantidad INT NOT NULL, precio DOUBLE NOT NULL, tipo VARCHAR(20) NOT NULL);";
	rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "Error al crear la tabla producto: %s\n", errMsg);
		sqlite3_free(errMsg);
		sqlite3_close(db);
		return 1;
	}

	// Cerrar la base de datos
	sqlite3_close(db);
	return 0;
}

//void insertarProductoBD(sqlite3 *db, Producto p) {
//	char sql[100];
//	sprintf(sql, "insert into Producto values(1,'%s','A','A@A.COM')", dni);
//}

int insertarProductoBD(sqlite3 *db, Producto p) {
    char *errMsg = NULL;
    char sql[300];

    // Crear la sentencia SQL para insertar el producto
    sprintf(sql, "INSERT INTO producto (cod_p, nombre, descripcion, cantidad, precio, tipo) VALUES ('%s', '%s', '%s', %d, %f, '%d')",
            p.cod_p, p.nombre, p.descripcion, p.cantidad, p.precio, p.tipo);

    // Ejecutar la sentencia SQL
    int rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al insertar producto: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 1;
    }

    return 0;
}

int mostrarProductosBD(sqlite3* db) {
    char *sql = "SELECT * FROM producto;";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        printf("Error preparando la consulta: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    printf("%-10s %-20s %-20s %-8d %-10.2f %-20s\n", "cod_p", "nombre", "descripcion", "cantidad", "precio", "tipo");
    printf("------------------------------------------------------------------------------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        char *cod_p = (char*) sqlite3_column_text(stmt, 0);
        char *nombre = (char*) sqlite3_column_text(stmt, 1);
        char *descripcion = (char*) sqlite3_column_text(stmt, 2);
        int cantidad = sqlite3_column_int(stmt, 3);
        double precio = sqlite3_column_double(stmt, 4);
        char *tipo = (char*) sqlite3_column_text(stmt, 5);

        printf("%-10s %-20s %-20s %-8d %-10.2f %-20s\n", cod_p, nombre, descripcion, cantidad, precio, tipo);
    }

    sqlite3_finalize(stmt);
    return 0;
}

int modificarCantidadProductoBD(sqlite3 *db, char *cod_p, int nueva_cantidad) {
    char sql[100];
    char *errMsg = NULL;
    int rc;

    // Verificar si el producto existe en la base de datos
    sprintf(sql, "SELECT * FROM producto WHERE cod_p = '%s'", cod_p);
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc == SQLITE_DONE) {
        fprintf(stderr, "El producto con código %s no existe en la base de datos.\n", cod_p);
        sqlite3_free(errMsg);
        return 1;
    }

    // Crear la sentencia SQL para actualizar la cantidad del producto
    sprintf(sql, "UPDATE producto SET cantidad = %d WHERE cod_p = '%s';",
            nueva_cantidad, cod_p);

    // Ejecutar la sentencia SQL
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al modificar la cantidad del producto: %s\n",
                errMsg);
        sqlite3_free(errMsg);
        return 1;
    }

    return 0;
}

int borrarProductoBD(sqlite3 *db, char *cod_p) {
    char *errMsg = NULL;
    int rc;

    // Crear la sentencia SQL para borrar un producto
    char sql[100];
    sprintf(sql, "DELETE FROM producto WHERE cod_p='%s'", cod_p);

    // Ejecutar la sentencia SQL
    rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al borrar el producto %s: %s\n", cod_p, errMsg);
        sqlite3_free(errMsg);
        return 1;
    }

    return 0;
}


int obtenerProductosBD(sqlite3* db, ListaProductos* productosBD) {
    char* errMsg = NULL;
    int rc, numRows;
    sqlite3_stmt* stmt;

    // Crear la sentencia SQL para obtener todos los productos
    const char* sql = "SELECT * FROM producto";

    // Preparar la sentencia SQL
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparando la consulta: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 1;
    }

    // Contar el número de filas que devuelve la consulta
    numRows = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        numRows++;
    }

    // Volver a preparar la sentencia SQL
    sqlite3_reset(stmt);

    // Crear el array de productos
    productosBD->aProductos = (Producto*) malloc(numRows * sizeof(Producto));
    productosBD->numProductos = numRows;

    // Volcar los datos de la consulta a la estructura ListaProductos
    int i = 0;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Producto* pProducto = &(productosBD->aProductos[i]);
        strcpy(pProducto->cod_p, (char*)sqlite3_column_text(stmt, 0));
        strcpy(pProducto->nombre, (char*)sqlite3_column_text(stmt, 1));
        strcpy(pProducto->descripcion, (char*)sqlite3_column_text(stmt, 2));
        pProducto->cantidad = sqlite3_column_int(stmt, 3);
        pProducto->precio = sqlite3_column_double(stmt, 4);
        pProducto->tipo = sqlite3_column_int(stmt, 5);
        i++;
    }

    sqlite3_finalize(stmt);
    return 0;
}

//int volcarListaProductosABD(sqlite3* db, ListaProductos* lista) {
//    char *errMsg = NULL;
//    int rc;
//
//    // Iniciar transacción
//    rc = sqlite3_exec(db, "BEGIN TRANSACTION", NULL, 0, &errMsg);
//    if (rc != SQLITE_OK) {
//        fprintf(stderr, "Error al iniciar la transacción: %s\n", errMsg);
//        sqlite3_free(errMsg);
//        return 1;
//    }
//
//    // Borrar todos los productos de la tabla
//    rc = sqlite3_exec(db, "DELETE FROM producto", NULL, 0, &errMsg);
//    if (rc != SQLITE_OK) {
//        fprintf(stderr, "Error al borrar los productos: %s\n", errMsg);
//        sqlite3_free(errMsg);
//        return 1;
//    }
//
//    // Insertar cada producto de la lista en la tabla
//    for (int i = 0; i < lista->numProductos; i++) {
//        Producto p = lista->aProductos[i];
//
//        // Crear la sentencia SQL para insertar un producto
//        char sql[100];
//        sprintf(sql, "INSERT INTO producto (cod_p, nombre, descripcion, cantidad, precio, tipo) "
//                     "VALUES ('%s', '%s', '%s', %d, %f, %d)",
//                p.cod_p, p.nombre, p.descripcion, p.cantidad, p.precio, p.tipo);
//
//        // Ejecutar la sentencia SQL
//        rc = sqlite3_exec(db, sql, NULL, 0, &errMsg);
//        if (rc != SQLITE_OK) {
//            fprintf(stderr, "Error al insertar el producto %s: %s\n", p.cod_p, errMsg);
//            sqlite3_free(errMsg);
//            sqlite3_exec(db, "ROLLBACK", NULL, 0, &errMsg);  // Deshacer transacción
//            return 1;
//        }
//    }
//
//    // Finalizar transacción
//    rc = sqlite3_exec(db, "COMMIT", NULL, 0, &errMsg);
//    if (rc != SQLITE_OK) {
//        fprintf(stderr, "Error al finalizar la transacción: %s\n", errMsg);
//        sqlite3_free(errMsg);
//        return 1;
//    }
//
//    return 0;
//}
//
