#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include "validaciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    float numero1;
    float numero2;
    float resultado;
    long long int resultadoFact;
    int flagX=0;
    int flagY=0;

    while(seguir=='s')
    {
        system("cls");
        validarCarga(flagX,numero1,"1- Ingresar 1er operando (A");
        validarCarga(flagY,numero2,"2- Ingresar 2do operando (B");

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            numero1 =getNum("Ingrese el primer numero: ");
            flagX = 1;
            system("pause");
            break;
        case 2:
            system("cls");
            numero2 =getNum("Ingrese el segundo numero: ");
            flagY=1;
            system("pause");
            break;
        case 3:
            system("cls");
            if (validarExistencia(flagX,"no se ingreso el primer numero")&& validarExistencia(flagY,"no se ingreso el segundo numero"))
            if (flagX && flagY)
            {
                resultado = suma(numero1,numero2);
                printf ("El resultado de la suma entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if (validarExistencia(flagX,"no se ingreso el primer numero")&& validarExistencia(flagY,"no se ingreso el segundo numero"))
            {
                resultado = resta(numero1,numero2);
                printf ("El resultado de la resta entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if (validarExistencia(flagX,"no se ingreso el primer numero")&& validarExistencia(flagY,"no se ingreso el segundo numero"))
            {

                if (validarDistintoCero(numero2))
                {
                    resultado = division(numero1,numero2);
                    printf ("El resultado de la division entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);
                }
                else
                {
                    printf("ERROR!! No se puede dividir por cero\n");
                }

            }
            system("pause");
            break;
        case 6:
            system("cls");
            if (validarExistencia(flagX,"no se ingreso el primer numero")&& validarExistencia(flagY,"no se ingreso el segundo numero"))
            {
                resultado = multiplicacion(numero1,numero2);
                printf ("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if (validarExistencia(flagX,"no se ingreso el primer numero"))
            {

                if(validarFactorial(numero1))
                {
                    resultadoFact = factorial(numero1);
                    printf ("El factorial de %.2f es: %lld\n",numero1,resultadoFact);
                }
                else
                {
                    printf("ERROR!!! No se puede factoriar numeros con decimal o  menores a 1\n");
                }

            }
            system("pause");
            break;
        case 8:
            system("cls");

            if (validarExistencia(flagX,"no se ingreso el primer numero")&& validarExistencia(flagY,"no se ingreso el segundo numero"))
            {
                resultado = suma(numero1,numero2);
                printf ("El resultado de la suma entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);

                resultado = resta(numero1,numero2);
                printf ("El resultado de la resta entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);

                if (validarExistencia(flagX,"no se ingreso el primer numero")&& validarExistencia(flagY,"no se ingreso el segundo numero"))
                {
                    //numero2 = validarDistintoCero(numero2);
                    if (validarDistintoCero(numero2))
                    {
                        resultado = division(numero1,numero2);
                        printf ("El resultado de la division entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);
                    }
                    else
                    {
                        printf("ERROR!! No se puede dividir por cero\n");
                    }

                }

                resultado = multiplicacion(numero1,numero2);
                printf ("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n",numero1,numero2,resultado);
            }

            if (validarExistencia(flagX,"no se ingreso el primer numero"))
            {
                if(validarFactorial(numero1))
                {
                    resultadoFact = factorial(numero1);
                    printf ("El factorial de %.2f es: %lld\n",numero1,resultadoFact);
                }
                else
                {
                    printf("ERROR!!! No se puede factoriar numeros con decimal o  menores a 1\n");
                }
            }
            system("pause");
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            system("cls");
            printf("Opcion invalida. Eija una opcion valida <1-9> ");
            system("pause");
            break;
        }

    }
    return 0;
}
