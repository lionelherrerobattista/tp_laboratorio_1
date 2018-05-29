#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDADPELICULAS 4


int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    int retorno;

    EMovie listadepeliculas[CANTIDADPELICULAS];
    EMovie* punteropeliculas[CANTIDADPELICULAS];



    for(i=0;i<CANTIDADPELICULAS;i++)
    {
        punteropeliculas[i]=&listadepeliculas[i];
    }

    incializarPeliculas(listadepeliculas, CANTIDADPELICULAS);
    hardcodePeliculas(listadepeliculas, CANTIDADPELICULAS);










    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

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
               break;
            case 4:
                seguir = 'n';
            case 5:
                mostrarPelicula(listadepeliculas,CANTIDADPELICULAS);
                break;
        }
    }

    return 0;
}
