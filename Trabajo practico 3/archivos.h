#include "funciones.h"

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
  *  @param tamaño de la lista
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* peliculas,int tam, char nombre[]);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* movie, int);

/** \brief Crea, validando si hay espacio, un archivo binario
 *
 * \param Puntero a la estructura a cargar en el binario
 * \return
 *
 */

void crearBinario (EMovie* peliculas);


