#include <stdio.h>

#define MAX 20

int n;                          // Number of states
int eTransition[MAX][MAX];      // Epsilon transition matrix
int visited[MAX];

// Function to find epsilon closure
void epsilonClosure(int state)
{
    int i;

    // If already visited, return
    if (visited[state])
        return;

    visited[state] = 1;

    // Print current state
    printf("q%d ", state);

    // Visit all states connected by epsilon transition
    for (i = 0; i < n; i++)
    {
        if (eTransition[state][i] == 1)
        {
            epsilonClosure(i);
        }
    }
}

int main()
{
    int i, j;
    int edges;
    int from, to;

    printf("Enter the number of states: ");
    scanf("%d", &n);

    // Initialize transition matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            eTransition[i][j] = 0;
        }
    }

    printf("Enter the number of epsilon transitions: ");
    scanf("%d", &edges);

    printf("Enter epsilon transitions (from to):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &from, &to);
        eTransition[from][to] = 1;
    }

    printf("\nEpsilon Closures of all states:\n\n");

    for (i = 0; i < n; i++)
    {
        // Reset visited array
        for (j = 0; j < n; j++)
        {
            visited[j] = 0;
        }

        printf("ε-Closure(q%d) = { ", i);
        epsilonClosure(i);
        printf("}\n");
    }

    return 0;
}
