#include<stdio.h>

int OddFactorial(int iNo)
{
   int i = 0;
   int iFact = 1;

   if(iNo < 0)
   {
        iNo = -iNo;
   }

   for(i = iNo; i > 0; i--)
   {
        if(i % 2 != 0)
        {
           iFact = iFact * i; 
        }
        
   }

   return iFact;
}

int main()
{
    int iValue = 0,iRet = 0;

    printf("Enter Number : ");
    scanf("%d",&iValue);

    iRet = OddFactorial(iValue);

    printf("Odd Factorial of Number is : %d\n",iRet);
   
    return 0;
}

