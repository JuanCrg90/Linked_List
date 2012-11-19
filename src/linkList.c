#include "include/linklist.h"

List initializeList(List *L)
{
    L->head=NULL;
    L->size=0;
    return *L;


}


Node* CreateNode(mytype *d)
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->data=(mytype*)malloc(sizeof(mytype));
    p->data=d;
    p->nodeNext=NULL;
    return p;
}


void insertBegin(List *L,mytype *d)
{
    Node *n;
    n=CreateNode(d);
    n->nodeNext=L->head;
    L->head=n;
    L->size++;
}


void insertEnd(List *L,mytype *d)
{
    Node *n;
    n=L->head;

    if(n==NULL)
    {
        L->head=CreateNode(d);
        L->size++;
    }
    else
    {
        while(n->nodeNext!=NULL)
        {
            n=n->nodeNext;
        }
        n->nodeNext=CreateNode(d);

        L->size++;
    }
}

void insertPos(List *L,mytype *d,int pos)
{
    Node *n,*aux;
    int i=1;
    n=L->head;

    if(pos==1)
    {
        insertBegin(L,d);
        return;
    }
    while(i!=pos-1)
    {
        n=n->nodeNext;
        if(n->nodeNext==NULL)
        {
            printf("The position is out of range the node will be inserted at the end of the list\n");
            insertEnd(L,d);
            return;

        }
        i++;
    }
    aux=CreateNode(d);
    aux->nodeNext=n->nodeNext;
    n->nodeNext=aux;
    L->size++;
}


Node* searchByPos(List *L,int pos)
{
    Node *ptr;
    int i=1;
    ptr=L->head;

    if(pos==0)
    {
        printf("The beginning of the list is in the position one, the search could not be realized\n");
        return NULL;
    }

    if(pos>L->size)
    {
        printf("The position is out of range, the search could not be realized\n");
        return NULL;
    }
    while(i!=pos)
    {
        ptr=ptr->nodeNext;
        i++;
    }

    return ptr;
}

int deleteNodeByPos(List *L,int pos)
{
    Node *ptr,*prev;
    int i=1;

    ptr=L->head;
    prev=NULL;
    if(pos>L->size)
    {
        printf("The position is out of range, the delete will be omitted\n");
        return FALSE;
    }
    if(pos==0)
    {
        printf("The list start at number one position, the zero position is an invalid value\n");
        return FALSE;
    }

    if(pos==1)
    {
        L->head=L->head->nodeNext;
        free(ptr);
        L->size--;
        return TRUE;
    }

    if(pos==2)
    {
        prev=ptr;
        ptr=ptr->nodeNext;
        prev->nodeNext=ptr->nodeNext;
        free(ptr);
        L->size--;
        return TRUE;
    }
    while(i!=pos-1)
    {
        ptr=ptr->nodeNext;
        prev=ptr;
        i++;
    }

    ptr=ptr->nodeNext;
    prev->nodeNext=ptr->nodeNext;
    free(ptr);
    L->size--;
    return TRUE;
}

void destroyList(List *L)
{
    while(L->size!=0)
    {
        deleteNodeByPos(L,L->size);
    }
    isEmpty(L);
}

int isEmpty(List *L)
{
    if(L->head==NULL) //Empty
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

void printList(List *L)
{
    Node *ptr;
    ptr=L->head;
    while(ptr!=NULL)
    {
        printf("%d-> ",ptr->data);
        ptr=ptr->nodeNext;
    }
    printf("NULL\n");
    printf("size=%d\n",L->size);
}
