// use of iteration to move from one node to another and count the number of nodes in linked list

#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

int main()
{
    PNODE head = NULL;
    PNODE temp = NULL;
    NODE obj1,obj2,obj3;

    int iCount = 0;
    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    temp = head;

    while(temp != NULL)
    {
        
        printf("%d\n",temp->data);
        iCount++;
        temp = temp -> next;
    }

    printf("Numbers of node are : %d\n ",iCount);

    return 0;
}

/*
    Output: 11
            21
            51
            Numbers of node are : 3
*/