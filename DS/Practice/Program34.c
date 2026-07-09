/*

Write a C program to implement a Singly Linear Linked List using dynamic memory allocation. The program should perform the following operations:

1. Define a structure node containing an integer data and a pointer next.
2. Create typedef aliases (NODE, PNODE, and PPNODE).
3. Implement the following linked list operations:
    * InsertFirst() – Insert a node at the beginning.
    * InsertLast() – Insert a node at the end.
    * InsertAtPos() – Insert a node at the specified position.
    * DeleteFirst() – Delete the first node.
    * DeleteLast() – Delete the last node.
    * DeleteAtPos() – Delete a node from the specified position.
    * Display() – Display all nodes of the linked list.
    * Count() – Count and return the total number of nodes.
4. In the main() function, create an empty linked list, perform all insertion and deletion operations, display the linked list after each operation, and print the total number of nodes.

Algorithm:- 1. Start the program.
            2. Define the node structure and create the required typedefs.
            3. Initialize the head pointer to NULL.
            4. Create new nodes using dynamic memory allocation.
            5. Insert nodes at the beginning using InsertFirst().
            6. Insert nodes at the end using InsertLast().
            7. Insert a node at the specified position using InsertAtPos().
            8. Traverse and display the linked list.
            9. Count and display the total number of nodes.
            10. Delete the first node using DeleteFirst().
            11. Delete the last node using DeleteLast().
            12. Delete the node at the specified position using DeleteAtPos().
            13. Display the updated linked list after each deletion.
            14. Count and display the updated number of nodes.
            15. Stop the program.

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
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCount  = 0;
    int i = 0;

    iCount=Count(*first);

    if(iPos < 1 || iPos > iCount+1)
    {
        printf("Invaild Position");
        return;

    }

    if(iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first,iNo);
    }
    else
    {
        temp = *first;
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
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

    if(*first==NULL)
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
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCount  = 0;
    int i = 0;

    iCount=Count(*first);

    if(iPos < 1 || iPos > iCount+1)
    {
        printf("Invaild Position");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount+1)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        for(i = 1; i < iPos-1;i++)
        {
            temp = temp->next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        free(target);
    }

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

    InsertAtPos(&head,105,4);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&head,4);
    
    Display(head);

    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    return 0;
}

/*
    Output :| 11 | ->| 21 | ->| 51 | ->| 101 | -> NULL
            Number of nodes are : 4
            | 11 | ->| 21 | ->| 51 | ->| 101 | ->| 111 | ->| 121 | -> NULL
            Number of nodes are : 6
            | 21 | ->| 51 | ->| 101 | ->| 111 | ->| 121 | -> NULL
            Number of nodes are : 5
            | 21 | ->| 51 | ->| 101 | ->| 111 | -> NULL
            Number of nodes are : 4
            | 21 | ->| 51 | ->| 101 | ->| 105 | ->| 111 | -> NULL
            Number of nodes are : 5
            | 21 | ->| 51 | ->| 101 | ->| 111 | -> NULL
            Number of nodes are : 4
*/

