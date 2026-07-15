// Doubly linear linked list in C++ (Delete first , Delete last)

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
{
    PNODE temp = NULL;

    temp = this->first;
    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp ->next;
    }
    cout<<"NULL "<<endl; 
}

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
    this -> iCount++;
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
    this -> iCount++;
}
void DoublyLL :: InsertAtPos(int iNo , int iPos)
{}
void DoublyLL :: DeleteFirst()
{
    PNODE temp = NULL;
    
    if(this-> first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
        this->iCount--;
    }
    
}
void DoublyLL :: DeleteLast()
{
    PNODE temp = NULL;
    
    if(this-> first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
        this->iCount--;
    }

}
void DoublyLL :: DeleteAtPos(int iPos)
{}

int main()
{
    DoublyLL  dobj;
    int iRet = 0;
    
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    iRet = dobj.Count();
    cout<<"The number of Nodes are : "<<iRet<<endl;

    dobj.DeleteFirst();

    dobj.Display();

    iRet = dobj.Count();
    cout<<"The number of Nodes are : "<<iRet<<endl;

    dobj.DeleteLast();
    dobj.Display();

    iRet = dobj.Count();
    cout<<"The number of Nodes are : "<<iRet<<endl;
        
    return 0;
}