#include "validaciones.h"

void validarCarga (int bandera,float numero,char texto [30])
{
    if (bandera==0)
    {
        printf("%s",texto);
        printf("=X)\n");
    }
    else
    {
        printf("%s",texto);
        printf("=%.2f)\n",numero);
    }
}

int validarExistencia(int bandera,char texto [30])
{
    if (bandera == 0)
    {
        printf("%s\n",texto);
    }
    return bandera;
}

int validarDistintoCero (float numero)
{
    int retorno;
    if (numero == 0)
    {
        retorno = 0;
    }
    else
    {
        retorno = 1;
    }
    return numero;
}

int validarFactorial (float numero)
{
    int retorno;
     if ((numero - (int)numero)!= 0 || numero<1)
        {
            retorno = 0;
        }
        else
        {
            retorno = 1;
        }
    return retorno;
}
