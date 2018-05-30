#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDADPELICULAS 4


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
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

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
                    printf("Se borro la pelicula seleccionada.\n");
                }
                else
                {
                    printf("No se pudo borrar la pelicula.\n");
                }
                generarArchivoBinario(listadepeliculas,CANTIDADPELICULAS);


                break;
            case 3:
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
                generarPagina(listadepeliculas,nombrePagina,CANTIDADPELICULAS);
                break;
            case 5:

                seguir = 'n';
                break;
            case 6:
                generarArchivoBinario(listadepeliculas,CANTIDADPELICULAS);
                break;
            case 7:
                leerArchivoBinario(listadepeliculas,CANTIDADPELICULAS);
                break;
            case 8:
                mostrarPelicula(listadepeliculas,CANTIDADPELICULAS);
                break;
        }
    }

    return 0;
}
