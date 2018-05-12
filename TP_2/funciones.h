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


/** \brief Iniciliza todos los datos en 0
 *
 * \param EPersona[] estructura persona
 * \param int cantidad máxima de personas
 * \return void
 *
 */
void inicializarPersona (EPersona[], int);


/** \brief Hardcode de los datos de las personas
 *
 * \param EPersona[] estructura persona
 * \param int cantidad máxima de personas
 * \return void
 *
 */
void inicializarPersonaHardCode (EPersona[], int);

/** \brief Agrega una persona a la lista
 *
 * \param EPersona[] estructura persona
 * \param int cantidad máxima de personas
 * \return void
 *
 */
void altaPersona (EPersona[], int);


/** \brief Comprueba que el dato ingresado sea de tipo char
 *
 * \param EPersona[] estructura persona
 * \param int indice
 * \return int 0 si no es char
 *
 */
int esChar(EPersona[], int);

/** \brief Busca el id libre que sigue al último utilizado
 *
 * \param EPersona[] estructura personas
 * \param int cantidad máxima de personas
 * \return int devuelve el id libre que sigue al último ocupado
 *
 */
int siguienteId(EPersona[], int);

/** \brief Busca un espacio libre para guardar los datos en el array de persona
 *
 * \param EPersona[] estructura persona
 * \param int cantidad máxima de personas
 * \return int devuelve el índice libre
 *
 */
int obtenerEspacioLibre(EPersona[], int);

/** \brief Muestra las personas ordenadas alfabéticamente
 *
 * \param [] EPersona estructura persona
 * \param EPersona auxiliar para realizar el ordenamiento
 * \param int cantidad máxima de personas
 * \return void
 *
 */
void mostrarPersonas(EPersona [],EPersona, int);

/** \brief Solicita el id de la persona y la borra de la lista
 *
 * \param EPersona[] estructura persona
 * \param int cantidad máxima de personas
 * \return void
 *
 */
void borrarPersona(EPersona[], int);

/** \brief Realiza un gráfico de la cantidad de personas distribuidas en 3 rangos etarios <18 18-35 >35
 *
 * \param EPersona[] estructura persona
 * \param int cantidad máxima de personas
 * \return void
 *
 */
void graficoEdad(EPersona[], int);




#endif // FUNCIONES_H_INCLUDED
