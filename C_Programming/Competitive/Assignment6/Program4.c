#include<stdio.h>

void Table(int iNo)
{
    int i = 0;

    //filter for making negative input  into positive input
    if(iNo < 0)
    {
        iNo = -iNo;
    }
    
    for(i = 1; i <= 10;i++)
    {
        printf(" %d\t ",iNo * i);
    }
}

int main()
{
    int iValue = 0;

    printf("Enter Number : ");
    scanf("%d",&iValue);

    Table(iValue);

    return 0;
}