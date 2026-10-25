#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[20][20];
char first[26][20], follow[26][20];
int n;

void add(char set[], char c)
{
    int i;
    for (i = 0; set[i]; i++)
        if (set[i] == c)
            return;

    int len = strlen(set);
    set[len] = c;
    set[len + 1] = '\0';
}

void FIRST(char c);

void firstString(char s[], char result[])
{
    int i, j, eps;

    for (i = 0; s[i]; i++)
    {
        if (!isupper(s[i]))
        {
            add(result, s[i]);
            return;
        }

        FIRST(s[i]);

        eps = 0;
        for (j = 0; first[s[i] - 'A'][j]; j++)
        {
            if (first[s[i] - 'A'][j] == '#')
                eps = 1;
            else
                add(result, first[s[i] - 'A'][j]);
        }

        if (!eps)
            return;
    }

    add(result, '#');
}

void FIRST(char c)
{
    int i;
    char temp[20];

    if (first[c - 'A'][0])
        return;

    for (i = 0; i < n; i++)
    {
        if (prod[i][0] != c)
            continue;

        if (prod[i][3] == '#')
        {
            add(first[c - 'A'], '#');
            continue;
        }

        temp[0] = '\0';
        firstString(prod[i] + 3, temp);

        for (int j = 0; temp[j]; j++)
            add(first[c - 'A'], temp[j]);
    }
}

void FOLLOW(char c)
{
    int i, j, k;
    char temp[20];

    if (c == prod[0][0])
        add(follow[c - 'A'], '$');

    for (i = 0; i < n; i++)
    {
        for (j = 3; prod[i][j]; j++)
        {
            if (prod[i][j] != c)
                continue;

            if (prod[i][j + 1])
            {
                firstString(prod[i] + j + 1, temp);

                for (k = 0; temp[k]; k++)
                    if (temp[k] != '#')
                        add(follow[c - 'A'], temp[k]);

                if (strchr(temp, '#'))
                {
                    if (prod[i][0] != c)
                    {
                        FOLLOW(prod[i][0]);

                        for (k = 0; follow[prod[i][0] - 'A'][k]; k++)
                            add(follow[c - 'A'],
                                follow[prod[i][0] - 'A'][k]);
                    }
                }
            }
            else if (prod[i][0] != c)
            {
                FOLLOW(prod[i][0]);

                for (k = 0; follow[prod[i][0] - 'A'][k]; k++)
                    add(follow[c - 'A'],follow[prod[i][0] - 'A'][k]);
            }
        }
    }
}

int main()
{
    int i;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use -> and # for epsilon):\n");

    for (i = 0; i < n; i++)
        scanf("%19s", prod[i]);

    for (i = 0; i < n; i++)
        FIRST(prod[i][0]);

    for (c = 'A'; c <= 'Z'; c++)
        if (first[c - 'A'][0])
            FOLLOW(c);

    printf("\nFIRST sets:\n");
    for (c = 'A'; c <= 'Z'; c++)
        if (first[c - 'A'][0])
            printf("FIRST(%c) = { %s }\n", c, first[c - 'A']);

    printf("\nFOLLOW sets:\n");
    for (c = 'A'; c <= 'Z'; c++)
        if (first[c - 'A'][0])
            printf("FOLLOW(%c) = { %s }\n", c, follow[c - 'A']);

    return 0;
}
