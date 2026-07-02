#include<stdio.h>

void Accept(int iNo)
{
    int iCnt = 0;
    while(iNo > iCnt)
    {
        printf("*\n");
        iNo--;
    }
}

int main()
{
    int iValue = 0;

    printf("Enter the number");
    scanf("%d",&iValue);

    Accept(iValue);
    return 0;
}