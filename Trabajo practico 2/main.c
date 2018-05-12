#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#define TAM 20

int main()
{
    char seguir='s';
    int opcion=0,aux,dni;
    ePersona personas[TAM];

    inicializarEstado(personas,TAM);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Hardcodeo\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                aux = obtenerEspacioLibre(personas,TAM);
                if (aux== -1)
                {
                    printf("No hay espacio disponible");
                }
                else
                {
                    alta(personas,aux);
                }

                system("pause");
                break;
            case 2:
                system("cls");

                printf("Ingrese el DNI: ");
                scanf("%d",&dni);
                aux = buscarPorDni(personas,dni,TAM);
                if (aux == -1)
                {
                    printf("No se encontro el DNI ingresado\n");
                }
                else
                {
                    baja(personas,aux);
                }

                system("pause");
                break;
            case 3:
                system("cls");

                burbujeo(personas,TAM);
                mostrar(personas,TAM);

                system("pause");
                break;
            case 4:
                system("cls");

                grafico ( personas,TAM);

                system("pause");
                break;
            case 5:
                hardcodeo (personas);
                system("Pause");

                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("Ingrese una opcion valida <1-5>\n");
                system("Pause");
        }
    }

    return 0;
}
