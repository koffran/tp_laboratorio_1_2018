#include "archivos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int agregarPelicula(EMovie* movie)
{
    int retorno=0;
    FILE* pArch;
    pArch = fopen("peliculas.dat","wb");
    if (pArch != NULL)
    {
        fwrite(movie,sizeof (EMovie),1,pArch);
        fclose(pArch);
        retorno = 1;
    }
    fread (movie,sizeof (EMovie),1,pArch);
    fclose(pArch);
    return retorno;

}

void crearBinario (EMovie* peliculas)
{
    FILE* pArch;
    pArch =fopen("peliculas.dat","rb");
    if (pArch == NULL)
    {
        pArch = fopen("peliculas.dat","wb");
        if (pArch == NULL)
        {
            printf("no se encuentra espacio en memoria");

        }
    }
    fread (peliculas,sizeof (EMovie),1,pArch);
    fclose(pArch);
}

void generarPagina(EMovie* peliculas,int tam,char nombre[])
{
    int i;
    FILE* pArch;
    pArch=fopen(nombre,"w");
    if(pArch==NULL)
    {
        printf("\nError al generar la pagina\n");
        exit(1);
    }
    for(i=0;i<tam;i++)
    {
        if((peliculas+i)->estado==1)
        {
            fprintf(pArch,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");
            fprintf(pArch,"<article class='col-md-4 article-intro'> <a href='#'><img class='img-responsive img-rounded' src=%s alt=''>",(peliculas+i)->linkImagen);
            fprintf(pArch,"</a><h3><a href='#'> %s</a></h3><ul>",(peliculas+i)->titulo);
            fprintf(pArch,"<li>Id Pelicula: %d</li><li>Genero: %s</li><li>Puntaje: %d</li><li>Duracion: %d minutos</li></ul>",(peliculas+i)->id,(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion);
            fprintf(pArch,"<p> %s</p></article>",(peliculas+i)->descripcion);
        }
    }
    fclose(pArch);
    printf("\nArchivo creado con exito!");
}

int borrarPelicula(EMovie* movie, int tam)
{
    int indice;
    char rta;
    int retorno = 0;

    indice = buscarId(movie,tam);
    if ((movie+indice)->estado == 1)
    {
    printf("La pelicula es: %s\n\nDesea eliminarla? <s/n>",(movie+indice)->titulo);
    fflush(stdin);
    rta = getch();
    if (rta == 's')
    {
        (movie+indice)->estado = 0;
        retorno = 1;
    }
    }
    return retorno;
}
