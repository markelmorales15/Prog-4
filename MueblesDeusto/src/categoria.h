#ifndef CATEGORIA_H_
#define CATEGORIA_H_

typedef enum {
   ELECTRONICA,
   ROPA,
   ALIMENTOS,
   HOGAR
}CategoriaProducto;

void imprimirListaCategorias();
CategoriaProducto buscarNombreCategoria();

#endif
