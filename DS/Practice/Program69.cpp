//singly Circular linked list in C++(Deletefirst and deletelast)

#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL();
        void Display();
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyCL :: SinglyCL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
void SinglyCL :: Display()
{
    PNODE temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    temp = this->first;
    do
    {
        cout<<"| "<<temp->data<<" | ->";
        temp = temp ->next;
    } while (temp != this->last->next);

    cout<<"\n";
}
int SinglyCL :: Count()
{
    return iCount;
}
void SinglyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn ->data = iNo;
    newn-> next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this-> first = newn;
        this-> last  = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;
    this->iCount++;
}
void SinglyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;

     newn = new NODE;
     
    newn ->data = iNo;
    newn-> next = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this-> first = newn;
        this-> last  = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;  
    }
    this->last->next = this->first;
    this->iCount++;
}
void SinglyCL :: InsertAtPos(int iNo, int iPos)
{}
void SinglyCL :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        free(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        free(this->last ->next);
        this->last->next = this->first;
        this->iCount--;
    }
}
void SinglyCL :: DeleteLast()
{
    PNODE temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        free(this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next != this->last)
        {
            temp = temp->next;
        }
        free(this->last);
        this->last = temp;
        this->last->next = this->first;
        this->iCount--;
    }
}
void SinglyCL :: DeleteAtPos(int iPos)
{}

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"The number of node are : "<<iRet<<endl;

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"The number of node are : "<<iRet<<endl;

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"The number of node are : "<<iRet<<endl;

    return 0;
}
