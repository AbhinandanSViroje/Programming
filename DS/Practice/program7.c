// single linked list

#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;  
};

int main()
{
    struct node *head = NULL;               // Structure pointer(object pointer)
    struct node obj1,obj2,obj3;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    printf("%u\n",head->data);
    printf("%u\n",head->next->data);
    printf("%u\n",head->next->next->data);


    return 0;
}

/*
    Output: 11
            21
            51
*/