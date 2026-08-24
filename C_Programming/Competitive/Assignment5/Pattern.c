#include <stdio.h>

void Pattern(int iNo)
{
    int i = 0;
    for(i = 1;i<iNo;i++)
    {
        if(i % 2 == 0)
        {
            printf("$\t*\t");
        }
        else
        {
            printf("$\t*\t");
        }
    }
}

int main()
{

    int iValue = 0;
    printf("Enter number: ");
    scanf("%d",&iValue);

    Pattern(iValue);

    return 0;
}