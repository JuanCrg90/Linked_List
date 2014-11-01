/**
* @file fuzzyrules.h
* @brief Fuzzy Rules
* @author: Juan Carlos Ruiz González
* Universidad de Guanajuato
* Email: juancarlosruiz14@gmail.com
* @date 11/01/2014
*/
#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0




typedef struct NODE_TAG
{
    void *data;
    struct NODE_TAG *nodeNext;
}Node;


typedef struct LIST_TAG
{
    Node *head;
    int size;
}List;

/**
 * @brief Initializes the list in NULL
 * @param L
 */
List *initializeList();

/**
 * @brief Creates a node
 * @param d
 * @return
 */
Node* createNode(void *d);

/**
 * @brief Free node
 * @param n
 */
void freeNode(Node *n);

/**
 * @brief Verifies if the list is empty
 * @param L
 * @return Bool
 */
int isEmpty(List *L);


/**
 * @brief Inserts a node at the begin
 * @param L
 * @param d
 */
void insertBegin(List *L,void *d);

/**
 * @brief Inserts a node at the end
 * @param L
 * @param d
 */
void insertEnd(List *L,void *d);

/**
 * @brief Inserts a node in the indicated position if the position is out of range the node is insert at the end
 * @param L
 * @param d
 * @param pos
 */
void insertPos(List *L,void *d,int pos);

/**
 * @brief Searchs the data contained in the given position
 * @param L
 * @param pos
 * @return Node
 */
Node* searchByPos(List *L,int pos);
/**
 * @brief Deletes a node in a given position
 * @param L
 * @param pos
 * @return Bool
 */
int deleteNodeByPos(List *L,int pos);

/**
 * @brief Destroy the list
 * @param L
 */
void destroyList(List *L);


#endif // LINKLIST_H
