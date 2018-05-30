#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDADPELICULAS 5


int main()
{
    char seguir='s';
    int opcion=0;

    int retorno;
    char nombrePagina[50];


    EMovie listadepeliculas[CANTIDADPELICULAS];

    incializarPeliculas(listadepeliculas, CANTIDADPELICULAS);
    //hardcodePeliculas(listadepeliculas, CANTIDADPELICULAS);
    leerArchivoBinario(listadepeliculas,CANTIDADPELICULAS);












    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        while (opcion<1 || opcion>5)
        {
            printf("\nError. Ingrese la opcion nuevamente: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                retorno=agregarPelicula(listadepeliculas,CANTIDADPELICULAS);
                if(retorno==1)
                {
                    printf("Carga exitosa.\n");
                }
                else
                {
                    printf("No se pudo cargar la pelicula.\n");
                }
                generarArchivoBinario(listadepeliculas,CANTIDADPELICULAS);
                break;
            case 2:
                mostrarPelicula(listadepeliculas,CANTIDADPELICULAS);
                if(borrarPelicula(listadepeliculas,CANTIDADPELICULAS))
                {
                    printf("\nSe borro la pelicula seleccionada.");
                }
                else
                {
                    printf("\nNo se pudo borrar la pelicula.\n");
                }
                generarArchivoBinario(listadepeliculas,CANTIDADPELICULAS);
                break;
            case 3:
                mostrarPelicula(listadepeliculas,CANTIDADPELICULAS);
                if(modificarPelicula(listadepeliculas,CANTIDADPELICULAS))
                {
                    printf("Modificacion exitosa.");
                }
                else
                {
                    printf("No se pudo modificar.");
                }
                generarArchivoBinario(listadepeliculas,CANTIDADPELICULAS);
               break;
            case 4:
                printf("Ingrese el nombre del archivo:");
                fflush(stdin);
                gets(nombrePagina);
                retorno=generarPagina(listadepeliculas,nombrePagina,CANTIDADPELICULAS);
                if(retorno==1)
                {
                    printf("\nSe genero la pagina con exito.\n");
                }
                else
                {
                    printf("\nError al generar la pagina.\n");
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
