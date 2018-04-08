#include "funciones.h"
#include <stdio.h>


void sumar(float numeroUno, float numeroDos)
{
    float suma;

    suma= numeroUno + numeroDos;

    printf("El resultado de la suma es: %f\n", suma);
}

void restar(float numeroUno, float numeroDos)
{
    float resta;

    resta= numeroUno - numeroDos;

    printf("El resultado de la resta es: %f\n", resta);

}

void multiplicar(float numeroUno, float numeroDos)
{
    float multiplicacion;

    multiplicacion= numeroUno * numeroDos;

    printf("El resultado de la multiplicacion es: %f\n", multiplicacion);

}

void dividir(float numeroUno, float numeroDos)
{
    float division;
    if (numeroDos==0)
        {
            printf("Error. No se puede dividir entre cero.\n");
        }
        else
        {
         division= numeroUno / numeroDos;
         printf("El resultado de la division es: %f\n", division);
        }
}

void factorial (float numero)
{
  int i=0;
  int factorial=1;

  if (numero - (int)numero != 0 || numero < 0)
    {
        printf("No se puede calcular el factorial. El operando debe ser un entero positivo.\n");
    }
    else
    {
        for (i=numero; i>=1; i--)
        {
            factorial=factorial*i;
        }
        printf("El factorial es %d\n",factorial);
    }
}


