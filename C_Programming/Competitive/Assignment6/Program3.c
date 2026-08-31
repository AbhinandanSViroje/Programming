#include<stdio.h>

int Factorial(int iNo)
{
    int i = 0;
    int iFact = 1;

    //filter for making negative input  into positive input
    if(iNo < 0)
    {
        iNo = -iNo;
    }
    
    for(i = iNo; i > 0;i--)
    {
        iFact = iFact * i;
    }
    return iFact;
}
int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter Number : ");
    scanf("%d",&iValue);

    iRet=Factorial(iValue);
    printf("%d\n",iRet);

    return 0;
}