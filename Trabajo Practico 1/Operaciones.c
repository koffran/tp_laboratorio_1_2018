#include "Operaciones.h"

float getNum(char texto[30])
{
    float numero;
    printf("%s",texto);
    scanf("%f",&numero);
    return numero;
}

float suma (float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;
    return resultado;
}

float resta (float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}

float division (float num1, float num2)
{
    float resultado;
    resultado = num1 / num2;
    return resultado;
}

float multiplicacion (float num1, float num2)
{
    float resultado;
    resultado = num1 * num2;
    return resultado;
}

long long int factorial (float num1)
{
    long long int resultado=1;
    int i;

        for (i=1;i<(num1+1);i++)
        {
        resultado *= i;
        }

    return resultado;
}
