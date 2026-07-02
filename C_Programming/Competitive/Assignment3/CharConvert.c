/*
logic remember the ASCCI Value 
example:-
'A' = 65
'a' = 97

97 - 65 = 32

Uppercase

A B C D E F G ... Z
65 66 67 68        90

↓

Difference = +32

↓

Lowercase

a b c d e f g ... z
97 98 99 100      122

------------------------------------------------------------

Lowercase

a b c d e f g ... z
97 98 99 100      122


↓

Difference = -32

↓

Uppercase

A B C D E F G ... Z
65 66 67 68        90


*/



#include<stdio.h>

void DisplayConvert(char cValue)
{
    if(cValue >= 'A' && cValue <= 'Z')
    {
        printf("%c",cValue + 32);
    }
    else if(cValue >= 'a' && cValue <= 'z')
    {
        printf("%c",cValue - 32);
    }
}

int main()
{
    char cValue = '\0';

    printf("Enter Character :\n");

    scanf("%c",&cValue);

    DisplayConvert(cValue);

    return 0;
}