#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h" //FUNCIONES DE ABM

void inicializarEstado(EMovie* peliculas, int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        (peliculas+i)->estado = 0;
    }
}

void pedirDatos(EMovie* peliculas, int tam)
{
    int auxDuracion, auxPuntaje,auxId;
    char auxTitulo[20], auxGenero[20],auxDescripcion [50],auxLink[50];

    printf("Ingrese el titulo: ");
    fflush(stdin);
    gets(auxTitulo);
    strupr(auxTitulo);
    printf("\nIngrese el genero: ");
    fflush(stdin);
    gets (auxGenero);
    printf("Ingrese la duracion: ");
    scanf("%d",&auxDuracion);
    printf("Ingrese la descripcion: ");
    fflush(stdin);
    gets (auxDescripcion);
    printf("Ingrese el puntaje: ");
    scanf ("%d",&auxPuntaje);
    printf("Ingrese el ID: ");
    scanf("%d",&auxId);


    cargarDatos (peliculas, tam, auxDuracion, auxPuntaje, auxTitulo, auxGenero, auxDescripcion, auxId);
}

int buscarLibre (EMovie* peliculas, int tam)
{
    int i;//indice
    int retorno;

    for (i=0; i<tam; i++)
    {
        if ((peliculas+i)->estado == 0)
        {
            retorno = i;
        }
    }

    return retorno;
}

void hardcodeo (EMovie* peliculas, int tam)
{
    int i;
    int auxId [10] = {1,2,3,4,5,6,7,8,9,10};
    int auxDuracion [10]= {124,116,115,102,177,108,113,107,126,122};
    int auxPuntaje[10]  ={10,9,7,7,8,10,6,6,5,7};
    char auxTitulo [10][20]=  {"STAR WARS","VOLVER AL FUTURO","INDIANA JONES","EL BAR","EL PADRINO","PSICOSIS","MEMENTO","TERMINATOR","HER","FRIDA"};
    char auxGenero[10] [20] = {"CIENCIA FICCION","CIENCIA FICCION","ACCION","COMEDIA","DRAMA","THRILLER","DRAMA","CIENCIA FICCION","DRAMA","DRAMA"};
    char auxDescripcion [10][512]=  {"Obi Wan Kenobi es el guia de Luke Skywalker en su mision para rescatar a la princesa Leia de Darth Vader.","El excentrico inventor Doc Brown convierte un DeLorean en una maquina del tiempo que accidentalmente envia a su joven amigo, Marty McFly, al pasado","EL gobierno contrata a Indiana Jones para encontrar la legendaria Arca de la Alianza","Un grupo de personas queda atrapado en un bar de Madrid, a medida que aumenta la tension las situaciones extremas no se hacen esperar","Puede un heroe de guerra legalizar un imperio del crimen organizado?","Una empleada escapa con un fajo de dinero para comenzar una nueva vida, pero termina en el oscuro motel Bates","Un apesadumbrado hombre que no recuerda casi nada debe calerse de sus notas para descubrir la espeluznante verdad","Las maquinas dominan el mundo. Los rebeldes que luchan contra ellas tienen como lider a John Connor. Las maquinas deciden enviar al pasado a un robot para eliminar a Sarah Connor, la madre de John","Un escritor solitario encuentra el amor de la manera mas inesperada: en el interior de un sistema operativo","La relacion de Frida Kahlo con Diego Rivera y su reputacion politica y sexual."};

    for (i=0;i<tam;i++)
    {
        cargarDatos(peliculas,tam,auxDuracion[i],auxPuntaje[i],auxTitulo[i],auxGenero[i],auxDescripcion[i],auxId[i]);
    }
}

void cargarDatos (EMovie* peliculas,int tam, int duracion, int puntaje, char titulo[], char genero[], char descripcion [], int id)
{
    int indice;
    indice = buscarLibre(peliculas, tam);

    strcpy ((peliculas+indice)->titulo,titulo);
    strcpy ((peliculas+indice)->genero,genero);
    strcpy ((peliculas+indice)->descripcion,descripcion);
    (peliculas+indice)->duracion = duracion;
    (peliculas+indice)->puntaje = puntaje;
    (peliculas+indice)->id = id;
    (peliculas+indice)->estado = 1;

    cargarLinks (peliculas,tam);
}

int buscarId (EMovie* peliculas, int tam)
{
    int i, id;
    int indice = -1;
    printf("Ingrese el ID: ");
    scanf("%d",&id);

    for (i=0; i<tam; i++)
    {
        if ((peliculas + i)->estado != 0 &&  (peliculas + i)->id == id)
        {
            indice = i;
        }
    }
    return indice;
}

void modificarPelicula (EMovie* peliculas, int tam)
{
    int auxDuracion, auxPuntaje;
    char seguir = 's';
    int indice;
    int opcion;
    indice = buscarId(peliculas, tam);

    if ((peliculas+indice)->estado == 1)
    {
        while (seguir == 's')
        {
            system("cls");

            printf("DATOS DE LA PELICULA SELECCIONADA\n\n\t\tTITULO\t\tGENERO\t\tDURACION\t\tDESCRIPCION\t\tPUNTAJE\n");
            printf("\t\t%s\t%s\t%d\t\t\t%s\t\t%d\n",(peliculas+indice)->titulo,(peliculas+indice)->genero, (peliculas+indice)->duracion,(peliculas+indice)->descripcion,(peliculas+indice)->puntaje);
            printf("Que dato desea modificar? \n1 - Titulo\n2 - Genero\n3 - Duracion\n4 - descripcion\n5 - Puntaje\n6 - Salir\n");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                system("cls");
                printf("Ingrese el nuevo titulo: ");
                fflush(stdin);
                gets ((peliculas+indice)->titulo);
                system("pause");
                break;
            case 2:
                system("cls");
                printf ("Ingrese el nuevo genero: ");
                fflush(stdin);
                gets ((peliculas+indice)->genero);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("Ingrese la duracion: ");
                scanf("%d",&auxDuracion);
                (peliculas+indice)->duracion = auxDuracion;
                system("pause");
                break;
            case 4:
                system("cls");
                printf("Ingrese la nueva descripcion: ");
                fflush(stdin);
                gets ((peliculas+indice)->descripcion);
                system("pause");
                break;
            case 5:
                system("cls");
                printf("Ingrese el puntaje: ");
                scanf("%d",&auxPuntaje);
                (peliculas+indice)->puntaje = auxPuntaje;
                system("pause");
                break;
            case 6:
                seguir = 'n';
                break;
            }

        }
    }
    else
    {
        printf ("\nNo existe el ID ingresado");
    }
}


void cargarLinks (EMovie* peliculas,int tam)
{
    int i;
    int auxInt;
    char auxTitulo [50];

    strcpy (auxTitulo,peliculas->titulo);
    auxInt = atoi(auxTitulo);
    for (i=0;i<tam;i++)
    {
        if (strcmp ((peliculas+i)->titulo,"STAR WARS")==0)
        {
            strcpy((peliculas+i)->linkImagen,"'https://lh3.googleusercontent.com/-H1KqX5HicIU/AAAAAAAAAAI/AAAAAAABSs8/XItaPYUOWX4/photo.jpg'");
        }
        else
        {
            if (strcmp ((peliculas+i)->titulo, "VOLVER AL FUTURO")==0)
            {
                strcpy((peliculas+i)->linkImagen,"http://es.web.img3.acsta.net/c_300_300/medias/nmedia/18/79/64/98/19512261.jpg");
            }
            else
            {
                if (strcmp ((peliculas+i)->titulo,"INDIANA JONES")==0)
                {
                    strcpy((peliculas+i)->linkImagen,"http://thinkhousedev.com/images/uploads/1360/indiana_jones_raiders_of_lost_ark_updated_title_300_x_300__event-square.jpg");
                }
                else
                {
                    if (strcmp ((peliculas+i)->titulo,"EL BAR")==0)
                    {
                        strcpy((peliculas+i)->linkImagen,"http://es.web.img2.acsta.net/c_300_300/pictures/17/01/25/13/52/576358.jpg");
                    }
                    else
                    {
                        if (strcmp ((peliculas+i)->titulo,"EL PADRINO")==0)
                        {
                            strcpy((peliculas+i)->linkImagen,"http://bucket.clanacion.com.ar/anexos/fotos/cartelera/el-padrino-c_4504gr.jpg");
                        }
                        else
                        {
                            if (strcmp ((peliculas+i)->titulo,"PSICOSIS")==0)
                            {
                                strcpy((peliculas+i)->linkImagen,"http://www.cinemaspop.com/435-503-large/poster-psicosis.jpg");
                            }
                            else
                            {
                                if (strcmp ((peliculas+i)->titulo,"MEMENTO")==0)
                                {
                                    strcpy((peliculas+i)->linkImagen,"https://www.faber.co.uk/media/catalog/product/cache/1/image/300x300/9df78eab33525d08d6e5fb8d27136e95/1/1/11039.books.origjpg.jpg");
                                }
                                else
                                {
                                    if (strcmp ((peliculas+i)->titulo,"TERMINATOR")==0)
                                    {
                                        strcpy((peliculas+i)->linkImagen,"https://celebrityauthentics.com/wp-content/uploads/2016/11/schwarzenegger2740terminator_1_X-300x300.jpg");
                                    }
                                    else
                                    {
                                        if (strcmp ((peliculas+i)->titulo,"HER")==0)
                                        {
                                            strcpy((peliculas+i)->linkImagen,"http://es.web.img3.acsta.net/c_300_300/pictures/13/12/24/09/59/266766.jpg");
                                        }
                                        else
                                        {
                                            if (strcmp ((peliculas+i)->titulo,"FRIDA")==0)
                                            {
                                               strcpy((peliculas+i)->linkImagen,"https://i.pinimg.com/736x/2b/54/8b/2b548b21ab36e1d071f4003d7a18f38a--frida-movie-frida-film.jpg");
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



void listar (EMovie* peliculas, int tam)
{
    int indice;

    printf("-----PELICULAS------");
    printf("\n\nID\t\tTITULO\n");
    for (indice=0;indice<tam;indice++)
    {
        if ((peliculas+indice)->estado == 1)
        {
            printf("%d\t\t%s\n",(peliculas+indice)->id,(peliculas+indice)->titulo);
        }
    }
}
