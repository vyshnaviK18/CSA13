#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_STATES 3

int transitions[NUM_STATES][2] = {
    {1, -1}, // State 0: 'o' transition to State 1
    {-1, 2}, // State 1: Any symbol transition to State 2
    {-1, -1} // State 2: '1' transition to Accepting State
};

#define ACCEPTING_STATE 2

bool simulateNFA(char *input) {
    int currentState = 0;
    int inputLength = strlen(input);

    for (int i = 0; i < inputLength; i++) {
        char symbol = input[i];
        int symbolIndex = (symbol == 'o') ? 0 : 1;

        int nextState1 = transitions[currentState][0];
        int nextState2 = transitions[currentState][1];

        if (nextState1 != -1) {
            currentState = nextState1;
        }

        if (nextState2 != -1) {
            currentState = nextState2;
        }
    }

    return currentState == ACCEPTING_STATE;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}

