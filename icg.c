
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
char result[100];
int i = 0, temp = 1;

void E();
void T();
void F();

void newtemp(char op, char left[], char right[],
             char res[])
{
    sprintf(res, "t%d", temp);

    printf("%s = %s %c %s\n",
           res, left, op, right);

    temp++;
}

void E()
{
    char left[20], right[20], res[20];

    T();
    strcpy(left, result);

    while (expr[i] == '+' || expr[i] == '-')
    {
        char op = expr[i++];
        T();
        strcpy(right, result);

        newtemp(op, left, right, res);
        strcpy(left, res);
    }

    strcpy(result, left);
}

void T()
{
    char left[20], right[20], res[20];

    F();
    strcpy(left, result);

    while (expr[i] == '*' || expr[i] == '/')
    {
        char op = expr[i++];
        F();
        strcpy(right, result);

        newtemp(op, left, right, res);
        strcpy(left, res);
    }

    strcpy(result, left);
}

void F()
{
    if (expr[i] == '(')
    {
        i++;
        E();
        i++;  // Skip closing parenthesis
    }
    else
    {
        int j = 0;

        while (isalnum(expr[i]))
            result[j++] = expr[i++];

        result[j] = '\0';
    }
}

int main()
{
    printf("Enter an expression: ");
    scanf("%99s", expr);

    printf("\nIntermediate Code:\n");
    E();

    return 0;
}

