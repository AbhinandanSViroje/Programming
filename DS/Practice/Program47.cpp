// Singly Linked list in C++ only InserFirst and InsertLast 

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
        int count();
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
{}
int SinglyLL :: count()
{
    return 0;
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
}
void SinglyLL :: InsertAtPos(int iNo, int iPos)
{
   
}
void SinglyLL :: DeleteFirst()
{}
void SinglyLL :: DeleteLast()
{}
void SinglyLL :: DeleteAtPos(int iPos)  
{}

int main()
{
    SinglyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);


}