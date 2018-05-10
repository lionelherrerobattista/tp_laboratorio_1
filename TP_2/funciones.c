#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "funciones.h"
#define LIBRE 0
#define OCUPADO 1


void inicializarPersona (EPersona personas[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        personas[i].estado=LIBRE;
    }
}

void inicializarPersonaHardCode (EPersona personas[], int limite)
{
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose"};
    int edad[5]={22,13,56,87,55};
    int dni[5]={38654789,45654821,20951753,123856,21111478};

    int i;

    for (i=0; i<5; i++)
    {
        strcpy(personas[i].nombre,nombre[i]);
        personas[i].edad=edad[i];
        personas[i].dni=dni[i];
        personas[i].estado=OCUPADO;

    }
}

void altaPersona (EPersona personas[], int limite)
{
    int index;


    index=obtenerEspacioLibre(personas, limite);

    if (index>=0)
    {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(personas[index].nombre);

        printf("\nIngrese la edad: ");
        scanf("%d", &personas[index].edad);

        printf("\nIngrese el DNI: ");
        scanf("%d", &personas[index].dni);

        personas[index].estado=OCUPADO;

        printf("\nSe ha ingresado la persona con exito.\n");
    }
    else
    {
        printf("\nNo hay lugar.");
    }
}

int obtenerEspacioLibre(EPersona personas[], int limite)
{
    int i;
    int retorno=-2;

    for (i=0; i<limite; i++)
    {
        if(personas[i].estado==LIBRE)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}



