/*5.	Write a C program to check whether a given string
 belongs to the language defined by a Context Free Grammar (CFG)
S->0S0 | A
A -> 1A | $
TWO		NONTERNIMALS	GRAMMAR*/

#include <stdio.h>
#include <string.h>

int isAValid(char *string, int start, int end);
int isSValid(char *string, int start, int end);

int isAValid(char *string, int start, int end) {
    if (start > end) {
        return 1; 
    } else if (string[start] == '1') {
        return isAValid(string, start + 1, end);
    } else {
        return 0;
    }
}

int isSValid(char *string, int start, int end) {
    if (start > end) {
        return 1; 
    } else if (string[start] == '0' && string[end] == '0') {
        return isSValid(string, start + 1, end - 1);
    } else {
        return isAValid(string, start, end);
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isSValid(input, 0, strlen(input) - 1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }

    return 0;
}

