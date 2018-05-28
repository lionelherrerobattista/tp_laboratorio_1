#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>

#include "funciones.h"

#define LIBRE 0
#define OCUPADO 1

void incializarPeliculas(EMovie* movie, int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        (movie+i)->estado=LIBRE;
    }
}

int agregarPelicula(EMovie* movie,int limite)
{
    int index;
    int retorno=0;
    char auxiliarValidacion[50];
    int validacion=0;

    index=obtenerEspacioLibre(movie, limite);

    if(index>=0)
    {
        printf("\nIngrese el titulo de la pelicula: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esChar(auxiliarValidacion);

        while (validacion==0)
        {
                printf("\nError. Ingrese el titulo nuevamente: ");
                fflush(stdin);
                gets(auxiliarValidacion);
                validacion=esChar(auxiliarValidacion);
        }

        strcpy((movie+index)->titulo,auxiliarValidacion);

        validacion=0;

        printf("\nIngrese el genero de la pelicula: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esChar(auxiliarValidacion);

        while (validacion==0)
        {
                printf("\nError. Ingrese el genero nuevamente: ");
                fflush(stdin);
                gets(auxiliarValidacion);
                validacion=esChar(auxiliarValidacion);
        }

        strcpy((movie+index)->genero,auxiliarValidacion);

        validacion=0;

        printf("\nIngrese la duracion: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esInt(auxiliarValidacion);


        while (validacion==0)
        {
            printf("\nError. Ingrese la duracion nuevamente: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esInt(auxiliarValidacion);

        }

        (movie+index)->duracion=atoi(auxiliarValidacion);


        validacion=0;

        printf("\nIngrese la descripcion de la pelicula: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esChar(auxiliarValidacion);

        while (validacion==0)
        {
                printf("\nError. Ingrese la descripcion nuevamente: ");
                fflush(stdin);
                gets(auxiliarValidacion);
                validacion=esChar(auxiliarValidacion);
        }

        strcpy((movie+index)->descripcion,auxiliarValidacion);

        validacion=0;

        printf("\nIngrese el puntaje: ");
        fflush(stdin);
        gets(auxiliarValidacion);
        validacion=esInt(auxiliarValidacion);


        while (validacion==0)
        {
            printf("\nError. Ingrese el puntaje nuevamente: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esInt(auxiliarValidacion);

        }

        (movie+index)->puntaje=atoi(auxiliarValidacion);

        (movie+index)->id=siguienteId(movie,limite);

        (movie+index)->estado=OCUPADO;

        retorno=1;


    }

    return retorno;

}

int obtenerEspacioLibre(EMovie* movie, int limite)
{
    int i;
    int retorno=-2;

    for(i=0;i<limite;i++)
    {
        if((movie+i)->estado==LIBRE)
        {
            retorno=i;
            break;

        }
    }

    return retorno;
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

int siguienteId(EMovie* movie, int limite)
{
    int retorno=0;
    int i;

    for(i=0; i<limite; i++)
    {
        if((movie+i)->estado==OCUPADO)
        {
            if((movie+i)->id>retorno)
            {
                retorno=(movie+i)->id;
            }
        }
    }

    return retorno+1;

}

void mostrarPelicula(EMovie* movie,int limite)
{
    int i;

    printf("%-10s %-10s %-10s %-10s %-10s %-15s\n", "Id:", "Titulo","Genero","Duracion","Descripcion","Puntaje");

    for(i=0;i<limite;i++)
    {
        if((movie+i)->estado==1)
        {
           printf("%-10d %-10s %-10s %-10d %-10s %-15d\n",(movie+i)->id,(movie+i)->titulo,(movie+i)->genero,(movie+i)->duracion,(movie+i)->descripcion,(movie+i)->puntaje);

        }

    }

}

int borrarPelicula(EMovie* movie,int limite)
{
    int i;
    int id;
    int retorno=0;

    printf("Ingrese el id de la pelicula que desea borrar: ");
    scanf("%d",&id);

    for(i=0;i<limite;i++)
    {
        if(id==(movie+i)->id)
        {
            (movie+i)->estado=LIBRE;
            retorno=1;
        }


    }

    return retorno;


}

int modificarPelicula(EMovie* movie,int limite)
{
    int i;
    int id;
    int retorno=0;
    char auxiliarValidacion[50];
    int validacion=0;

    printf("Ingrese el id de la pelicula que desea modificar: ");
    scanf("%d",&id);

    for(i=0;i<limite;i++)
    {
        if(id==(movie+i)->id)
        {
            printf("\nIngrese el titulo de la pelicula: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esChar(auxiliarValidacion);

            while (validacion==0)
            {
                    printf("\nError. Ingrese el titulo nuevamente: ");
                    fflush(stdin);
                    gets(auxiliarValidacion);
                    validacion=esChar(auxiliarValidacion);
            }

            strcpy((movie+i)->titulo,auxiliarValidacion);

            validacion=0;

            printf("\nIngrese el genero de la pelicula: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esChar(auxiliarValidacion);

            while (validacion==0)
            {
                    printf("\nError. Ingrese el genero nuevamente: ");
                    fflush(stdin);
                    gets(auxiliarValidacion);
                    validacion=esChar(auxiliarValidacion);
            }

            strcpy((movie+i)->genero,auxiliarValidacion);

            validacion=0;

            printf("\nIngrese la duracion: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esInt(auxiliarValidacion);


            while (validacion==0)
            {
                printf("\nError. Ingrese la duracion nuevamente: ");
                fflush(stdin);
                gets(auxiliarValidacion);
                validacion=esInt(auxiliarValidacion);

            }

            (movie+i)->duracion=atoi(auxiliarValidacion);


            validacion=0;

            printf("\nIngrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esChar(auxiliarValidacion);

            while (validacion==0)
            {
                    printf("\nError. Ingrese la descripcion nuevamente: ");
                    fflush(stdin);
                    gets(auxiliarValidacion);
                    validacion=esChar(auxiliarValidacion);
            }

            strcpy((movie+i)->descripcion,auxiliarValidacion);

            validacion=0;

            printf("\nIngrese el puntaje: ");
            fflush(stdin);
            gets(auxiliarValidacion);
            validacion=esInt(auxiliarValidacion);


            while (validacion==0)
            {
                printf("\nError. Ingrese el puntaje nuevamente: ");
                fflush(stdin);
                gets(auxiliarValidacion);
                validacion=esInt(auxiliarValidacion);

            }

            (movie+i)->puntaje=atoi(auxiliarValidacion);

            retorno=1;

        }
    }

    return retorno;


}


