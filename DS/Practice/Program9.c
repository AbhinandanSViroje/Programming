// used typedef for pointer and structure

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
    NODE obj1,obj2,obj3;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;      // we are storing Address of obj2 into obj1 next pointer

    obj2.data = 21;
    obj2.next = &obj3;     // we are storing Address of obj3 into obj2 next pointer

    obj3.data = 51;
    obj3.next = NULL;

    printf("%d\n",head->data);
    printf("%d\n",head -> next -> data);
    printf("%d\n",head -> next -> next -> data);

    return 0;
}

/*
    Output: 11
            21
            51
*/