#include <stdio.h>

int main()
{
    printf("-------------------------\n");
    printf("Please insert your age\n");
    printf("-------------------------\n");

    int age = scanf("%d");

    if (age > 18)
    {
        printf("You are over 18\n");
    } else
        {
            printf("You are under 18\n");
        }
}