/*
Write a C program to implement a Singly Linear Linked List using dynamic memory allocation. The program should perform the following operations:

1. Define a structure node containing an integer data and a pointer next.
2. Create typedef aliases (NODE, PNODE, and PPNODE).
3. Implement the InsertFirst() function to insert a new node at the beginning of the linked list.
4. Implement the Display() function to display all the nodes of the linked list.
5. Implement the Count() function to count and return the total number of nodes.
6. In the main() function, create an empty linked list, insert multiple nodes using InsertFirst(), display the linked list, and print the total number of nodes.

    Algorithm:-     1. Start the program.
                    2. Define the node structure and create typedefs.
                    3. Initialize the head pointer to NULL.
                    4. Create a new node using dynamic memory allocation.
                    5. Store the given data in the new node.
                    6. Insert the new node at the beginning of the linked list.
                    7. Repeat the insertion process for all required nodes.
                    8. Traverse the linked list and display each node.
                    9. Traverse the linked list again and count the total number of nodes.
                    10. Display the total number of nodes.
                    11. Stop the program.
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
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(NULL = *first)              // Error
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

    int iRet = 0;

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}

/*
    Output : | 11 | ->| 21 | ->| 51 | ->| 101 | -> NULL
              Number of nodes are : 4
*/

