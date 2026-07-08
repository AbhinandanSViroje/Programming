/*
Write a C program to implement a Singly Linear Linked List using dynamic memory allocation. The program should perform the following operations:

1. Define a structure node containing an integer data and a pointer next.
2. Create typedef aliases (NODE, PNODE, and PPNODE).
3. Implement the InsertFirst() function to insert a node at the beginning of the linked list.
4. Implement the InsertLast() function to insert a node at the end of the linked list.
5. Implement the DeleteFirst() function to delete the first node from the linked list.
6. Implement the Display() function to display all the nodes of the linked list.
7. Implement the Count() function to count and return the total number of nodes.
8. In the main() function, create an empty linked list, perform insertion and deletion operations, display the linked list, and print the total number of nodes.

--Algorithm:-       1.Start the program.
                    2. Define the node structure and create typedefs.
                    3. Initialize the head pointer to NULL.
                    4. Create a new node using dynamic memory allocation.
                    5. Insert nodes at the beginning using InsertFirst().
                    6. Insert nodes at the end using InsertLast().
                    7. Traverse and display the linked list.
                    8. Count the total number of nodes.
                    9. Delete the first node using DeleteFirst().
                    10. Display the updated linked list.
                    11. Count and display the updated number of nodes.
                    12. Stop the program.  
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

    if(NULL == *first)              // Modern compilers usually warn you if you accidentally write = instead of ==.   //This is an old C programming style called Yoda conditions.
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
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    
    newn -> data = iNo;
    newn -> next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if((*first)==NULL)
    {
        return;
    }
    else if((*first)-> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp -> next = NULL;
    }
    
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

    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}

/*
    Output : | 11 | ->| 21 | ->| 51 | ->| 101 | -> NULL
              Number of nodes are : 4
              | 11 | ->| 21 | ->| 51 | ->| 101 | ->| 111 | ->| 121 | -> NULL
              Number of nodes are : 6
              | 21 | ->| 51 | ->| 101 | ->| 111 | ->| 121 | -> NULL
              Number of nodes are : 5
*/

