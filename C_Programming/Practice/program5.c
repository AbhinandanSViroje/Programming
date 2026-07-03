#include<stdio.h>

int main()
{
    float fValue1 = 0.0f;                               //To store first input
    float fValue2 = 0.0f;                               //To store second input
    float fResult = 0.0f;                               //To store result

    printf("Enter the first number : \n");
    scanf("%f",&fValue1);
    printf("Enter the second number : \n");
    scanf("%f",&fValue2);

    fResult = fValue1 + fValue2;                        // perform the Addtion and it is Business logic

    printf("Addition is : %f",fResult);
    

    return 0;
}