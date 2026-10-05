
#include <stdio.h>

int main() {
    int n, m, d[50][10];
    int final[50] = {0};
    int mark[50][50] = {0};
    int group[50];
    int i, j, k, x, y, f, nf;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    printf("Enter transition table:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("q%d on %d: ", i, j);
            scanf("%d", &d[i][j]);
        }
    }

    printf("Enter number of final states: ");
    scanf("%d", &f);

    printf("Enter final states: ");
    for (i = 0; i < f; i++) {
        scanf("%d", &x);
        final[x] = 1;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (final[i] != final[j])
                mark[i][j] = mark[j][i] = 1;
        }
    }

    do {
        nf = 0;

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (!mark[i][j]) {
                    for (k = 0; k < m; k++) {
                        x = d[i][k];
                        y = d[j][k];

                        if (x != y && mark[x][y]) {
                            mark[i][j] = mark[j][i] = 1;
                            nf = 1;
                            break;
                        }
                    }
                }
            }
        }
    } while (nf);

    for (i = 0; i < n; i++)
        group[i] = -1;

    int g = 0;

    for (i = 0; i < n; i++) {
        if (group[i] == -1) {
            group[i] = g;

            for (j = i + 1; j < n; j++) {
                if (!mark[i][j])
                    group[j] = g;
            }

            g++;
        }
    }

    printf("\nMinimized DFA:\n");

    for (i = 0; i < g; i++) {
        printf("Group %d = { ", i);

        for (j = 0; j < n; j++)
            if (group[j] == i)
                printf("q%d ", j);

        printf("}\n");
    }

    printf("\nTransition Table:\n");

    for (i = 0; i < g; i++) {
        printf("Group %d: ", i);

        for (j = 0; j < m; j++) {
            x = -1;

            for (k = 0; k < n; k++) {
                if (group[k] == i) {
                    x = group[d[k][j]];
                    break;
                }
            }

            printf("%d ", x);
        }

        printf("\n");
    }

    printf("\nFinal Groups: ");
    for (i = 0; i < g; i++) {
        for (j = 0; j < n; j++) {
            if (group[j] == i && final[j]) {
                printf("%d ", i);
                break;
            }
        }
    }

    printf("\n");

    return 0;
}


