/*

Write a C program to implement a Singly Linear Linked List with the following operations:

1. Create a node structure containing data and next.
2. Create typedef aliases (NODE, PNODE, and PPNODE).
3. Implement the InsertFirst() function to insert a new node at the beginning of the linked list.
4. Implement the Display() function to display all the elements of the linked list.
5. In the main() function, create an empty linked list, insert multiple nodes using InsertFirst(), and display the linked list.

Algorithm:-     1. Start the program.
                2. Define the node structure and create typedefs.
                3. Declare and initialize the head pointer to NULL.
                4. Create a new node using dynamic memory allocation.
                5. Store the given data in the new node.
                6. If the linked list is empty, make the new node the first node.
                7. Otherwise, link the new node before the current first node and update head.
                8. Repeat the insertion process for all required elements.
                9. Traverse the linked list from head to NULL and display each node’s data.
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
    while(first != NULL)
    {
        printf("| %d | ->", first->data);
        first = first -> next;
    }
    printf(" NULL\n");
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

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);


    return 0;
}

/*
    Output : | 11 | ->| 21 | ->| 51 | ->| 101 | -> NULL
*/