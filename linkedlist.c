#include <stdlib.h>
#include "linkedlist.h"

// 需要head指针的原因是，万一该链表是空链表，则添加节点既是添加在last也是添加在first，addFirst函数同理
void addLast(void * pData, struct element ** pHead, struct element ** pTail)
{
	struct element * pNewElement = (struct element *) malloc (sizeof(struct element));
	pNewElement->pData = pData;
	pNewElement->pNext = NULL;
	
	if((*pHead) == NULL)
	{
		pNewElement->pNext = (*pHead);	// pNewElement->pNext = NULL
		(*pTail) = (*pHead) = pNewElement;
	}
	else 
	{
		pNewElement->pNext = NULL;
		(*pTail)->pNext = pNewElement;
		(*pTail) = pNewElement;
	}
}

// 同上
void addFirst(void * pData, struct element ** pHead, struct element ** pTail)
{
	struct element * pNewElement = (struct element *) malloc (sizeof(struct element));
	pNewElement->pData = pData;
	pNewElement->pNext = NULL;
	
	if((*pHead) == NULL)
	{
		pNewElement->pNext = (*pHead);	// pNewElement->pNext = NULL
		(*pTail) = (*pHead) = pNewElement;
	}
	else 
	{
		pNewElement->pNext = (*pHead);
		(*pHead) = pNewElement;
	}
}

// return the data in the removed node
void * removeFirst(struct element ** pHead, struct element ** pTail)
{
	void * pData = NULL;
	struct element * pTemp = NULL;
	if((*pHead) != NULL)
	{
		pTemp = (*pHead);	// 用来free
		(*pHead) = (*pHead)->pNext;
		if((*pHead) == NULL)
			(*pTail) = NULL;
		pData =  pTemp->pData;
		free(pTemp);
	}
	return pData;
}
