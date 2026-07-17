//Doubly Circular linked list in C++(Template)

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
        void Insertlast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst(int iNo);
        void Deletelast(int iNo);
        void DeleteAtPos(int iNo, int iPos);
};

DoublyCL :: DoublyCL()
{}
void DoublyCL :: Display()
{}
int DoublyCL :: Count()
{}
void DoublyCL :: InsertFirst(int iNo)
{}
void DoublyCL :: Insertlast(int iNo)
{}
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

    return 0;
}


