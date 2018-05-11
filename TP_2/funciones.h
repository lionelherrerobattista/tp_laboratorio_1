#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    int id;
    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
//int buscarPorDni(EPersona lista[], int dni);

void inicializarPersona (EPersona[], int);
void inicializarPersonaHardCode (EPersona[], int);

void altaPersona (EPersona[], int);
int siguienteId(EPersona[], int);
int obtenerEspacioLibre(EPersona[], int);

void mostrarPersonas (EPersona [],EPersona, int);

void borrarPersona (EPersona[], int);

void graficoEdad (EPersona[], int);




#endif // FUNCIONES_H_INCLUDED
