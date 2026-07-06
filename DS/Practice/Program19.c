/*
Q.Write a C program to define a singly linked list using typedef?

* Create a structure node containing:
    * an integer variable data
    * a pointer next to the next node.
* Use typedef to define:
    * NODE as the structure type.
    * PNODE as a pointer to the structure.
    * PPNODE as a pointer to a pointer to the structure.
* In the main() function, declare a head pointer and initialize it to NULL.

Algorithm:

            1. Start the program.
            2. Define the node structure using typedef.
            3. Declare NODE, PNODE, and PPNODE.
            4. Declare head as a PNODE.
            5. Initialize head to NULL.
            6. Stop the program.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}NODE, *PNODE ,**PPNODE; 

int main()
{
    PNODE head = NULL;


    return 0;
}