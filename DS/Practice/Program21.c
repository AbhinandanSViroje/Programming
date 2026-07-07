/*
Write a C program to create a Singly Linear Linked List and implement the InsertFirst() operation.

The program should:

* Define a structure node with data and next.
* Create typedef aliases (NODE, PNODE, PPNODE).
* Declare placeholder functions for Display(), Count(), InsertLast(), InsertAtPos(), DeleteFirst(), DeleteLast(), and DeleteAtPos().
* Implement only the InsertFirst() function to insert a new node at the beginning of the linked list.
* In main(), create an empty linked list and insert multiple nodes using InsertFirst().

Algorithm:-     1. Start the program.
                2. Define the node structure and create typedefs.
                3. Declare all required linked list functions.
                4. Initialize head to NULL.
                5. Allocate memory for a new node.
                6. Store the data in the new node.
                7. If the list is empty, make the new node the first node.
                8. Otherwise, link the new node before the current first node and update head.
                9. Repeat for all insertions.
                10. Stop the program.


*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first)
{

}

int Count(PNODE first)
{
    return 0;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;

    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        
    }

}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{

}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int iPos)
{

}
int main()
{
    PNODE head = NULL;

    return 0;
}