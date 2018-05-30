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

    if(movie!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            (movie+i)->estado=LIBRE;
        }

    }
}

/*void hardcodePeliculas(EMovie* movie,int limite)
{

    int i;
    char titulos[][100]={"Back to the future","El Padrino","La Lista de Schindler"};
    char generos[][50]={"Aventura","Drama","Historico"};
    int puntajes[3]={86,92,90};
    int duracion[3]={116,175,195};

    FILE* miArchivo;

    miArchivo=fopen("sinopsis.txt","r");


    for (i=0;i<3;i++)
    {
        strcpy((movie+i)->titulo,titulos[i]);
        strcpy((movie+i)->genero,generos[i]);
        (movie+i)->puntaje=puntajes[i];
        (movie+i)->duracion=duracion[i];
        (movie+i)->id=i+1;
        (movie+i)->estado=OCUPADO;
        fgets((movie+i)->descripcion,500,miArchivo);

    }

    fclose(miArchivo);

    miArchivo=fopen("imagenes.txt","r");

    for (i=0;i<3;i++)
    {

        fgets((movie+i)->linkImagen,500,miArchivo);

    }

    fclose(miArchivo);


}*/

int agregarPelicula(EMovie* movie,int limite)
{
    int index;
    int retorno=0;
    char auxiliarValidacion[50];
    int validacion=0;

    if(movie!=NULL)
    {
        index=obtenerEspacioLibre(movie, limite);

        if(index>=0)
        {
            printf("\nIngrese el titulo de la pelicula: ");
            fflush(stdin);
            gets((movie+index)->titulo);


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

            printf("\nIngrese el link de la imagen: ");
            fflush(stdin);
            gets((movie+index)->linkImagen);

            (movie+index)->puntaje=atoi(auxiliarValidacion);

            (movie+index)->id=siguienteId(movie,limite);

            (movie+index)->estado=OCUPADO;

            retorno=1;


        }



    }

    return retorno;


}

int obtenerEspacioLibre(EMovie* movie, int limite)
{
    int i;
    int retorno=-2;

    if(movie!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if((movie+i)->estado==LIBRE)
            {
                retorno=i;
                break;

            }
        }
    }

    return retorno;

}

int esChar (char auxiliar[])
{
    int i;
    int espacio;
    int caracter;
    int limite;
    int retorno=1;

    limite=strlen(auxiliar);

    for (i=0;i<limite;i++)
    {
        caracter=isalpha(auxiliar[i]);//0 si no es carácter
        espacio=isspace(auxiliar[i]);//0 si no es espacio

        if (caracter==0 && espacio==0)
        {
            retorno=0;
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

    if(movie!=NULL)
    {
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
    }
    return retorno+1;
}

void mostrarPelicula(EMovie* movie,int limite)
{
    int i;

    if(movie!=NULL)
    {

        printf("%-5s %-25s %-20s %-20s %-20s\n", "Id:", "Titulo","Genero","Duracion","Puntaje");

        for(i=0;i<limite;i++)
        {
            if((movie+i)->estado==1)
            {
               printf("%-5d %-25s %-20s %-20d %-20d\n",(movie+i)->id,(movie+i)->titulo,(movie+i)->genero,(movie+i)->duracion,(movie+i)->puntaje);
            }
        }
    }
}

int borrarPelicula(EMovie* movie,int limite)
{
    int i;
    int id;
    int retorno=0;
    char respuesta;

    if(movie!=NULL)
    {

        printf("Ingrese el id de la pelicula que desea borrar: ");
        scanf("%d",&id);

        printf("\nEsta seguro que desea borrar la pelicula?(s/n)");
        fflush(stdin);
        respuesta=getche();

        while(respuesta!='s' && respuesta!='n')
        {
            printf("\nIngrese s o n: ");
            fflush(stdin);
            respuesta=getche();
        }

        if(respuesta=='s')
        {
            for(i=0;i<limite;i++)
            {
                if(id==(movie+i)->id)
                {
                    (movie+i)->estado=LIBRE;
                    retorno=1;
                }
            }
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

    if(movie!=NULL)
    {

        printf("Ingrese el id de la pelicula que desea modificar: ");
        scanf("%d",&id);

        for(i=0;i<limite;i++)
        {
            if(id==(movie+i)->id)
            {
                printf("\nIngrese el titulo de la pelicula: ");
                fflush(stdin);
                gets((movie+i)->titulo);

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
                gets((movie+i)->descripcion);

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

                printf("\nIngrese el link de la imagen: ");
                fflush(stdin);
                gets((movie+i)->linkImagen);


                retorno=1;

            }
        }


    }
    return retorno;
}

int generarPagina(EMovie lista[], char nombre[],int limite)
{
    FILE* paginaWeb;
    char buffer[2000]={};
    int i;
    char numero[50]={};
    int retorno=1;
    int flag=0;




    strcat(nombre,".html");

    paginaWeb=fopen(nombre,"w");

    if(paginaWeb==NULL)
    {
        paginaWeb=fopen(nombre,"w");
        if(paginaWeb==NULL)
        {
            retorno=0;
            flag=1;
            return retorno;
        }



    }

    if (flag==0)
    {
        for(i=0;i<limite;i++)
        {
            if(lista[i].estado==OCUPADO)
            {
                memset(buffer,0,sizeof(buffer));

                strcat(buffer,"<article class='col-md-4 article-intro'>"
                        "<a href='#'>"
                            "<img class='img-responsive img-rounded' src='");
                strcat(buffer,lista[i].linkImagen);
                strcat(buffer,"'alt=''>"
                                 "</a>"
                                 "<h3>"
                                    "<a href='#'>");
                strcat(buffer,lista[i].titulo);
                strcat(buffer,"</a>"
                                "</h3>"
                            "<ul>"
                                "<li>Género: ");
                strcat(buffer,lista[i].genero);
                strcat(buffer,"</li>"
                            "<li>Puntaje: ");
                sprintf(numero,"%d",lista[i].puntaje);//copia int en un buffer char
                strcat(buffer,numero);
                strcat(buffer,"</li>"
                                "<li>Duración: ");
                sprintf(numero,"%d",lista[i].duracion);
                strcat(buffer,numero);
                strcat(buffer,"</li>"
                                "</ul>"
                                "<p>");
                strcat(buffer,lista[i].descripcion);
                strcat(buffer,"</p>"
                            "</article>");

                fprintf(paginaWeb, buffer);

            }

        }

        fclose(paginaWeb);

    }



    return retorno;
}

void generarArchivoBinario(EMovie* movie,int limite)
{
    FILE* binario;
    int i;
    int flag=0;

    if(movie!=NULL)
    {

        binario=fopen("peliculas.dat","wb");

        if(binario==NULL)
        {
            binario=fopen("peliculas.dat","wb");
            if(binario==NULL)
            {

                flag=1;
            }
        }

        if(flag==0)
        {
            for(i=0;i<limite;i++)
            {
                if((movie+i)->estado==OCUPADO)
                {
                    fwrite((movie+i),sizeof(EMovie),1,binario);
                }
            }
            fclose(binario);
        }
    }
}

void leerArchivoBinario(EMovie* movie,int limite)
{
    FILE* miArchivo;
    int i;

    miArchivo=fopen("peliculas.dat","rb");

    for(i=0;i<limite;i++)
    {
            fread(movie+i,sizeof(EMovie),1,miArchivo);

    }


    fclose(miArchivo);


}




