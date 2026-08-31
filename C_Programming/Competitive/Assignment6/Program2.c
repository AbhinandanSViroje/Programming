#include<stdio.h>

void Display(int iNo)
{
    if(iNo == 0 || iNo == -0)
    {
        printf("Zero\n");
    }
    else if(iNo == 1 || iNo == -1)
    {
        printf("One\n");
    }
    else if(iNo == 2 || iNo == -2)
    {
        printf("Two\n");
    }
    else if(iNo == 3 || iNo == -3)
    {
        printf("Three\n");
    }
    else if(iNo == 4 || iNo == -4)
    {
        printf("Four\n");
    }
    else if(iNo == 5 || iNo == -5)
    {
        printf("Five\n");
    }
    else if(iNo == 6 || iNo == -6)
    {
        printf("Six\n");
    }
    else if(iNo == 7 || iNo == -7)
    {
        printf("Seven\n");
    }
    else if(iNo == 8 || iNo == -8)
    {
        printf("Eight\n");
    }
    else if(iNo == 9 || iNo == -9)
    {
        printf("Nine\n");
    }
    else
    {
        printf("Invaild Number\n");
    }
}
int main()
{
    int iValue = 0;
    printf("Enter Number : ");
    scanf("%d",&iValue);

    Display(iValue);
    return 0;
}