#include "personas.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void inicializarEstado (ePersona personas[], int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        personas[i].estado = 0;
    }
}

int obtenerEspacioLibre(ePersona lista[],int tam)
{
    int indice = -1,i;
    for (i=0; i<tam; i++)
    {

        if (lista[i].estado ==0)
        {
            indice = i;
        }
    }
    return indice;
}

int buscarPorDni(ePersona lista[], int dni,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (dni == lista[i].dni)
        {
            indice = i;
        }
    }
    return indice;
}

void alta (ePersona lista[], int i)
{
    printf("ingrese el nombre: \n");
    fflush(stdin);
    gets(lista[i].nombre);
    printf("Ingrese la edad: ");
    scanf("%d",&lista[i].edad);
    printf("Ingrese el dni: ");
    scanf("%d",&lista[i].dni);

    lista[i].estado = 1;
}

void baja (ePersona lista[], int i)
{
    char rta;
    printf("Nombre\t Edad\t DNI\n %s\t %d\t %d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
    printf("Desea eliminarlo? <S/N>\n");
    fflush(stdin);
    rta = getche();
    rta = tolower(rta);
    if ( rta == 's')
    {
        lista[i].estado = 0;
        printf("\nPersona elilminada\n\n");
    }
}



void mostrar (ePersona lista[],int tam)
{
    int i;
    printf("Nombre\t Edad\t DNI\n");
    for (i=0; i<tam; i++)
    {
        if (lista[i].estado == 1)
        {
            printf("%s\t %d\t %d\n",lista[i].nombre,lista[i].edad,lista[i].dni);
        }
    }
}

void burbujeo (ePersona lista[], int tam)
{
    int i,j;
    ePersona aux;

    for (i=0; i<tam-1; i++)
    {
        if(lista[i].estado ==1)
        {
            for (j=i+1; j<tam; j++)
            {
                if(lista[j].estado ==1)
                {
                    if(strcmp(lista[i].nombre, lista[j].nombre)>0)
                    {
                        aux = lista[i];
                        lista[i] = lista[j];
                        lista[j] = aux;
                    }
                }

            }

        }
    }
}


void grafico (ePersona lista[],int tam)
{
    int i, cont1=0,//<18
           cont2=0,//19-35
           cont3=0;//>35
    int mayor,flag=0;

    for (i=0; i<tam; i++)
    {
        if (lista[i].estado == 1)
        {
            if (lista[i].edad <18)
            {
                cont1++;
            }
            else
            {
                if (lista[i].edad>17 &&lista[i].edad< 36 )
                {
                    cont2++;
                }
                else
                {
                    cont3++;
                }
            }
        }
    }

    if (cont1 >= cont2 && cont1 >= cont3)
    {
        mayor = cont1;
    }
    else
    {
          if (cont2 >= cont1 && cont2 >= cont3)
        {
            mayor = cont2;
        }
        else
        {
               if (cont3 >= cont2 && cont3 >= cont1)
            {
                mayor = cont3;
            }
        }

    }

    for (i=mayor; i>0;i--)
    {
        if (i<=cont1)
        {
            printf("*");
        }
        if (i<=cont2)
        {
            printf("\t*");
            flag=1;
        }
        if (i<=cont3)
        {
            if(flag ==0)
            {
                printf("\t\t*");
            }
         else
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("<18 \t 18-35 \t >35");
}


void hardcodeo (ePersona personas[])
{

   // ePersona aux[] = {{"Juan",21,1,37041253},{"Paula",13,1,12346783},{"Pablo",56,1,43011789},{"Micaela",27,1,28946312},{"German",17,1,45987654},{"Esteban",58,1,17987456},{"Cecilia",34,1,25654789},{"Roberto",65,1,11000111}};

   strcpy(personas[0].nombre,"Juan");
   personas[0].edad = 21 ;
   personas[0].estado = 1;
   personas[0].dni = 37041253;

   strcpy(personas[1].nombre,"Paula");
   personas[1].edad = 13;
   personas[1].estado = 1;
   personas[1].dni = 12346783;

   strcpy(personas[2].nombre,"Pablo");
   personas[2].edad = 56;
   personas[2].estado = 1;
   personas[2].dni = 43011789;

   strcpy(personas[3].nombre,"Micaela");
   personas[3].edad = 27;
   personas[3].estado = 1;
   personas[3].dni =28946312;

   strcpy(personas[4].nombre,"German");
   personas[4].edad = 17;
   personas[4].estado = 1;
   personas[4].dni = 45987654;

   strcpy(personas[5].nombre,"Esteban");
   personas[5].edad = 58;
   personas[5].estado = 1;
   personas[5].dni = 17987456;

   strcpy(personas[5].nombre,"Cecilia");
   personas[5].edad = 34;
   personas[5].estado = 1;
   personas[5].dni = 25654789;

}
