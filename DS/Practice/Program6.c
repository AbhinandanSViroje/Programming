// three  node linked List

#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node obj1,obj2,obj3;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    printf("%u\n",&obj1);
    printf("%u\n",&obj2);
    printf("%u\n",&obj3);

    printf("%u\n",obj1.next);
    printf("%u\n",obj2.next);
    printf("%u\n",obj3.next);

    printf("%u\n",obj1.data);
    printf("%u\n",obj1.next->data);
    printf("%u\n",obj1.next->next->data);

    return 0;
}

/*
    Output: 1800106304
            1800106292
            1800106280
            1800106292
            1800106280
            0
            11
            21
            51
*/