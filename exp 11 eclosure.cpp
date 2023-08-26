#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_STATES 5

#define MAX_EPSILON_STATES 5

int transitions[NUM_STATES][2][MAX_EPSILON_STATES] = {
    {{1, 2, -1, -1, -1}, {-1, -1, -1, -1, -1}}, // State 0: e to State 1 and 2
    {{-1, -1, 3, -1, -1}, {-1, -1, -1, -1, -1}}, // State 1: e to State 3
    {{-1, -1, -1, 4, -1}, {-1, -1, -1, -1, -1}}, // State 2: e to State 4
    {{-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}}, // State 3: No transitions
    {{-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}}  // State 4: No transitions
};

void calculateEpsilonClosure(int state, bool visited[], int epsilonClosure[]) {
    visited[state] = true;
    epsilonClosure[state] = 1;

    for (int i = 0; i < MAX_EPSILON_STATES; i++) {
        int nextState = transitions[state][0][i];
        if (nextState != -1 && !visited[nextState]) {
            calculateEpsilonClosure(nextState, visited, epsilonClosure);
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

