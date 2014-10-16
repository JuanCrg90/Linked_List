#include <stdio.h>
#include <stdlib.h>
#include "../../include/linklist.h"

/*something is wrong with this code*/

int main(void)
{

    List *l;
    Node *aux;

    int a=1;
    int b=2;
    int c=3;
    int d=4;
    int e=5;

    int *ptrA=a;
    int *ptrB=b;
    int *ptrC=c;
    int *ptrD=d;
    int *ptrE=e;


    *l=initializeList(l);

    insertEnd(l,ptrA);
    insertEnd(l,ptrB);
    insertEnd(l,ptrC);
    insertEnd(l,ptrD);
    insertEnd(l,ptrE);

    printList(l);

    aux=searchByPos(l,3); //search the node in the position 3

    printf("\n%d\n",aux->data);

    destroyList(l);

    if(isEmpty(l))
    {
        printf("The list is empty\n");
    }

    return 0;
}

