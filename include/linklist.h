/*
  Juan Carlos Ruiz González
  Universidad de Guanajuato
  Linked list library
*/
#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef int mytype; //Here is the data type

typedef struct NODE_TAG
{
    mytype *data;
    struct NODE_TAG *nodeNext;
}Node;


typedef struct LIST_TAG
{
    Node *head;
    int size;
}List;


List initializeList(List *L); //Initializes the list in NULL
Node* CreateNode(mytype *d); //Creates a node
void insertBegin(List *L,mytype *d); //Inserts a node at the begin
void insertEnd(List *L,mytype *d); //Inserts a node at the end
void insertPos(List *L,mytype *d,int pos); //Inserts a node in the indicated position if the position is out of range the node is insert at the end
Node* searchByPos(List *L,int pos); //Searchs the data contained in the given position
int deleteNodeByPos(List *L,int pos); //Deletes a node in a given position
void destroyList(List *L);//Destroy the list
int isEmpty(List *L); //Verifies if the list is empty
void printList(List *L); //Prints all the list and the Elements Quantity (the function prints integer values)


#endif // LINKLIST_H
