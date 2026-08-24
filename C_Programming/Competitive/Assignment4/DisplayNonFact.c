#include<stdio.h>

void NonFact(int iNo)
{
    int  i = 0;

    for(i = 1;i < iNo;i++)
    {
        if(iNo % i != 0)
        {
            printf("%d\t",i);
        }
    }
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter Number: \n");
    scanf("%d",&iValue);

    NonFact(iValue);
    
    return 0;
}