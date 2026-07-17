//Doubly Circular linked list in C++(Deletefirst and Deletelast)

#include<iostream>
using namespace std;

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
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL :: DoublyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
void DoublyCL :: Display()
{
    PNODE temp = NULL;
    temp = this->first;

    cout<<"<=> ";
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    do
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp -> next;
    } while (temp != this->last->next);

    cout<<"\n";

}
int DoublyCL :: Count()
{
    return iCount;
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
    this->iCount++;
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
    this->iCount++;
}
void DoublyCL :: InsertAtPos(int iNo, int iPos)
{}
void DoublyCL :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    if(this->first == this->last)
    {
        free(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        free(this->last->next);
    }
    this->first->prev = this->last;
    this->last->next = this->first;
    this->iCount--;
}
void DoublyCL :: DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    if(this->first == this->last)
    {
        free(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        free(this->first->prev);
    }
    this->first->prev = this->last;
    this->last->next = this->first;
    this->iCount--;
}
void DoublyCL :: DeleteAtPos(int iPos)
{}

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"The Number of nodes are : "<<iRet<<endl;

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"The Number of nodes are : "<<iRet<<endl;

    obj.DeleteLast();

     obj.Display();

    iRet = obj.Count();
    cout<<"The Number of nodes are : "<<iRet<<endl;

    return 0;
}


