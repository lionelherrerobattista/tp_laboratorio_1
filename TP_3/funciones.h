#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];
    int estado;
    int id;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie*,int);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie*,int);

/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 * \param lista[] EMovie la lista de peliculas a ser agregadas en el archivo.
 * \param nombre[] char Nombre del archivo html
 * \param int limite de películas
 * \return int 1 si se generó o 0 si hubo error
 *
 */
int generarPagina(EMovie lista[], char nombre[],int);

/** \brief Busca un espacio libre en el array de estructura
 *
 * \param EMovie* puntero al array de estructura
 * \param int limite de películas
 * \return int indice libre
 *
 */
int obtenerEspacioLibre(EMovie*, int);

/** \brief Comprueba que el dato ingresado sea carácter
 *
 * \param char[] string auxiliar
 * \return int 0 si no es carácter
 *
 */
int esChar(char[]);

/** \brief Comprueba que el dato ingresado sea int
 *
 * \param char[] string auxiliar
 * \return int 0 si no es int
 *
 */
int esInt(char[]);

/** \brief Inicializa todas las películas en estado libre
 *
 * \param EMovie* puntero al array de estructura
 * \param int limite de peliculas
 * \return void
 *
 */
void incializarPeliculas(EMovie*, int);


/** \brief Muestra una lista de películas
 *
 * \param EMovie* puntero al array de películas
 * \param int límite de películas
 * \return void
 *
 */
void mostrarPelicula(EMovie*,int);


/** \brief Busca el siguiente ID libre
 *
 * \param EMovie* puntero al array de estructuras
 * \param int límite de películas
 * \return int el id libre
 *
 */
int siguienteId(EMovie*, int);


/** \brief Modifica los datos ingresados para la película
 *
 * \param EMovie* puntero al array de estructuras
 * \param int límite de películas
 * \return int 1 si se modifica o 0 si hubo error
 *
 */
int modificarPelicula(EMovie*,int);


//void hardcodePeliculas(EMovie*,int);
/** \brief Genera y actualiza el archivo binario
 *
 * \param EMovie* puntero al array de estructuras
 * \param int límite de películas
 * \return void
 *
 */
void generarArchivoBinario(EMovie*,int);


/** \brief Lee el archivo binario
 *
 * \param EMovie* puntero al array de estructuras
 * \param int límte de películas
 * \return void
 *
 */
void leerArchivoBinario(EMovie*,int);





#endif // FUNCIONES_H_INCLUDED
