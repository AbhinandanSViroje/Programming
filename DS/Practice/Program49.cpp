// Singly Linked list in C++ only DeleteFirst and DeleteLast

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

class SinglyLL
{
    private:                    // because no one can access outside of the class
        PNODE first;
        int iCount;

    public:
        SinglyLL();
        void Display();
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);      
};

SinglyLL :: SinglyLL()
{
    this->first = NULL;
    this->iCount = 0;
}
void SinglyLL :: Display()
{
    PNODE temp = NULL;

    temp = this->first;
    
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int SinglyLL :: Count()
{
    return this -> iCount;
}
void SinglyLL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn -> next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->iCount++;
}
void SinglyLL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn -> next = NULL;

    if(this->first == NULL)
    {
       this->first =  newn;
    }
    else
    {
      temp = this->first;

      while(temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newn;
    }
    this->iCount++;
}
void SinglyLL :: InsertAtPos(int iNo, int iPos)
{
   
}
void SinglyLL :: DeleteFirst()
{
    PNODE temp = NULL;

    if(this->first == NULL)
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
        this->first = this->first->next;
        delete temp;
        this->iCount--;
    }
}
void SinglyLL :: DeleteLast()
{
    PNODE temp = NULL;
    
    if(this->first == NULL)
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
        while(temp -> next ->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
        this->iCount--;
    }
    
}
void SinglyLL :: DeleteAtPos(int iPos)  
{
    
}

int main()
{
    int iRet = 0;
    SinglyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of Nodes are : "<<iRet<<endl;

}