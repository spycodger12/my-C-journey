# include <stdio.h>
# include <string.h>



int main() {
    char userInput[100];

    printf("Type something\n"); // ask prompt
    printf("---------------\n");

    scanf("%99s", userInput);

    if (strcmp(userInput, "hello") == 0) {
        printf("Hello!\n");
    } else {
        printf("You wrote: %s\n", userInput);
    }

//    printf("You wrote: %s\n", userInput);
    return 0;
}

// variables are like this: int NAME = value;
// this is a comment