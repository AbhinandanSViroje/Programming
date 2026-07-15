// Doubly linear linked list (Display,Count)

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};


typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first->next;     
    }
    return iCount;
}
void Display(PNODE first)
{
    printf("\n NULL <=> ");
    while(first != NULL)
    {
        printf("| %d | <=> ", first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }
}
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        newn -> prev = temp;
        temp -> next = newn;
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
    int iRet = 0;

    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);
    printf("The number of nodes are : %d \n",iRet);

    return 0;
}