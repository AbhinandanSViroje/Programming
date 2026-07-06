// Dynamic allocation with malloc() function

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

int main()
{
    PNODE newn = NULL;

/*
malloc() allocates memory in the heap and returns its address as a generic pointer (void *). 
(PNODE) typecasts that generic pointer into a struct node *, telling the compiler that the pointer points to a struct node. 
Therefore, the allocated memory is treated as a struct node, and since newn is a pointer to that structure, we use the -> operator to access its members.
*/

    newn = (PNODE) malloc(sizeof(NODE));

    newn->data = 11;
    newn -> next = NULL;

    printf("%d\n",newn->data);


    return 0;
}

/*
    Output: 11
*/