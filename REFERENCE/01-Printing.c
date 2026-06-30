#include <stdio.h>

int main()
{
    int number;
    number = 20;
    printf("Number is: %d\n",number);
    return 0;
}

// compile: gcc 01-Printing.c -o printing.exe
// TEST: Expected output, Number is: 20
// Results: Output, Number is: 20

// CODE WORKED AS EXPECTED

// remember: %d (int), %c (char), %f (float)