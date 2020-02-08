#include<stdio.h>
#include<stdlib.h>
#include"List.h"

typedef struct NodeObj
{
	int data;
	struct NodeObj* next;
	struct NodeObj* prev;
}NodeObj;

typedef NodeObj * Node;

typedef struct ListObj
{
	//int data;
	Node front;
	Node back;
	Node cursorElement;
	int cIndex;
	int length;
	
} ListObj;

typedef ListObj* List;



List newList(void) // Creates and returns a new empty List.
{
	List nList = malloc(sizeof(ListObj));
	nList->front = NULL;
	nList->back = NULL;
	nList->cursorElement = NULL;
	nList->cIndex = -1;
	nList->length = 0;
	return nList;
}
//creates and returns a new emptyNode
Node newNode(int newData)
{
	Node nNode = malloc(sizeof(NodeObj));
	nNode->data = newData;
	nNode->next = NULL;
	nNode->prev = NULL;
	return nNode;
}

//frees the list
void freeList(List* pL)//Frees all heap memory associated with *pL, and sets*pL to NULL.
{
	if( pL != NULL && *pL!=NULL)
	{
			free(*pL);
			*pL = NULL;
			//printf("check");
	}
}

int length(List L) // Returns the number of elements in L.
{
	if(L == NULL)
	{
		fprintf(stderr,"Queue Error: calling getLength() on NULL Queue reference\n");
		exit(1);
	}
	return(L->length);
}

int index(List L) // Returns index of cursor element if defined, -1 otherwise.
{
	if(L == NULL || L->cIndex == -1)
	{
		return -1;
	}
	return L->cIndex;
}

int front(List L) // Returns front element of L. Pre: length()>0
{
	if(L->length <= 0 || L == NULL)
	{
		fprintf(stderr, "L is empty\n");
		exit(1);
	}
	return L->front->data;
}

int back(List L) // Returns back element of L. Pre: length()>0
{
	if(L->length == 0 || L == NULL)
	{
		fprintf(stderr, "L is empty and contains no back\n");
		exit(1);
	}
	return L->back->data;
}
int get(List L) // Returns cursor element of L. Pre: length()>0, index()>=0
{
	if(L == NULL)
	{
		fprintf(stderr, "The Cursor Element is NOT initiated when called in get()\n");
		exit(1);
	}
	if(L->cIndex < 0)
	{
		fprintf(stderr, "The cIndex is undefined when called in get()\n");
		exit(1);
	}
	if(L->length < 0)
	{
		fprintf(stderr, "The List is empty when called in get()\n");
		exit(1);
	}
	return L->cursorElement->data;
}
int equals(List A, List B) // Returns true (1) iff Lists A and B are in same state, and returns false (0) otherwise.
{
	if(A->length != B->length)
	{
		return 0;
	}
	//if(A->cIndex != B->cIndex)
	//{
		//return 0;
	
	if(A->length == B->length)
	{
		moveFront(A);
		moveFront(B);
		for(int i = 0; i<A->length; i++)
		{
			if(A->cursorElement->data != B->cursorElement->data)
			{
				return 0;
			}
			if(A->cursorElement->next != NULL)
			{
				A->cursorElement= A->cursorElement->next;
			}
			if(B->cursorElement->next != NULL)
			{
				B->cursorElement= B->cursorElement->next;
			}
			if(i == A->length - 1)
			{
				return 1;
			}
		}
		
	}else
	{
		return 0;
	}
	return 1;
}
void clear(List L) // Resets L to its original empty state.
{
	if(L->length != 0)
	{
		while(L->front->next != NULL)
		{
		 deleteFront(L);
		}
		deleteFront(L);
	}
	L->front = NULL;
	L->back = NULL;
	L->cursorElement = NULL;
	L->cIndex = -1;
	L->length = 0;
}
void moveFront(List L) // If L is non-empty, sets cursor under the front element,otherwise does nothing.
{
	if(L == NULL)
	{
		fprintf(stderr,"The List inputed in moveFront is NULL");
		exit(1);
	}
	if(L->length != 0)
	{
		L->cIndex = 0;
		L->cursorElement = L->front;
	}
}
void moveBack(List L) // If L is non-empty, sets cursor under the back element,otherwise does nothing.
{
	if(L == NULL)
	{
		fprintf(stderr,"The List inputed in moveBack is NULL");
		exit(1);
	}
	L->cIndex = L->length - 1;
	L->cursorElement = L->back;
}
void movePrev(List L) // If cursor is defined and not at front, move cursor onestep toward the front of L; if cursor is defined and atfront, cursor becomes undefined; if cursor is undefineddo nothing
{
	if(L == NULL)
	{
		fprintf(stderr,"The List inputed in movePrev is NULL");
		exit(1);
	}
	if(L->length == 0)
	{
		fprintf(stderr, "The  List inputed in movePrev is empty");
		exit(1);
	}
	if(L->cIndex != -1)
	{
		L->cursorElement = L->cursorElement->prev;
		L->cIndex = L->cIndex - 1;
	}
	
}
void moveNext(List L) // If cursor is defined and not at back, move cursor onestep toward the back of L; if cursor is defined and atback, cursor becomes undefined; if cursor is undefineddo nothing
{

	if(L == NULL)
	{
		fprintf(stderr,"The List inputed in moveNextis NULL");
		exit(1);
	}
	//if(L->cIndex == -1)
	//{
		//fprintf(stderr, "The  List inputed in moveNext has an undefined cursor");
		//exit(1);
	//}
	if(L->cursorElement!=NULL)
	{
	if(L->cursorElement != L->back)
	{
		//
			L->cursorElement = L->cursorElement->next;
			L->cIndex = L->cIndex + 1;
	}else
	{
		L->cIndex = -1;
		L->cursorElement = NULL;
	}
	}
	//if(L->cursorElement->next != NULL && L->cIndex != -1)
	//{

	//}
	
	
	
}

void append(List L, int data)// Insert new element into L. If L is non-empty,// insertion takes place after back element.
{
	
	if(L == NULL)
	{
		fprintf(stderr,"The List inputed in append is NULL");
		exit(1);
	}
	Node tNode = newNode(data);
	if(L->front == NULL)
	{
		//L->cursorElement = tNode;
		L->front = tNode;
		L->back = tNode;
		L->length += 1;
		//L->cIndex = 1;
	}
	else
	{
	tNode->prev = L->back;
	L->back->next = tNode;
	tNode->next = NULL;
	L->back = tNode;
	L->length = L->length + 1;
	}

	
} 

void prepend(List L, int data) // Insert new element into L. If L is non-empty,insertion //takes place before front element.
{
	if(L == NULL)
	{
		fprintf(stderr,"The List inputed into prepend is NULL");
		exit(1);
	}
	Node tNode = newNode(data);
	if(L->front == NULL)
	{
		//L->cursorElement = tNode;
		L->front = tNode;
		L->back = tNode;
		L->length = 1;
	}
	else
	{
		tNode->next = L->front;
		L->front->prev = tNode;
		tNode->prev = NULL;
		L->front = tNode;
		L->length = L->length + 1;
		
		if(L->cursorElement != NULL)
		{
		L->cIndex = L->cIndex + 1;
		}
	}
	
	
}

void insertAfter(List L, int data) // Insert new element after cursor.
 // Pre: length()>0, index()>=0
{
	if(L == NULL)
	{
		fprintf(stderr,"The List inputed in insertAfter is NULL");
		exit(1);
	}
	if(L->cIndex < 0)
	{
		fprintf(stderr,"The List inputed in insertAfter has a cursor index at -1 off the list");
		exit(1);
	}
	Node tNode = newNode(data);
	if(L->cursorElement != L->back)
	{
		L->cursorElement->next->prev = tNode;
	}
	tNode->next = L->cursorElement->next;
	L->cursorElement->next = tNode;
	tNode->prev = L->cursorElement;
	if(tNode->next == NULL)
	{
		L->back = tNode;
	}
	//L->cIndex += 1;
	
	L->length += 1;
}
void insertBefore(List L, int data) // Insert new element before cursor.// Pre: length()>0, index()>=0
{
	if(L == NULL)
	{
		fprintf(stderr,"The List inputed in insertBefore is NULL");
		exit(1);
	}
	if(L->cIndex < 0)
	{
		fprintf(stderr,"The List inputed in insertBefore has a cursor index at -1 off the list");
		exit(1);
	}
	Node tNode = newNode(data);
	tNode->next = L->cursorElement;
	tNode->prev = L->cursorElement->prev;
	if(L->front != L->cursorElement)
	{
		L->cursorElement->prev->next = tNode;
		//tNode->prev = L->cursorElement->prev;
	}
	else
	{
		L->front = tNode;
	}
	L->cursorElement->prev = tNode;
	L->cIndex += 1;
	L->length += 1;
	
}
void deleteFront(List L) // Delete the front element. Pre: length()>0
{
	if(L == NULL)
	{
		fprintf(stderr, "The List you called deleteFront on is NULL");
		exit(1);
	}
	if(L->length == 0)
	{
		fprintf(stderr, "The List you called deleteFront on is empty");
		exit(1);
	}
	if(L->front->next != NULL)
	{
		L->front = L->front->next;
		free(L->front->prev);
		L->front->prev = NULL;
		if(L->cIndex == 0)
		{
			L->cursorElement = NULL;
		}
	}
	else
	{
		free(L->front);
		L->front=NULL;
		L->back=NULL;
	}
	L->length -= 1;
	L->cIndex -= 1;
}
void deleteBack(List L) // Delete the back element. Pre: length()>0
{
	if(L == NULL)
	{
		fprintf(stderr, "The List you called deleteBack on is NULL");
		exit(1);
	}
	if(L->length == 0)
	{
		fprintf(stderr, "The List you called deleteBack on is empty");
		exit(1);
	}
	
	if(L->back->prev != NULL)
	{
		L->back = L->back->prev;
		free(L->back->next);
		L->back->next = NULL;
	}
	else
	{
		free(L->back);
		L->front=NULL;
		L->back=NULL;
		L->cursorElement = NULL;
	}
	if(L->cIndex == L->length-1)
	{
		L->cIndex = -1;
	}
	L->length -= 1;
}
void delete(List L) // Delete cursor element, making cursor undefined.
{
	if(L == NULL)
	{
		fprintf(stderr, "The List you called delete on is NULL");
		exit(1);
	}
	if(L->cIndex == -1)
	{
		fprintf(stderr, "The List you called delete on is empty or cursor is undefined");
		exit(1);
	}
	//add ifs and to prevent Null exceptions
	if(L->cursorElement->prev != NULL && L->cursorElement->next != NULL)
	{
		L->cursorElement->prev->next = L->cursorElement->next;
		L->cursorElement->next->prev = L->cursorElement->prev;
		free(L->cursorElement);
		L->cursorElement  = NULL;
	}
	else if(L->cursorElement->prev == NULL && L->cursorElement->next != NULL)
	{
		L->cursorElement->next->prev = NULL;
		L->front = L->cursorElement->next;
		free(L->cursorElement);
		L->cursorElement  = NULL;
	}
	else if (L->cursorElement->prev != NULL && L->cursorElement->next == NULL)
	{
		(L->cursorElement->prev->next = NULL);
		L->back =L->cursorElement->prev;
		free(L->cursorElement);
		L->cursorElement  = NULL;
	}
	else
	{
		free(L->cursorElement);
		L->cursorElement = NULL;
		L->front = NULL;
		L->back = NULL;
	}
	L->length = L->length-1;
	L->cIndex = -1;
}
void printList(FILE* out, List L) // Prints to the file pointed to by out, a// string representation of L consisting// of a space separated sequence of integers,// with front on left.
{
	Node N = NULL;
	if(L == NULL)
	{
		fprintf(stderr, "List inputed into printList is NULL\n");
		exit(1);
	}
	for(N = L->front; N != NULL; N = N->next)
	{
		fprintf(out,"%d ", N->data);
	}
	free(N);
}
List copyList(List L) // Returns a new List representing the same integer// sequence as L. The cursor in the new list is undefined,// regardless of the state of the cursor in L. The state// of L is unchanged.
{
	if(L == NULL)
	{
		fprintf(stderr, "The List you called deleteB on is NULL");
		exit(1);
	}
	
	List nList = newList();
	Node hotN = NULL;
	hotN = L->front;
	
	while(hotN != NULL)
	{
		append(nList,hotN->data);
		hotN = hotN->next;
	}
	
	return nList;
	
}




