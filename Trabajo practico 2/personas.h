#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;


/** \brief Inicializa el estado del array para futuras validaciones
 *
 * \param El array a inicializar
 * \param El tamaño del array
 * \return
 *
 */
void inicializarEstado (ePersona[],int);

/** \brief
 *
 * \param El array en el que se carga la nueva persona
 * \param El indice
 * \return
 *
 */
void alta (ePersona [], int );

/** \brief Da de baja a una persona del array pasando el estado a cero
 *
 * \param El array donde se encuentra el elemento a eliminar
 * \param El indice del array
 * \return
 *
 */
void baja (ePersona [], int );

/** \brief Ordena el array en orden alfabetico
 *
 * \param El array a ordenar
 * \param El tamaño del array
 * \return
 *
 */
void burbujeo (ePersona [], int );

/** \brief Imprime por pantalla todo el contenido del array
 *
 * \param El array a mostrar
 * \param El tamaño del array
 * \return
 *
 */
void mostrar (ePersona [],int );

/** \brief Imprime por pantalla un grafico de barras por edad
 *
 * \param El array
 * \param El tamaño del array
 * \return
 *
 */
void grafico (ePersona [],int );

/** \brief Carga automaticamente datos en el arrayy
 *
 * \param El array
 * \param
 * \return
 *
 */
void hardcodeo (ePersona []);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni,int tam);

#endif // FUNCIONES_H_INCLUDED

