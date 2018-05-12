#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20



int main()
{
    char seguir='s';
    int opcion=0;
    //validar que se ingreso opción correcta

    EPersona listaDePersonas[TAM];
    EPersona auxiliar;

    inicializarPersona(listaDePersonas, TAM);
    inicializarPersonaHardCode(listaDePersonas, TAM);

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nIngrese una opcion: ");

        scanf("%d",&opcion);

        while (opcion>=6 || opcion <=0)
        {
            printf("\nNo es una opcion valida.\n");
            printf("\n1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por nombre\n");
            printf("4- Imprimir grafico de edades\n\n");
            printf("5- Salir\n");
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);

        }

        switch(opcion)
        {
            case 1:
                altaPersona(listaDePersonas, TAM);
                break;
            case 2:
                mostrarPersonas(listaDePersonas,auxiliar, TAM);
                borrarPersona(listaDePersonas, TAM);
                break;
            case 3:
                mostrarPersonas(listaDePersonas,auxiliar, TAM);
                break;
            case 4:
                graficoEdad(listaDePersonas, TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
