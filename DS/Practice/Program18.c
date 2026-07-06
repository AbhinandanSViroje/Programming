/*
Q.Write a C program to create the basic structure of a singly linked list ?

* Define a structure named node containing:
    * an integer data
    * a pointer next to the next node.
* Create typedefs for:
    * NODE (structure type)
    * PNODE (pointer to structure)
    * PPNODE (pointer to pointer to structure)
* In main(), declare a head pointer and initialize it to NULL.

Algorithm:-
--Start the program.
--Define a node structure with data and next.
--Create typedefs: NODE, PNODE, and PPNODE.
--In main(), declare head as a PNODE.
--Initialize head to NULL (empty linked list).
--End the program.
*/
 
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct ndoe **PPNODE;

int main()
{
    PNODE head = NULL;
    
    return 0;
}