//Doubly Circular linked list in C++(Insertfirst and Insertlast)

#include<iostream>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCL();
        void Display();
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst(int iNo);
        void Deletelast(int iNo);
        void DeleteAtPos(int iNo, int iPos);
};

DoublyCL :: DoublyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
void DoublyCL :: Display()
{}
int DoublyCL :: Count()
{
    return 0;
}
void DoublyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this ->last = newn;
    }
    else
    {
        newn -> next = this-> first;
        this->first = newn;
    }
    this->first->prev = this->last;
    this->last->next = this->first;
}
void DoublyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this ->last = newn;
    }
    else
    {
        
        this->last->next = newn;
        newn -> prev = this -> last;
        this->last = newn;
    }
    this->first->prev = this->last;
    this->last->next = this->first;
}
void DoublyCL :: InsertAtPos(int iNo, int iPos)
{}
void DoublyCL :: DeleteFirst(int iNo)
{}
void DoublyCL :: Deletelast(int iNo)
{}
void DoublyCL :: DeleteAtPos(int iNo, int iPos)
{}

int main()
{
    DoublyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    return 0;
}


