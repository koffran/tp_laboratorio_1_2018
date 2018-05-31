#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
//FUNCIONES DE ABM
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImagen[256];
    int estado;
    int id;
}EMovie;

/** \brief Pide datos al usuario
 *
 * \param Puntero a la estructura en la que se guardaran los datos
 * \param Tamaño del array estructura
 *
 */
void pedirDatos(EMovie* peliculas, int tam);

/** \brief Inicializa el estado de cada pelicula en cero para siguientes validaciones.
 *
 * \param puntero a la estructura
 * \param tamaño del array
 *
 */
void inicializarEstado(EMovie*, int );

/** \brief Carga los datos recibidos en la estructura
 *
 * \param La estructura en la cual se cargan los datos.
 * \param tamaño del array
 * \param La duracion de la pelicula representada en minutos
 * \param el puntaje de la pelicula
 * \param array con el nombre de la pelicula
 * \param el genero de la pelicula
 * \param una breve descripcion de la pelicula
 * \param indice del array para cada pelicula
 *
 */
void cargarDatos (EMovie* peliculas,int tam, int duracion, int puntaje, char titulo[], char genero[], char descripcion [],int);

/** \brief Busca el primer indice de array libre
 *
 * \param puntero a estructura
 * \param tamaño del array
 * \return Devuelve el indice libre o -1 si no se encuentra disponible
 *
 */
int buscarId (EMovie* peliculas, int tam);

/** \brief Abre un menu para modificar diferentes datos de una peliula
 *
 * \param puntero a la estructura de peliculas
 * \param tamaño del array
 *
 */
void modificarPelicula (EMovie* peliculas, int tam);

/** \brief Carga automaticamente 10 peliculas con todos sus datos
 *
 * \param puntero a la estructura de peliculas
 * \param tamaño del array
 *
 */
void hardcodeo (EMovie* peliculas, int tam);

/** \brief Asigna un link de imagen a cada pelicula
 *
 * \param puntero a estructura de peliculas
 * \param tamaño del array
 *
 */
void cargarLinks (EMovie* peliculas,int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void listar (EMovie* , int );
#endif // FUNCIONES_H_INCLUDED
