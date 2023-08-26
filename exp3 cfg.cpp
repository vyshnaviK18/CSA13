/*3.	Write a C program to check whether a given string belongs to the language defined by a Context Free Grammar (CFG)
S -> 0A1	
A -> 0A | 1A | $
TWO		NONTERNIMALS	GRAMMAR*/
#include <stdio.h>
#include <string.h>

int isSValid(char *string, int start, int end);
int isAValid(char *string, int start, int end);

int isAValid(char *string, int start, int end) {
    if (start > end) {
        return 1; 
    } else if (string[start] == '0' || string[start] == '1') {
        return isAValid(string, start + 1, end);
    } else {
        return 0;
    }
}

int isSValid(char *string, int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        if (string[i] == '0') {
            int a_end = i - 1;
            if (isAValid(string, start + 1, a_end) && string[i + 1] == '1') {
                return 1;
            }
        }
    }
    return 0;
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

