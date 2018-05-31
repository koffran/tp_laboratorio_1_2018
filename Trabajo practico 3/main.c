#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "archivos.h"
#define TAM 10

/* RESPECTO A LOS LINKS A IMAGENES:
LAS PELICULAS QUE ESTAN PREPARADAS PARA REPRESENTAR SU IMAGEN SON:
STAR WARS, VOLVER AL FUTURO, TERMINATOR, HER, FRIDA, INDIANA JONES, EL BAR, EL PADRINO, PSICOSIS Y MEMENTO.
PUEDEN CARGARSE POR TECLADO O POR HARDCODEO
*/
int main()
{
    char seguir='s';
    char auxString [40];
    int opcion=0;
    int i;
    EMovie peliculas[10];

    inicializarEstado(peliculas,TAM);
    crearBinario (peliculas);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Generar lista precargada web\n"); // GENERA UNA LISTA HARCODEADA DE PELICULAS
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                pedirDatos(peliculas, TAM);
                if (agregarPelicula(peliculas))
                {
                    printf("El archivo se cargo correctamente\n");
                }
                system("pause");
                break;
            case 2:
                system("cls");
                crearBinario(peliculas);
                listar (peliculas,TAM);
                if (borrarPelicula(peliculas,TAM))
                {
                    printf("La pelicula fue eliminada");
                }
                else
                {
                    printf ("No se elimino ninguna pelicula");
                }
                agregarPelicula(peliculas);
                system("pause");
                break;
            case 3:
                system("cls");
                listar (peliculas,TAM);
                modificarPelicula (peliculas, TAM);
                agregarPelicula(peliculas);
                system("pause");
               break;
            case 4:
                printf("Que nombre desea asignarle a la pagina? <Debe finalizar con .html> \n");
                fflush(stdin);
                gets (auxString);
                generarPagina(peliculas, TAM,auxString);
                system ("pause");

                break;
            case 5:
                 hardcodeo (peliculas,TAM);
                 agregarPelicula(peliculas);
                 if (agregarPelicula(peliculas))
                {
                    printf("El archivo se cargo correctamente.\n");
                }
                 system ("pause");
                 break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion valida <1-6>\n");
                system("pause");
                break;
        }
    }

    return 0;
}
