#include <stdio.h>

int FactDiff(int iNo)
{
    int i = 0;
    int iFact1 = 0, iFact2 = 0;
    int iFactDiff = 0;

    for(i = 1; i < iNo; i++)
    {
        if(iNo % i == 0)
        {   
            iFact1 = iFact1 + i;
        }
        if(iNo % i != 0)
        {   
            iFact2 = iFact2 + i;
        }
    }
    iFactDiff = iFact1 - iFact2;    
    return iFactDiff;
}

int main()
{


    int iValue = 0;
    int iRet = 0;

    printf("Enter number: ");
    scanf("%d",&iValue);

    iRet = FactDiff(iValue);
    printf("%d\n",iRet);

    return 0;
}