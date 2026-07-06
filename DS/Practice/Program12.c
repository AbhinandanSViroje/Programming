/*
Q) Why do we use temp = temp->next; in a linked list? 

ANS:- temp = temp->next; moves the pointer to the next node in the linked list. 
Unlike i = i + 1, linked list nodes are not stored in contiguous memory, so we use the next pointer -> to reach the next node instead of adding 1.

--in previous Program 11  it was sequence as you can see it is repetation.

// SEQUENCE

   printf("%d\n",temp -> data);                 // 11 (the data that is inside the 100 address)
   
   temp = temp -> next;                         //200
   printf("%d\n",temp -> data);                 //21 

   temp = temp -> next;                         //300
   printf("%d\n",temp -> data);                 // 51

   temp = temp -> next; 
   
   -- so make this sequence to iteration.
*/

#include<stdio.h>

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
    PNODE head = NULL;
    PNODE temp = NULL;

    NODE obj1,obj2,obj3;

    head = &obj1;
    
     obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    temp = head;                                

    // Iteration

    while(temp != NULL)
    {
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }

    return 0;

}

/*
    Output: 11
            21
            51
*/