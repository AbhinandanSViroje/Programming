#include<stdio.h>

void Accept(int iNo)
{
    int iCnt = 0;

    while(iCnt < iNo)
    {
        printf("*\n");
        iCnt++;
    }

}

int main()
{
    int iValue = 0;

    printf("Enter the Number :  ");
    scanf("%d",&iValue);

    Accept(iValue);
    
    return 0;
}