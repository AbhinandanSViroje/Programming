#include <stdio.h>

void OddDisplay(int iNo)
{
    int iMult = 5;
    int i = 0, Result = 0;

    for(i = 1; i <= iMult; i++)
    {
        Result = iNo * i;     
        printf("%d\t",Result);
    }
}

int main()
{

    int iValue = 0;
    printf("Enter number: ");
    scanf("%d",&iValue);

    OddDisplay(iValue);

    return 0;
}