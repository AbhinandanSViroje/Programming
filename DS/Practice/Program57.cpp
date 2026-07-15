// Doubly linear linked list in C++ (Insert first , Insert last)

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL 
{
    private:
        PNODE first;
        int iCount;
        
    public:
        DoublyLL();
        void Display(); 
        int Count();  
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo , int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

DoublyLL :: DoublyLL()
{
    this -> first = NULL;
    this -> iCount = 0;
}

void DoublyLL :: Display()
{}

int DoublyLL :: Count()
{
    
    return this -> iCount;
}

void DoublyLL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
}
void DoublyLL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this -> first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        newn -> prev = temp;
    }
}
void DoublyLL :: InsertAtPos(int iNo , int iPos)
{}
void DoublyLL :: DeleteFirst()
{}
void DoublyLL :: DeleteLast()
{}
void DoublyLL :: DeleteAtPos(int iPos)
{}

int main()
{
    DoublyLL  dobj;
    
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
        
    return 0;
}