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

void hardcodePeliculas(EMovie* movie,int limite)
{

    int i;
    char titulos[][50]={"Back to the future","El Padrino","La Lista de Schindler"};
    char generos[][50]={"Aventura","Drama","Historico"};
    int puntajes[3]={86,92,90};
    int duracion[3]={116,175,195};

    for (i=0;i<3;i++)
    {
        strcpy((movie+i)->titulo,titulos[i]);
        strcpy((movie+i)->genero,generos[i]);
        (movie+i)->puntaje=puntajes[i];
        (movie+i)->duracion=duracion[i];
        (movie+i)->id=i+1;
        (movie+i)->estado=OCUPADO;

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

    printf("%-5s %-25s %-20s %-20s %-20s\n", "Id:", "Titulo","Genero","Duracion","Puntaje");

    for(i=0;i<limite;i++)
    {
        if((movie+i)->estado==1)
        {
           printf("%-5d %-25s %-20s %-20d %-20d\n",(movie+i)->id,(movie+i)->titulo,(movie+i)->genero,(movie+i)->duracion,(movie+i)->puntaje);

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

void generarPagina(EMovie lista[], char nombre[])
{
    FILE* paginaWeb;
    char buffer[1080]={};

    paginaWeb=fopen("peliculas.html","w");

    fprintf(paginaWeb,"<article class='col-md-4 article-intro'>");
    fprintf(paginaWeb,"<a href='#'>");
    fprintf(paginaWeb,"<img class='img-responsive img-rounded' src='http://ia.mediaimdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg'alt=''>");
 </a>
 <h3>
 <a href='#'>Back to the future</a>
 </h3>
<ul>
<li>Género:Aventura</li>
<li>Puntaje:86</li>
<li>Duración:116</li>
</ul>
 <p>A young man is accidentally sent thirty years into the past in a time-traveling
DeLorean invented by his friend, Dr. Emmett Brown, and must make sure his high-school-age parents
unite in order to save his own existence.</p>
</article>
}




