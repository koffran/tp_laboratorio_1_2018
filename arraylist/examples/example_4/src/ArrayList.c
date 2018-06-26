#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"

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
    void* pElements;
    this = (ArrayList*)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;

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
            returnAux = this;
        }
        else
        {
            free(this);
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
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int flag;

    if (this!=NULL && pElement!=NULL)
    {
        if (resizeUp(this)==0)
        {
            flag =1;
        }
        else
        {
            flag = 0;
        }

        if (flag)
        {
            this->pElements[this->size]=pElement;
            this->size++;
            returnAux = 0;
        }
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

    if (this != NULL)
    {
        free(this->pElements);

        returnAux =0;
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

    if (this !=NULL)
    {
        returnAux = this->size;
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

    if (this!= NULL && (index > -1 && index < this->size))
    {
        returnAux = this->pElements[index];
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

    if (this != NULL && pElement != NULL)
    {
        for (i=0;i<al_len(this);i++)
        {
            if (this->pElements[i] == pElement)
            {
                returnAux = 1;
                break;
            }
            returnAux =0;
        }
    }
    return returnAux;
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

    if (this != NULL && pElement != NULL && (index>= 0 && index< this->size))
    {
        this->pElements[index] = pElement;
        returnAux = 0;
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

    if (this != NULL && (index > -1 && index < this->size))
    {
        contract(this, index);

        returnAux = 0;
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
    int i;
    if (this!= NULL)
    {
         for (i=0;i<this->size;i++)
    {
        contract(this,i);
        this->size = 0;
        returnAux= 0;
    }
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
    ArrayList* clon = NULL;
    void* pElementClon;
    int i;

    if (this != NULL)
    {
        clon = al_newArrayList();
        if (clon !=NULL)
        {
            for (i=0;i<al_len(this);i++)
            {
                pElementClon = al_get(this,i);
                al_add(clon,pElementClon);
            }
            if(this->size == clon->size)
            {
                returnAux = clon;
            }
        }
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

    if (this != NULL && pElement !=NULL && (index >-1 && index < this->size))
    {
       if (expand(this,index)==0)
       {
           this->pElements[index] = pElement;
           this->size++;
           returnAux = 0;
       }
    }
    else
        if (index == this->size)
    {
        if (al_add(this,pElement)==0)
        {
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

    if (this !=NULL && pElement != NULL)
    {
        if (al_isEmpty(this)==0)
        {
            for (i=0;i<al_len(this);i++)
            {
                if (this->pElements[i]== pElement)
                {
                    returnAux = i;
                }
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
    if (this !=NULL)
    {
        if (this->size == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux=0;
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

    if (this != NULL && (index>-1 && index<this->size))
    {
        if (al_isEmpty(this)==0)
        {
            returnAux = al_get(this,index);

            if (al_remove(this,index)== -1)
            {
                returnAux == NULL;
            }
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
    void* subElement;
    ArrayList*  subList;

    int i;

    if (this!=NULL && (from>-1&&from <= to)&&to<=this->size)
    {
        subList = al_newArrayList();
        if (subList !=NULL)
        {
            for (i=from;i<to;i++)
            {
                subElement = al_get(this,i);
                al_add(subList,subElement);
            }
            if (al_isEmpty(subList)==0)
            {
                return subList;
            }

        }
    }
    else
    {
        return returnAux ;
    }

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
    int i,j;
    int contador=0;

    if(this != NULL && this2 != NULL)
    {
        for(i=0;i<this->size;i++)
        {
            for(j=0; j<this2->size; j++)
            {
                if(this2->pElements[i] == this->pElements[j])
                {
                    contador++;
                }
            }
        }
        if(contador == this2->size)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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
    int i, j, aux;
    void* auxThis;

    if(this != NULL && pFunc != NULL && order > -1 && order < 2)
    {
        for(i=0;i<al_len(this)-1;i++)
        {
            for(j=i+1;j<al_len(this);j++)
            {
                aux = pFunc(this->pElements[i],this->pElements[j]);
                switch(aux)
                {
                    case -1:
                        if(order == 0)
                        {
                            auxThis = this->pElements[j];
                            this->pElements[j] = this->pElements[i];
                            this->pElements[i] = auxThis;
                        }
                        else
                        {
                            continue;
                        }
                        break;
                    case 0:
                        continue;
                        break;
                    case 1:
                        if(order == 1)
                        {
                            auxThis = this->pElements[j];
                            this->pElements[j] = this->pElements[i];
                            this->pElements[i] = auxThis;
                        }
                        break;
                }
            }
        }
        returnAux = 0;
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
    void** auxList;
    if (this!=NULL )
    {
        if (this->size == this->reservedSize)
        {
            auxList = (void**) realloc(this->pElements, sizeof(void*) * (this->size+AL_INCREMENT));
            if (auxList != NULL)
            {
                this->reservedSize = this->size+AL_INCREMENT;
                this->pElements = auxList;

                returnAux = 0;
            }
        }
        else
        {
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
    int i;

    if (this != NULL && (index >-1 && index < this->size))
    {
        if(resizeUp(this)==0)
        {
            for (i=(al_len(this)-1); i>=index;i--)
            {
                this->pElements[i+1]= this->pElements[i];
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
    int i;

    if (this != NULL && (index> -1 && index <this->size))
    {
        for (i=index; i < this->size;i++)
        {
            this->pElements[i] = this->pElements[i+1];
        }
        this->size--;

        returnAux =0;
    }

    return returnAux;
}
