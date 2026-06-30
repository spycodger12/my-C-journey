#include <stdio.h>

int main(void) {
    printf("-----------------------\n");
    printf("Please insert your age\n");
    printf("-----------------------\n");
    fflush(stdout);
    int age;
    if (scanf("%d", &age) != 1) return 1;

    int remaining = 18 - age;

    if (age > 18) {
        printf("You are over 18\n");
    } else if (age == 18) {
        printf("You are 18\n");
    } else { // age < 18
        printf("%d years until you are 18\n", remaining);
    }

    return 0;
}
