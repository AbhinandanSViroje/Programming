// DS Program to Count number and display function nodes in singly linear linked list

#include<stdio.h>

#pragma Pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("%d\n",first -> data);
        first = first -> next;
    }
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

int main()
{
    PNODE head = NULL;

    int iRet = 0;

    NODE obj1,obj2,obj3;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d\n",iRet);




    return 0;
}

/*
    Output: 11
            21
            51
            Numbers of node are : 3
*/
