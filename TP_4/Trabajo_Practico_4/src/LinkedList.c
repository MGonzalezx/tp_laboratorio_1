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
	int cont = 0;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;
		while(cont < nodeIndex)
		{
			cont++;
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
	if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
		pNode = (Node *)malloc(sizeof(Node));
		if(pNode != NULL)
		{
			pNode->pElement = pElement; //le asignamos el elemento a agregar a pNode.
			if (nodeIndex==0)//Si el index es igual a cero es decir que es locomotora del tren
			{
				pNode->pNextNode = this->pFirstNode;//el siguiente nodo es va a hacer el anteriorprimer nodo
				this->pFirstNode = pNode;//Y el primero nodo es el nuevo nodo creado
			}
			else
			{
				pAuxPreviousNode=getNode(this,nodeIndex-1);
				pNode->pNextNode = pAuxPreviousNode->pNextNode; // el siguiente del node nuevo va a ser el siguiente del anterior
				pAuxPreviousNode->pNextNode = pNode; // el nuevo siguiente del anterior va a ser el nuevo node
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
		if(indice > -1)
		{
			if((addNode(this, indice, pElement)) == 0)
			{
				returnAux = 0;
			}
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
	void* returnAux = NULL;
	Node* pAuxNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		pAuxNode = getNode(this, index);
		if(pAuxNode != NULL)
		{
			returnAux = pAuxNode->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
	Node* pAuxNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		pAuxNode = getNode(this, index);
		if(pAuxNode != NULL)
		{
			pAuxNode->pElement = pElement;
			returnAux = 0;
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
	Node* pNodeAux= NULL;
	Node* pNode= NULL;

	if(this != NULL && index>=0 && index < ll_len(this))
	{


		 if(index == 0)//Si el elemento del nodo que se quiere eliminar es el de la locomotora el index tiene que ser igual a cero
		{
			pNode = getNode(this, index);
			this->pFirstNode = pNode->pNextNode;
			free(pNode);
		}

		else//Si el elemento del nodo que se quiere eliminar no esta al principio ni al final es distinto al largo y distinto a 0
		{
			pNodeAux = getNode(this,(index-1));
			pNode = getNode(this,index);
			pNodeAux->pNextNode = pNode->pNextNode;
			free(pNode);
		}

		this->size--;//Se reduce la lista una vez eliminado el nodo
		returnAux=0;//Si esta todo Ok cambio el retorno a 0
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
	int i;
	if(this != NULL)
	{
		//La variable i tiene que ser igual al tamaño de la lista ya que tiene que recorrer de atras para adelante
		//Una vez que valga cero deja de recorre, por eso la condicion "i" tiene que ser mayor o igual a 0
		for(i=ll_len(this); i>=0; i--)//Recorro de atras para adelante porque si borro el primero pierdo la direccion del segundo nodo
		{
			ll_remove(this, i);
		}

		returnAux=0;//Si esta todo Ok cambio el valor del retorno
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
	    if(this != NULL)
	    {
	        if(ll_clear(this) == 0)
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
	int returnAux = -1;
	Node* pAuxNode = NULL;
	int indice;
	if(this != NULL)
	{
		for(indice = 0; indice < ll_len(this); indice++)
		{
			pAuxNode = ll_get(this, indice);
			if(pAuxNode == pElement)
			{
				returnAux = indice;
				break;
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
		if(this->size == 0)
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
		if(addNode(this, index, pElement) == 0)
		{
			returnAux = 0;
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
	Node* pAuxNode = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		pAuxNode = ll_get(this, index);
		if(pAuxNode != NULL)
		{
			returnAux = pAuxNode;
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

	if(this != NULL )
	{
		returnAux = 0;
		index = ll_indexOf(this, pElement);


		if(index != -1)
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
	void* auxElementoDos = NULL;
	int auxThis;

	if(this != NULL &&  this2 != NULL)
	{
		returnAux=1;

		for(int i=0; i<ll_len(this2); i++)//Recorro la lista 2
		{
			auxElementoDos = ll_get(this2, i);
			auxThis=ll_contains(this, auxElementoDos);//Verifica si los elementos estan en la lista 1


			if(auxThis == 0)
			{
				returnAux=0;
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
	void* pAuxiliar = NULL;

	if( (this!=NULL) && (from>=0) && (from<this->size) && (to>0) && (to<=this->size) && (from<to) )
	{
		cloneArray= ll_newLinkedList();//Creo un nuevo linkesList para clonar la lista

		if(cloneArray!=NULL)
		{
			for(int i=from; i<to ; i++)
			{
				pAuxiliar = ll_get(this, i);
				ll_add(cloneArray,pAuxiliar);
			}
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

	int returnAux = -1;
	void* pElementA = NULL;
	void* pElementB = NULL;
	void* pAuxiliar = NULL;

	if(this != NULL && pFunc != NULL && (order == 1 || order ==0))
	{
		for(int i=0; i<ll_len(this)-1; i++)
		{
			pElementA = ll_get(this, i); //Obtengo el elemento de la posicion i

			for(int j=i+1; j<ll_len(this); j++)
			{
				pElementB = ll_get(this, j); //Obtengo el elemento de la posicion j

				if((order == 0 && pFunc(pElementA, pElementB) == -1) || (order == 1 && pFunc(pElementA, pElementB) == 1))
				{

						//Realizo metodo de borbujeo
						pAuxiliar = pElementB;
						pElementB = pElementA;
						pElementA = pAuxiliar;

				}

				//modifico el pElementA y pElementB
				ll_set(this, i, pElementA);
										ll_set(this, j, pElementB);
			}
		}
		returnAux = 0;
	}
	return returnAux;

}

