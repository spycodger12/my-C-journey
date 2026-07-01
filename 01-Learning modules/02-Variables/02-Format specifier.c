//* FORMAT SPECIFIERS
/*
Format specifiers are used with printf() to print variables
A format specifier tells C what kind of value will be printed
The format specifier starts with percentage sign '%' folowed by a letter
*/

// example
int myNum = 15;
printf("%d", myNum); // Outputs 15



//* Print multiple types in a single print()

int myNum = 10;
char myLetter = 'A';
printf("The number is %d and the letter is %c", myNum, myLetter); //Outputs The number is 10 and the letter is A

//* If you dont want to use variables
printf("The number is %d and the letter is %c", 10, 'A');