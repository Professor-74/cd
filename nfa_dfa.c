
#include <stdio.h>

int n, m;
int nfa[20][10][20];
int dfa[100][10];
int states[100][20];
int count = 1;

int same(int a[], int b[]) {
    int i;
    for (i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int find(int s[]) {
    int i;
    for (i = 0; i < count; i++)
        if (same(states[i], s))
            return i;
    return -1;
}

int main() {
    int i, j, k, x, t;
    int temp[20];

    printf("Enter number of NFA states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    printf("Enter transitions:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("q%d on symbol %d: ", i, j);
            scanf("%d", &t);

            for (k = 0; k < t; k++) {
                scanf("%d", &x);
                nfa[i][j][x] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
        states[0][i] = 0;

    states[0][0] = 1;

    for (i = 0; i < count; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++)
                temp[k] = 0;

            for (k = 0; k < n; k++) {
                if (states[i][k]) {
                    for (x = 0; x < n; x++) {
                        if (nfa[k][j][x])
                            temp[x] = 1;
                    }
                }
            }

            int p = find(temp);

            if (p == -1) {
                p = count;
                for (k = 0; k < n; k++)
                    states[count][k] = temp[k];
                count++;
            }

            dfa[i][j] = p;
        }
    }

    printf("\nDFA Transition Table:\n");

    for (i = 0; i < count; i++) {
        printf("D");
        for (j = 0; j < n; j++)
            if (states[i][j])
                printf("q%d", j);

        printf(" : ");

        for (j = 0; j < m; j++)
            printf("%d ", dfa[i][j]);

        printf("\n");
    }

    return 0;
}


