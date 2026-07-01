#include <stdio.h>

int main(void)
{
    printf("Enter the first number\n");
    int n1; scanf("%d", &n1);
    printf("Enter the second number\n");
    int n2; scanf("%d", &n2);
    int r = (n1 + n2);
    printf("Result is: %d\n",r);

    char exit;
    
    scanf("%c", &exit); // TODO: make an exit function.
    if (exit == "%c", "e")
    {
        return 0;
    }
}