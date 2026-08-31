#include<stdio.h>

void Number(int iNo)
{
    if(iNo <= 50)
    {
        printf("small\n");
    }
    else if(iNo > 50 && iNo <= 100)
    {
        printf("Medium\n");
    }
    else
    {
        printf("Large\n");
    }
}
int main()
{
    int iValue = 0;
    printf("Enter Number : ");
    scanf("%d",&iValue);

    Number(iValue);
    return 0;
}