#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_STATES 4

int transitions[NUM_STATES][2][2] = {
    {{1, -1}, {3, -1}}, // State 0: 'a' transitions to State 1, 'b' to State 3
    {{-1, 2}, {-1, -1}}, // State 1: 'b' transitions to State 2
    {{-1, -1}, {-1, -1}}, // State 2: No transitions
    {{-1, -1}, {-1, -1}} // State 3: No transitions
};

void calculateEpsilonClosure(int state, bool visited[], int epsilonClosure[]) {
    visited[state] = true;
    epsilonClosure[state] = 1;

    int epsilonTransitions[2] = {transitions[state][0][1], transitions[state][1][1]};

    for (int i = 0; i < 2; i++) {
        if (epsilonTransitions[i] != -1 && !visited[epsilonTransitions[i]]) {
            calculateEpsilonClosure(epsilonTransitions[i], visited, epsilonClosure);
        }
    }
}

int main() {
    int epsilonClosures[NUM_STATES][NUM_STATES] = {0};

    for (int i = 0; i < NUM_STATES; i++) {
        bool visited[NUM_STATES] = {false};
        calculateEpsilonClosure(i, visited, epsilonClosures[i]);
    }

    printf("e-Closures for each state:\n");
    for (int i = 0; i < NUM_STATES; i++) {
        printf("e-Closure(%d): ", i);
        for (int j = 0; j < NUM_STATES; j++) {
            if (epsilonClosures[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}

