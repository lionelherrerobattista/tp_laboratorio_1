#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include "funciones.h"

#define LIBRE 0
#define OCUPADO 1


void inicializarPersona (EPersona personas[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        personas[i].estado=LIBRE;
        personas[i].id=0;
        personas[i].edad=0;
    }
}

void inicializarPersonaHardCode (EPersona personas[], int limite)
{
    int id[10]={100,101,102,103,104,105,106,107,108,109};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luis","Guillermo","Laura","Agustin","Paula"};
    int edad[10]={22,13,56,87,55,5,20,33,19,25};
    int dni[10]={38654789,45654821,20951753,123856,21111478,45236854,40111222,32654984,39654128,37569845};

    int i;

    for (i=0; i<10; i++)
    {
        personas[i].id=id[i];
        strcpy(personas[i].nombre,nombre[i]);
        personas[i].edad=edad[i];
        personas[i].dni=dni[i];
        personas[i].estado=OCUPADO;

    }
}

void altaPersona (EPersona personas[], int limite)
{
    int index;
    int validacion=0;
    int validacionlargo=0;
    char auxiliarValidacion[50];


    index=obtenerEspacioLibre(personas, limite);

    if (index>=0)
    {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esChar(auxiliarValidacion);

        while (validacion==0)
        {
                printf("\nError. Ingrese el nombre: ");
                fflush(stdin);
                gets(auxiliarValidacion);
                validacion=esChar(auxiliarValidacion);
        }

        strcpy(personas[index].nombre,auxiliarValidacion);

        validacion=0;

        printf("\nIngrese la edad: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esInt(auxiliarValidacion);
        validacionlargo=strlen(auxiliarValidacion);

        while (validacion==0 || validacionlargo>3)
        {
            printf("\nError. Ingrese la edad nuevamente: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esInt(auxiliarValidacion);
            validacionlargo=strlen(auxiliarValidacion);
        }

        personas[index].edad=atoi(auxiliarValidacion);


        validacion=0;

        printf("\nIngrese el DNI: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esInt(auxiliarValidacion);
        validacionlargo=strlen(auxiliarValidacion);

        while (validacion==0 || validacionlargo>8)
        {
            printf("\nError. Ingrese el DNI nuevamente: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esInt(auxiliarValidacion);
            validacionlargo=strlen(auxiliarValidacion);
        }

        personas[index].dni=atoi(auxiliarValidacion);

        personas[index].id=siguienteId(personas,limite);

        personas[index].estado=OCUPADO;

        printf("\nSe ha ingresado la persona con exito.\n");
    }
    else
    {
        printf("\nNo hay lugar.");
    }
}

int esChar (char auxiliar[])
{
    int i;
    int retorno;
    int limite;

    limite=strlen(auxiliar);

    for (i=0;i<limite;i++)
    {
        retorno=isalpha(auxiliar[i]);

        if (retorno==0)
        {
            break;
        }
    }



    return retorno;

}

int esInt(char auxiliar[])
{
    int i;
    int retorno;
    int limite;

    limite=strlen(auxiliar);

    for (i=0;i<limite;i++)
    {
        retorno=isdigit(auxiliar[i]);

        if (retorno==0)
        {
            break;
        }
    }

    return retorno;

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

int siguienteId(EPersona personas[], int limite)
{
    int retorno=0;
    int i;

    for(i=0; i<limite; i++)
    {
        if(personas[i].estado==OCUPADO)
        {
            if(personas[i].id>retorno)
            {
                retorno=personas[i].id;
            }
        }
    }

    return retorno+1;

}



void mostrarPersonas (EPersona personas[],EPersona auxiliar, int limite)
{
    int i;
    int j;



    printf("\n%-10s %-10s %-10s %-10s\n","Id:","Nombre:","Edad:","DNI:");
    for (i=0; i<limite-1; i++)
    {
        for (j=i+1; j<limite; j++)
        {
            if (stricmp(personas[i].nombre, personas[j].nombre)>0)
            {
                auxiliar=personas[i];
                personas[i]=personas[j];
                personas[j]=auxiliar;

            }

        }

    }

    for (i=0; i<limite-1; i++)
    {
        if (personas[i].estado==OCUPADO)
        {
            printf("%-10d %-10s %-10d %-10d\n",personas[i].id, personas[i].nombre, personas[i].edad, personas[i].dni);
        }
    }
}

void borrarPersona (EPersona personas[], int limite)
{
    int id;
    int i;
    int flag=0;



    printf("\nIngrese el id de la persona que quiere borrar: ");
    scanf("%d",&id);


    for (i=0; i<limite; i++)
    {
        if (personas[i].id==id)
        {
           personas[i].estado=LIBRE;
           flag=1;
        }
    }

    if(flag==0)
    {
        printf("\nEl id ingresado no es valido.\n");
    }
}

void graficoEdad (EPersona personas[], int limite)
{
    int i;
    int j;
    int edades[3]={};//1.<18,2.18-35,3.+35
    int flag=0;
    int max;

    printf(" \n");
    for (i=0; i<limite; i++)
    {
        if (personas[i].estado==OCUPADO)
        {
            if (personas[i].edad>35)
            {
                edades[2]=edades[2]+1;
            }
            else
            {
                if (personas[i].edad>=18 && personas[i].edad<=35)
                {
                   edades[1]=edades[1]+1;
                }
                else
                {
                    edades[0]=edades[0]+1;
                }
            }

        }
    }

    for (i=0; i<3;i++)
    {
        if(flag==0 || edades[i]>max)
        {
            max=edades[i];
            flag=1;
        }
    }

    for (i=max;i>0;i--)
    {
        printf("%5d-", i);

        for (j=0;j<3;j++)
        {
            if (edades[j]>=i)
            {
                printf("  *  ");
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");
    }

    printf("       <18 19-35 >35\n");

}






