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
    return 0;
}

void Display(PNODE first)
{
    
}

void InsertFirst(PPNODE first , int iNo)
{
    PNODE newn = NULL;
    
    newn = (PNODE) malloc (sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;                          //$ means new line

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        (*first) -> prev = newn;  //$
        *first = newn;
    }

}
void InsertLast(PPNODE first , int iNo)
{

    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE) malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;                          //$ means new line

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
        newn -> prev = temp;                    // $
    }

}
void InsertAtPos(PPNODE first ,int iNo, int iPos)
{
    
}
void DeleteFirst(PPNODE first)
{
    
}
void DeleteLast(PPNODE first)
{

}
void DeleteAtPos(PPNODE first ,int iPos)
{

}
int main()
{
    PNODE head = NULL;

    return 0;
}