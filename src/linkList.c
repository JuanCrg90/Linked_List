#include "include/linklist.h"
//#include "../include/linklist.h"

List *initializeList()
{
    List *L;
    L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->size = 0;

    return L;
}


Node* createNode(void *d)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->data = malloc(sizeof(void*));
    p->data = d;
    p->nodeNext = NULL;
    return p;
}

void freeNode(Node *n)
{
    free(n);
}

int isEmpty(List *L)
{
    if(L->head == NULL) //Empty
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



void insertBegin(List *L, void *d)
{
    Node *n;
    n=createNode(d);
    n->nodeNext=L->head;
    L->head=n;
    L->size++;
}

void insertEnd(List *L,void *d)
{
    Node *aux = L->head;

    if(aux==NULL)
    {
        insertBegin(L,d);
    }
    else
    {
        while(aux->nodeNext!=NULL)
        {

            aux=aux->nodeNext;
        }
        aux->nodeNext=createNode(d);;
        L->size++;
    }


}

void insertPos(List *L,void *d,int pos)
{
    Node *aux = L->head;
    Node *aux2;

    int i = 0;

    if(pos==0)
    {
        insertBegin(L,d);
    }
    else
    {
        while(i<pos-1 && aux->nodeNext!=NULL )
        {
            aux = aux->nodeNext;
            i++;
        }
        aux2=createNode(d);
        aux2->nodeNext=aux->nodeNext;
        aux->nodeNext=aux2;
        L->size++;
    }


}

Node* searchByPos(List *L,int pos)
{
    Node *aux = L->head;
    int i = 0;

    if(pos < 0 || pos > (L->size-1))
    {
        return NULL;
    }
    else
    {
        while(i != pos)
        {
            aux = aux->nodeNext;
            i++;
        }
    }
    return aux;
}

int deleteNodeByPos(List *L,int pos)
{
    Node *aux = L->head;
    Node *prev=NULL;
    int i = 0;

    if(pos < 0 || pos > (L->size-1))
    {
        return FALSE;
    }
    else
    {
        if(pos == 0)
        {
            L->head=L->head->nodeNext;
        }
        else
        {
            do
            {
                prev = aux;
                aux = aux->nodeNext;
                i++;
            }while(i<pos);

            prev->nodeNext=aux->nodeNext;

        }
    }

    freeNode(aux);
    L->size--;

    return TRUE;

}

void destroyList(List *L)
{
    while(!isEmpty(L))
    {
        deleteNodeByPos(L,0);
    }

}



