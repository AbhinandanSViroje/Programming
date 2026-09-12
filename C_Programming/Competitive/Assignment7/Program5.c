#include<stdio.h>

int DiffEvenOddFactorial(int iNo)
{
   int i = 0;
   int iFact1 = 1,iFact2 = 1;
   int DiffResult = 0;

   if(iNo < 0)
   {
        iNo = -iNo;
   }

   for(i = iNo; i > 0; i--)
   {
        if(i % 2 == 0)
        {
           iFact1 = iFact1 * i; 
        }
        else
        {
            iFact2 = iFact2 * i;
        }   
   }

   DiffResult = iFact1 - iFact2;

   return DiffResult;
}

int main()
{
    int iValue = 0,iRet = 0;

    printf("Enter Number : ");
    scanf("%d",&iValue);

    iRet = DiffEvenOddFactorial(iValue);

    printf("Difference of EvenOdd Factorial of Number is : %d\n",iRet);
   
    return 0;
}

