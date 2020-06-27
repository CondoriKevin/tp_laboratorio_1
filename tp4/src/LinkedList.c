#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode;
    pNode = NULL;
    int i;
    int size=ll_len(this);//
    if(this != NULL && nodeIndex>=0 && nodeIndex < size)//validamos "this" osea validamos el puntero a linkedlist
    {
        //y validamos que el index este entre la cantidad de la lista y el 0....no debe ser negativo.
        pNode = this->pFirstNode;//Apuntamos al "PRIMER VAGON"
        if(pNode != NULL)
        {
            for(i = 0; i < nodeIndex ; i++)
            {

                pNode = pNode->pNextNode;//Es como escrivi " pNODO ++; " apuntamos a cada vagon

            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode;//creamos nuevo nodo (1)
    Node* pBeforeNode;
    int size = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= size)//se puede agregar al principio detras de la "locmotora" o al final como el nuevo vagon final
    {
        pNewNode =(Node*) malloc(sizeof(Node));//creamos un nuevo nodo(2)
        if(pNewNode != NULL)
        {
            pNewNode->pElement = pElement;


            if(nodeIndex > 0)//si lo tengo que agregar a algun otro nodo
            {
                pBeforeNode = getNode(this, nodeIndex - 1);
                pNewNode->pNextNode = pBeforeNode->pNextNode;
                pBeforeNode->pNextNode = pNewNode;
                this->size++;
                returnAux = 0;
            }
            else if(nodeIndex == 0)//Si lo tengo que encganchar  a la locomotora :v
            {
                pNewNode->pNextNode = this->pFirstNode;
                this->pFirstNode = pNewNode;
                this->size++;
                returnAux = 0;
            }

        }

    }
    return returnAux;

}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);//asiigan el tañano de la lista a una variable
    if(this != NULL )//condicion para agragar un nuevo vagon pero al final de los anteriores
    {
        if(addNode(this,size,pElement) == 0)
        {
            returnAux=0;
        }

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;//declaramos puntero a Void
    Node* pNode;// declaramos puntero a nodo
    int size=ll_len(this);
    if(this != NULL && index>=0 && index<size)
    {
        pNode=getNode(this,index);
        if(pNode!=NULL)
        {
            returnAux=pNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

//Con ll_set sobreescribimos el elemento al que apunta con el nuevo puntero que me llegua por parametro
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int size=ll_len(this);
    if(this != NULL && index>=0 && index<size)//la validacion de this esta demas ya que get node tambien lo valida internamente
    {

        pNode=getNode(this,index);
        if(pNode != NULL)
        {
            pNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* pNode2;
    int size=ll_len(this);
    if(this != NULL && index>=0 && index<size)
    {
        if(index>0)
        {
            pNode=getNode(this,index);//obtendo el nodo que quiero eliminar
            pNode2=getNode(this,index-1);//obtengo el nodo anterios al que quiero eliminar
            pNode2->pNextNode=pNode->pNextNode;//ago que ese nodo anterios apunte al que apuntaba el nodo que estoy por elimnar
            free(pNode);//libero la memoria del nodo eliminado
            this->size--;//actualizo el tañano de la lista
            returnAux=0;// aclaro que todo salio piola
        }
        else if(index==0)
        {
            pNode=this->pFirstNode;//mi nodo es el primero
            this->pFirstNode=pNode->pNextNode;//hago que se apunte al segundo nodo y se lo toma como el primer nodo de la lista
            this->size--;//actualizo el tamaño de la lista
            free(pNode);//liobera la memoris del nodo eliminado
            returnAux=0;//devuelvo que todo esta bien
        }

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int size = ll_len(this);//busco el tamaño de la lista
    int i;
    if(this != NULL)//veo que la lista no sea NULL
    {

        for(i = 0; i < size; i++)//voy a barrer toda la lisra
        {
            ll_remove(this,i);// Elimino todos los elementos de la lista

            returnAux = 0;//devuelvo que todo salio re bien
        }

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)//vemos que la lista no sea nula
    {
        if(ll_clear(this)==0)//si todos los elementos de la lista ya fueron eliminados ......entonces:
        {
            free(this);//elimino la lista...osea elimino/ libero ese espacio de la memoria

            returnAux = 0;//todo salio re cheto
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
//mira en todo el linkend list si hay algun nodo que este apuntando al elemento seleccionado
//es como revisar si alguien te esta mirando...re perseguido xD
int ll_indexOf(LinkedList* this, void* pElement)
//entonces vemos que otro pElement sea igual para saber si alguien mas nos esta apuntando
{
    int returnAux = -1;
    int i;
    int tam = ll_len(this);//tamaño de la lista
    Node* pNode;//puntero a nodo
    if(this != NULL)//vemos que la lista no sea nula
    {
        for(i=0; i < tam; i++)//recorremos toda la lista
        {
            pNode=getNode(this,i);//buscamos o miramos los punteros de la lista
            if(pNode != NULL && pElement == pNode->pElement) //vemos si hay otro elemento apuntando a nuestro nodo
            {
                returnAux=i;//si encuentra a otro elemento apuntando entonces devolvemos el indice para saber quien mas esta apuntando :)
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)//puntero a la lista
{
    int returnAux = -1;
    int size = ll_len(this);//puntero a la lista
    if(this != NULL)//vemos que lista sea valida
    {
        if(size > 0)//si el tamaño de la lista es mato a cero entonces NO esta vacia
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;//Como no se cumple la ondicion del if --> la lista esta vacia
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int size=ll_len(this);//tamaño de la lista
    if(this != NULL && index >= 0 && index<=size)//puede poscisionarse tanto en el princi´pio como en elk final del linkedlist
    {
        if(addNode(this,index,pElement)==0 && this->size>size)
        {
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int size=ll_len(this);
    void* pElement=ll_get(this,index);
    if(this != NULL && index>=0 && index<size)
    {
        if(ll_remove(this,index)==0)
        {
            returnAux=pElement;
        }

    }
    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int size=ll_len(this);
    void* pElementAux;
    if(this!=NULL)
    {
        for(i=0; i<size; i++) //vemos toda la lista
        {
            pElementAux=ll_get(this,i);//vemos los punteros y los guardamos en eun aux
            if(pElementAux==pElement)//si alguno de ellos es igual al que estamos viendo si escite entonces
            {
                returnAux=1;//la funcion delvuelve 1...Lo cual quiere decir que el elemento existe en la lista
                break;//salimos para que ya no busque mas
            }
        }
        if(i==size)//si ya recorrimos todo un
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)//punteros a cada lista del tipo linkedlist
{
    int returnAux = -1;
    int i;
    int size=ll_len(this);//tamaño de la lista
    int size2=ll_len(this2);//tamaño de la lsita2
    void* pElement;//punteros a un elemto
    void* pElement2;//puntero a otro elemento
    int cantIguales=0;
    if(this != NULL && this2 != NULL)//vemos que ambas listas no sean NULL
    {
        for(i = 0; i < size; i++)//recorremos toda la primer lista
        {
            pElement = ll_get(this,i);//"contamos los elementos del la primer lista"
            pElement2 = ll_get(this2,i);//"contamoos" los elementos de la segunda lista
            if(pElement == pElement2)// ya cuando vemoas la cantida de elemento que tiene cada lista entonces los comparamos para ver sis sons iguales las cantidades y luego avanzamos con el IF
            {
                cantIguales++;//si son iguales las cantidades de elementos etonces almacenamos esa cantidad de elementos en otra variable...
            }
        }
        if(cantIguales == size  && size == size2) //tenemos que ver que las cantidades de elemntos sean iguales tanto entre listas como el tamañana contado anteriormente
        {
            returnAux = 1;// devolvemos 1, por lo tanto los elementos de la lista2 estan contenidos en la lista
        }
        else
        {
            returnAux = 0;//en caso contrario a lo anterior devuelve 0
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    void* pElement;
    int i;
    int size=ll_len(this);//tamaño de la lista


    if(this != NULL && from >=0 && from < size && to > from && to <= size)//arammos la condicion segun el enunciado-->Que el puntero sea distinto de NULL....el indice "from" empieze y sea mayor a cero
        //                                          pero que sea menor al tamaño de la lista y que el indice "to" sea mayor a "from" y tenga el limite
        //del tamaño de la lista
    {
        //si todo eso se cumple entonces:
        cloneArray = ll_newLinkedList();//creamos una nueva lista con los indices que ya validamos creamos un archivos lincked list en la memoria dinamica
        for(i = from; i < to; i++)
        {
            pElement = ll_get(this,i);
            if(ll_add(cloneArray,pElement) == 0)//si se agregaron los elementos con exito al nuevor linked list
            {
                continue;//entonces continuamos
            }
            else
            {
                free(cloneArray);//si no salio bien entonces eliminamos rl archivo del tipo lincked list
                cloneArray=NULL;//nos aseguramos de que no contenga nada
                break;
            }

        }
    }
    else
    {
        free(cloneArray);//si no se cimplen las condiciones de los indices o falla algo en lka condicion del if entonces borramos lo creado
        cloneArray=NULL;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    cloneArray = ll_newLinkedList();
    void* pElement;

    int i;

    int size = ll_len(this);
    if(this != NULL)

    {
        for(i = 0; i < size; i++)

        {
            pElement = ll_get(this,i);//toma los elemento que estan la lista
            if(ll_add(cloneArray,pElement) == 0)//si se creo con exito la nueva lista entonces le pasa los elemento copiados a cara de perro

            {
                continue;
            }

            else
            {
                free(cloneArray);//de lo contrario elimina la lista creada
                cloneArray=NULL;
                break;
            }

        }
    }
    else
    {
        free(cloneArray);//elimina la lista si es que el ppuntero a la lista de donde se va a copiar tira NULL
        cloneArray=NULL;
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int size = ll_len(this);
    int i;
    int j;
    void* aux;
    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {

        for(i = 0; i < size; i++)
        {
            for(j = i+1; j < size; j++)
            {
                if(pFunc(ll_get(this, i), ll_get(this,j)) > 0 && order == 1) //me devolvera 1, 0 o -1 depende de esto vamos a ordenar
                {
                    aux = ll_get(this,i);
                    ll_set(this,i, ll_get(this,j));
                    ll_set(this, j, aux);
                }
                else if(pFunc(ll_get(this, i), ll_get(this,j)) < 0 && order == 0)  //me devolvera 1, 0 o -1 depende de esto vamos a ordenar
                {
                    aux = ll_get(this,i);
                    ll_set(this,i, ll_get(this,j));
                    ll_set(this, j, aux);




                }
            }

        }
        returnAux = 0;



    }



    return returnAux;


}

