#include<stdio.h>

int DollorToINR(int iNo)
{
   int Result = 0;
   Result = iNo * 70;
   
   return Result;
}

int main()
{
    int iValue = 0,iRet = 0;

    printf("Enter Number of USD : ");
    scanf("%d",&iValue);

    iRet = DollorToINR(iValue);

    printf("Value of INR is : %d\n ",iRet);    


    return 0;
}