#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;//variable auxiliar
    this = (ArrayList *)malloc(sizeof(ArrayList));//puntero que contiene otro puntero, tengo que crear memoria para el otro

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );//creo espacio en memoria para el otro puntero.//tengo 10 elem de puntero a void
        if(pElements != NULL)//asigno los datos de la variable auxiliar pElements
        {
            //Se pasan al array list. Los campos esenciales:
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            //punteros a funciones.A esos campos les asigno la dir de memoria de las funciones
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;//le asigno al auxiliar el array list
        }
        else
        {
            free(this);//libero el espacio porque no hay suf espacio en memoria para elements
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)//puntero a void, elemento que quiero agregar
{
    int returnAux = -1;
    //int flag = 0;

    //verifico que los punteros no lleguen NULL
    //Esto se pasa a funcion resizeUP
    if(this!=NULL && pElement!=NULL)//con que uno de los dos sea NULL ya hace que no funcione
    {
        if(!(resizeUp(this)))
        {
            *(this->pElements+this->size)=pElement;//guardo en la dirección de memoria 0. Uso size, que siempre apunta al siguiente elemento
            this->size++;
            returnAux=0;
        }


        /*Otra forma:
        if(resizeUp(this))//si no da cero es null y entra
            {
                flag=1;//es nulo, no se cumple el aumento de espacio
            }

        if(flag==0)//para no repetir el agregado
        {
            *(this->pElements+this->size)=pElement;
            this->size++;


            returnAux=0;
        }*/

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this);//borro la la lista liberando la memoria
        returnAux=0;
    }


    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;//devuelvo el tamaño de la lista

    }


    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL)
    {
        if(index>=0 && index<this->size)//el indice puede ser == 0
        {
            returnAux=*(this->pElements+index);//devuelvo el elemento almacenado de la lista de elementos
        }
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL)
    {
        for(i=0;i<this->size;i++)//itero para buscar el valor en pElements
        {
            if(*(this->pElements+i)==pElement)//busco que el valor *() guardado en el array de punteros pElements en la posición "i" sea igual al que pasa pElement
            {
                returnAux=1;
                break;
            }
            else
            {
                returnAux=0;//No lo encuentra
            }

        }

    }


    return returnAux; //-1 si alguno de los punteros es NULL
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL)
    {
        if(index>=0 && index<this->size)
        {

            *(this->pElements+index)=pElement; //le agrego el elemento

            returnAux=0;

        }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    //int i;
    //void* aux;


    if(this!=NULL)
    {
        if(index>=0 && index<this->size) //el indice se encuentra entre los valores del tamaño del array
        {
            if(!contract(this,index))
            {
                returnAux=0;
            }
        }
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        //solo puedo liberar lo que construí (malloc)
        free(this->pElements);//limpio los elementos
        //free(this);//limpio la lista
        this->size=0;
        //al_newArrayList(); //creo la lista de nuevo sino está todo vacío
        returnAux=0;

    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    void* aux;
    int i;

    if(this!=NULL)
    {

        aux=al_newArrayList();//creo una nueva lista y la asigno a aux
        for(i=0;i<this->size;i++)
        {
          al_add(returnAux,*(this->pElements+i));//le agrego todos los elementos
        }

        //aux=this;//NO! COPIO DIR DE MEMORIA DE LA LISTA copio las listas en un auxiliar
        returnAux=aux; //devuelvo
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    int i;

    if(this!=NULL && pElement!=NULL)
    {
        if(index>=0 && index<=this->size)
        {

            al_add(this,pElement);//agrego un espacio al final
            for(i=this->size-1;i>index;i--)
            {
                //tomo el elemento y lo pongo en la posición
                *(this->pElements+i)=al_get(this,i-1);
            }
            al_set(this,index,pElement);

            returnAux=0;

        }
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL)
    {
        //Recorro pElements
        for(i=0;i<this->size;i++)
        {
            if(*(this->pElements+i)==pElement)//comparo si los datos son iguales
            {
                returnAux=i;//devuelvo la posición
                break;//para que no siga iterando
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        //Me fijo en el valor de size
        if(this->size>0)
        {
            returnAux=0;//no está vacía
        }
        else
        {
            if(this->size==0)
            {
                returnAux=1;//está vacía
            }
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL)
    {
        if(index>=0 && index<=this->size)
        {
            returnAux=al_get(this,index);//tomo el elemento y lo devuelvo *(this->pElements+index);
            contract(this,index);
            /*free(this->pElements+index);
            this->size--;*/
        }
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    void* aux;
    int i;

    if(this!=NULL)
    {
        if((from<this->size && from >=0) && (to<=this->size && to>=0))
        {
            if(from<=to)
            {
                //Creo una nueva lista:
                returnAux=al_newArrayList();
                //Le agrego los elementos desde from hasta to
                for(i=from;i<to;i++)
                {
                    aux=al_get(this,i);//tomo el elemento
                    //al_add(returnAux,this->pElements+i);
                    al_add(returnAux,aux);//lo agrego al vector nuevo

                }

            }

        }
    }

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int contador=0;
    int i;
    int j;

    if(this!=NULL && this2!=NULL)
    {
        for(i=0;i<this->size;i++)
        {
            for(j=0;j<this2->size;j++)
            {

                if(*((this->pElements)+i)==*((this2->pElements)+j))
               {
                   contador++;

               }

            }

        }

        if(contador==this2->size)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }

    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* aux;
    int i;
    int j;

    if(this!=NULL && pFunc!=NULL)
    {
        if(order==0 || order==1)
        {

            for(i=0;i<this->size-1;i++)
            {
                for(j=i+1;j<this->size;j++)
                {
                    if(order==1)
                    {
                        if((*pFunc)(*(this->pElements+i),*(this->pElements+j))==1)//Le la dirección de memoria que está adentro del puntero
                        {

                            aux=*(this->pElements+i);
                            *(this->pElements+i)=*(this->pElements+j);
                            *(this->pElements+j)=aux;
                        }
                    }
                    else
                    {
                        if(order==0)
                        {
                            if((*pFunc)(*(this->pElements+i),*(this->pElements+j))==-1)//si el primero es menor y orden de mayor a menor
                            {

                                aux=*(this->pElements+i);
                                *(this->pElements+i)=*(this->pElements+j);
                                *(this->pElements+j)=aux;
                            }
                        }
                    }

                    /*if(pFunc(this->pElements+i,this->pElements+j)==1 && order==1)//si el 1º es mayor == 1 y orden de menor a mayor
                    {
                        aux=*(this->pElements+i);
                        *(this->pElements+i)=*(this->pElements+j);
                        *(this->pElements+j)=aux;
                    }
                    else
                    {
                        if(pFunc(this->pElements+i,this->pElements+j)==-1 && order==0)//si el primero es menor y orden de mayor a menor
                        {
                            aux=*(this->pElements+i);
                            *(this->pElements+i)=*(this->pElements+j);
                            *(this->pElements+j)=aux;
                        }
                    }*/
                }
            }
            returnAux=0;
        }
    }


    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;

    void** aux;//pElement es un doble puntero a void



    if(this!=NULL)//verifico que no sea NULL
    {

        if(this->size == this->reservedSize)//si esta agotada la capacidad de la memoria, hago el realloc para que no se pise
        {

            aux = (void**) realloc(this->pElements, sizeof(void*)* (this->reservedSize + AL_INCREMENT));//necesito espacio en memoria para espacio a void
            //verfico que el auxiliar no sea nulo
            if(aux!=NULL)
            {
                this->pElements = aux;//le paso el puntero auxiliar con más espacio
                //tengo que modificar el reserved size
                this->reservedSize = this->reservedSize + AL_INCREMENT;//Aumento el espacio reservado

                returnAux=0;
            }
        }
        else
        {
            //si hay espacio
            returnAux=0;

        }

    }


    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    void* aux=NULL;
    int i;

    if(this!=NULL)
    {
        if(index>=0 && index<this->size)
        {

            al_add(this,aux);//agrego un espacio al final
            for(i=this->size-1;i>index;i--)
            {
                *(this->pElements+i)=this->pElements+(i-1);
            }


            returnAux=0;

        }
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    void* aux;
    int i;

    if(this!=NULL)
    {
        if(index>=0 && index<this->size) //el indice se encuentra entre los valores del tamaño del array
        {

            for(i=index;i<this->size-1;i++)
            {
                *(this->pElements+i)=*(this->pElements+(i+1));//piso el elemento anterior desde index(el que quiero borrar)

            }

            this->size--;//le saco uno al tamaño de la lista

            //free((this->pElements)+index);//si libero pierdo los datos

            this->reservedSize = this->reservedSize - AL_INCREMENT;//necesita menos espacio

            //Libero el espacio en memoria adicional:
            aux = (void**) realloc(this->pElements, sizeof(void*)* (this->reservedSize - AL_INCREMENT));
            //verfico que el auxiliar no sea nulo
            if(aux!=NULL)
            {
                this->pElements = aux;
            }


            returnAux=0;

        }
    }

    return returnAux;
}
