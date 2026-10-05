
#include <stdio.h>

int main() {
    int n, m, e;
    int a[20][20][20], ep[20][20] = {0};
    int i, j, k, t;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            for (k = 0; k < n; k++)
                a[i][j][k] = 0;

    printf("Enter number of epsilon transitions: ");
    scanf("%d", &e);

    printf("Enter epsilon transitions (from to):\n");
    for (i = 0; i < e; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ep[x][y] = 1;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            printf("Enter number of transitions from %d on symbol %d: ", i, j);
            scanf("%d", &t);
            printf("Enter destination states: ");
            for (k = 0; k < t; k++) {
                int x;
                scanf("%d", &x);
                a[i][j][x] = 1;
            }
        }

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            if (ep[i][k])
                for (j = 0; j < n; j++)
                    if (ep[k][j])
                        ep[i][j] = 1;

    printf("\nNFA without epsilon transitions:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int r[20] = {0};

            for (k = 0; k < n; k++)
                if (ep[i][k] || i == k)
                    for (t = 0; t < n; t++)
                        if (a[k][j][t])
                            r[t] = 1;

            printf("q%d -- %d --> { ", i, j);
            for (k = 0; k < n; k++)
                if (r[k])
                    printf("q%d ", k);
            printf("}\n");
        }
    }

    return 0;
}


