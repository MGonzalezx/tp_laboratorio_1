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
    LinkedList* this = NULL;
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
	if(this != NULL)
	{
		returnAux = this->size;
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
	Node* pNode = NULL;
	int contador = 0;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;
		while(contador < nodeIndex)
		{
			contador++;
			pNode = pNode->pNextNode;
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
	Node* pNode = NULL;
	Node* pAuxPreviousNode = NULL;
	Node* pAuxNextNode = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		pNode = (Node *)malloc(sizeof(Node));
		if(pNode != NULL)
		{
			pNode->pElement = pElement;
			if(nodeIndex == 0)
			{
				pAuxPreviousNode = getNode(this, nodeIndex);
				this->pFirstNode = pNode;
				pNode->pNextNode = pAuxPreviousNode;
			} else
			{
				pAuxPreviousNode = getNode(this, (nodeIndex - 1));
				pAuxNextNode = pAuxPreviousNode->pNextNode;
				pAuxPreviousNode->pNextNode = pNode;
				pNode->pNextNode = pAuxNextNode;
			}
			this->size++;
			returnAux = 0;
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
	int indice;
	if(this != NULL)
	{
		indice = ll_len(this);
		if(indice >= 0)
		{
			if((addNode(this, indice, pElement)) == 0)
			{
				returnAux = 0;
			}
		}
	}
	return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	 void* returnAux = NULL;
	Node* pNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		//Obtenemos el nodo que estamos buscando
		pNode = getNode(this, index);
		//Se lo asignamos a returnAux por que devuelve el node si esta correctamente
		returnAux = pNode ->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
	Node* pNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		//Obtenemos el elemento que queremos modificar
		pNode = getNode(this, index);
		//Asignamos el elemento obtenido a pElement. Cambiamos pElement
		pNode ->pElement = pElement;
		returnAux = 0;
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
	Node* pNode = NULL;
	Node* pNodeAnterior = NULL;
	Node* pNodeSiguiente = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		//El indice que va a ser borrado
		pNode = getNode(this, index);

		//Como en el addNode recorremos en los casos que pueda ocurrir esto.
		//En el caso que el elemento esté en el indice 0
		if(index == 0)
		{
			//Conseguimos el elemento siguiente al que vamos a borrar.
			pNodeSiguiente = getNode(this, index+1);
			//Le asignamos el firstNode al node siguiente ya que el primero no esta más.
			this->pFirstNode = pNodeSiguiente;
		}
		//En el caso que el elemento este en el medio de otros dos
		else
		{
			//Llamamos a los dos elementos, el anterior y siguiente al elemento que vamos a borrar
			pNodeAnterior = getNode(this, index-1);
			pNodeSiguiente = getNode(this, index+1);
			//Los unimos ya que el del medio fue eliminado,
			pNodeAnterior->pNextNode = pNodeSiguiente;


		}
		//Se libera el espacio de pNode
		free(pNode);
		//Se achica el size, ya que un elemento fue eliminado
		this->size = this->size - 1;
		returnAux = 0;

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
	//int longitud;
	int i;
	int remove;
	if(this != NULL)
	{
		//Primero consigo la longitud de la lista.
		//longitud = ll_len(this);
		for(i = 0; i<ll_len(this); i++)
		{
			//Por cada i con un limite que es la longitud de la lista, va a borrar los elementos
			remove = ll_remove(this, i);
			//Lo que devuelve remove es 0 o -1. Si no devuelve 0, significa que hubo un error,
			//Osea que en este caso nos genera un error
			if(remove != 0)
			{
				returnAux = -1;
			}
		}

		returnAux = 0;
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
	int borrar;
	if(this != NULL)
	{
		//Borramos todos los elementos de la lista
		borrar = ll_clear(this);
		//Si borramos exitosamente todos los elementos, entonces continuamos a borrar la lista.
		if(borrar == 0)
		{
			free(this);
			returnAux = 0;
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
int ll_indexOf(LinkedList* this, void* pElement)
{
	//Nos pide que busquemos el indice del elemento que nos va a pasar
	int returnAux = -1;
	//Node* pNode = NULL;
	int i;
	if(this != NULL)
	{
		//Pasamos por toda la lista hasta que encontremos un elemento igual al que pide.
		for(i=0; i<ll_len(this); i++)
		{
			//pNode = getNode(this,i);
			//pNode->pElement = ll_get(this, i);
			if(ll_get(this, i) == pElement)
			{
				//Nos pide que devolvamos el indice del elemento.
				returnAux = i;
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
int ll_isEmpty(LinkedList* this)
{
	int returnAux = -1;

	    if(this != NULL)
	    {
	    	returnAux = 0;
	        if(ll_len(this) == 0)
	        {
	            returnAux = 1;
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
	if(this != NULL && index >= 0 && index <= ll_len(this))
	{
		addNode(this, index, pElement);
		returnAux = 0;
	}

	return returnAux;
}


/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
de la lista.
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
	//Node* pNode = NULL;
	if(this != NULL && index >= 0 && index <= ll_len(this))
	{
		//Primero tenemos que conseguir el elemento a eliminar
		//pNode = getNode(this, index);
		//Acordate que getNode devuelce NULL si esta mal y !=NULL si esta bien
		if(ll_get(this, index) != NULL)
		{
			//Ahora el elemento que vamos a devolver devuelve el puntero
			returnAux = ll_get(this, index);
			ll_remove(this, index);
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
	int index;
	if(this != NULL)
	{
		index = ll_indexOf(this, pElement);
		//El indice tiene que que ser mayor o igual a 0
		returnAux = 0;
		if( index > -1)
		{
			returnAux = 1;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int index;
	//Node* pNode = NULL;
	if(this != NULL && this2 != NULL)
	{
		returnAux = 1;
		for(index = 0; index < ll_len(this2); index++)
		{
			//Conseguimos todos los elementos de la lista 2 para luego comparar los elementos pNode con la lista 1
			//pNode = getNode(this2, index);
			//Mientras va agarrando los elementos de la lista 2, los compara.
			//Si la lista 1 contiene este elemento, con este elementos nos referimos a la que conseguimos de la lista 2
			if(ll_contains(this, ll_get(this2, index)) == 0)
			{
				returnAux = 0;
				break;
			}
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
	//Node* pNode = NULL;
	int i;
	if(this != NULL && from >= 0 && to > from && to <= ll_len(this))
	{

		cloneArray = ll_newLinkedList();
		//Desde el numero que indicamos hasta donde queremos llegar
		for(i=from; i<to; i++)
		{
			//Conseguimos los elementos que queremos poner
			//pNode = getNode(this, i);
			//Ponemos los elementos
			ll_add(cloneArray, ll_get(this, i));
		}
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
	if(this != NULL)
	{
		//Se va a clonar la lista, se hace otra, copiandose los datos desde la posicion 1 hasta la longitud de la lista.
		cloneArray = ll_subList(this, 0, ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	Node* pNode = NULL;
	Node* pNodeDos = NULL;
	void* pElementAuxiliar = NULL;
	int index;
	int i;
	if(this != NULL && (order == 0 || order == 1) && ll_len(this) > 1 && (*pFunc) != NULL)
	{
		if(order == 0)
		{
			for(index = 0; index < ll_len(this) -1 ; index++)
			{
				pNode = getNode(this, index);
				if(pNode->pElement == NULL)
				{
					continue;
				}
				for(i = index + 1; i < ll_len(this); i++)
				{
					pNodeDos = getNode(this, i);
					if(pNodeDos->pElement == NULL)
					{
						continue;
					}
					if((*pFunc)(pNode->pElement, pNodeDos->pElement) == -1)
					{
						pElementAuxiliar = pNode->pElement;
						pNode->pElement = pNodeDos->pElement;
						pNodeDos->pElement = pElementAuxiliar;
					}
				}
			}
			returnAux = 0;
		}

		if(order == 1)
		{
			for(index = 0; index < ll_len(this)-1; index++)
			{
				pNode = getNode(this, index);
				if(pNode->pElement == NULL)
				{
					continue;
				}
				for(i = index + 1; i < ll_len(this); i++)
				{
					pNodeDos = getNode(this, i);
					if(pNodeDos->pElement == NULL)
					{
						continue;
					}
					if((*pFunc)(pNode->pElement, pNodeDos->pElement) == 1)
					{
						pElementAuxiliar = pNode->pElement;
						pNode->pElement = pNodeDos->pElement;
						pNodeDos->pElement = pElementAuxiliar;
					}
				}
			}
			returnAux = 0;
		}
	}
	return returnAux;

}

