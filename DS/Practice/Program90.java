class node 
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    public node first;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Inside Constructor");
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {}

    public int Count()
    {
        return 0;
    }
    public void InsertFirst(int iNo)
    {
        node newn = null;

        newn = new node(iNo);

        if(first == null)
        {
            return;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
    }
    public void InsertLast(int iNo)
    {
        node newn = null;

        newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            while(first != null)
            {
                first = first.next;
            }
        }
    }
    public void InsertAtPost(int iNo,int iPos)
    {}

    public void DeleteFirst()
    {}
    public void DeleteLast()
    {}
    public void DeleteAtPost(int iPos)
    {}

}

class Program90
{
   public static void main(String A[])
   {
        SinglyLL sobj = new SinglyLL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);
   }

}

    

