#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    float operandoUno=0;
    float operandoDos=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%f)\n",operandoUno);
        printf("2- Ingresar 2do operando (B=%f)\n",operandoDos);
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
                printf("Ingrese el primer operando: ");
                scanf("%f",&operandoUno);
                break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%f",&operandoDos);
                break;
            case 3:
                sumar(operandoUno,operandoDos);
                break;
            case 4:
                restar(operandoUno,operandoDos);
                break;
            case 5:
                dividir(operandoUno, operandoDos);
                break;
            case 6:
                multiplicar(operandoUno,operandoDos);
                break;
            case 7:
                factorial(operandoUno);
                break;
            case 8:
                sumar(operandoUno,operandoDos);
                restar(operandoUno,operandoDos);
                dividir(operandoUno, operandoDos);
                multiplicar(operandoUno,operandoDos);
                factorial(operandoUno);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
