#include<stdio.h>

void Display(int iNo , int iFrequence)
{
    int iCnt = 0;
    if(iFrequence < 0)
    {
        iFrequence = -iFrequence;
    }
    for(iCnt = 1; iCnt <= iFrequence; iCnt++)
    {
        printf("%d\t",iNo);
    }
}

int main()
{
    int iValue = 0;
    int iCount = 0;

    printf("Enter Number : ");
    scanf("%d",&iValue);

    printf("Enter the frequence : ");
    scanf("%d",&iCount);

    Display(iValue,iCount);

    return 0;
}