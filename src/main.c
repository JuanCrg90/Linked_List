#include <stdio.h>
#include "include/linklist.h"

void printIntegerList(List *l);
void printFloatList(List *l);
void printCharList(List *l);
void printStringList(List *l);


int main(void)
{

    List *lInt,*lFloat,*lChar,*lString;

    int ia = 2;
    int ib = 3;
    int ic = 4;

    float fa = 5.6;
    float fb = 7.3;
    float fc = 8.9;

    char ca = 'a';
    char cb = 'b';
    char cc = 'c';

    char *sa = "Hello World";
    char *sb = "Test Data";
    char *sc = "Good Bye";



    lInt = initializeList();
    insertBegin(lInt,&ia);
    insertBegin(lInt,&ib);
    insertBegin(lInt,&ic);
    printIntegerList(lInt);

    lFloat = initializeList();
    insertEnd(lFloat,&fa);
    insertEnd(lFloat,&fb);
    insertEnd(lFloat,&fc);
    printFloatList(lFloat);

    lChar=initializeList();
    insertBegin(lChar,&ca);
    insertEnd(lChar,&cb);
    insertBegin(lChar,&cc);
    printCharList(lChar);

    lString = initializeList();
    insertEnd(lString,sa);
    insertEnd(lString,sb);
    insertEnd(lString,sc);
    insertPos(lString,"Prueba",0);
    insertPos(lString,"Prueba2",2);
    insertPos(lString,"Prueba99",99);
    printStringList(lString);


    Node *aux;
    aux = searchByPos(lInt,1);
    printf("Result search position 1 (integer list): %d \n",*(int*)aux->data);

    printf("Delete status (node 4 in string list): %s\n",deleteNodeByPos(lString,99) == 1 ?"True":"False");
    printStringList(lString);

    printf("----------------------------------\n");
    printf("Delete Integer list\n");
    destroyList(lInt);
    printf("List Size %d\n",lInt->size);
    printf("----------------------------------\n");

    printf("----------------------------------\n");
    printf("Delete Float list\n");
    destroyList(lFloat);
    printf("List Size %d\n",lFloat->size);
    printf("----------------------------------\n");

    printf("----------------------------------\n");
    printf("Delete char list\n");
    destroyList(lChar);
    printf("List Size %d\n",lChar->size);
    printf("----------------------------------\n");

    printf("----------------------------------\n");
    printf("Delete String list\n");
    destroyList(lString);
    printf("List Size %d\n",lString->size);
    printf("----------------------------------\n");

    free(lInt);
    free(lFloat);
    free(lChar);
    free(lString);







    return 0;
}

void printIntegerList(List *l)
{
    Node *aux =l->head;

    while(aux!=NULL)
    {
        printf("%d -> ",*(int*)aux->data);
        aux=aux->nodeNext;
    }
    printf("NULL\n");
}

void printFloatList(List *l)
{
    Node *aux =l->head;

    while(aux!=NULL)
    {
        printf("%f -> ",*(float*)aux->data);
        aux=aux->nodeNext;
    }
    printf("NULL\n");

}

void printCharList(List *l)
{
    Node *aux =l->head;

    while(aux!=NULL)
    {
        printf("%c -> ",*(char*)aux->data);
        aux=aux->nodeNext;
    }
    printf("NULL\n");
}

void printStringList(List *l)
{
    Node *aux =l->head;

    while(aux!=NULL)
    {
        printf("%s -> ",(char*)aux->data);
        aux=aux->nodeNext;
    }
    printf("NULL\n");
}
