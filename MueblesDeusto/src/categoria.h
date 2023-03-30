#ifndef CATEGORIA_H_
#define CATEGORIA_H_

typedef enum {
   ELECTRONICA = 0,
   ROPA = 1,
   ALIMENTOS = 2,
   HOGAR = 3
}CategoriaProducto;

void imprimirListaCategorias();
CategoriaProducto buscarNombreCategoria();

#endif
