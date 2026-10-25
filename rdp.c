
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char input[100];
int i = 0;

void E();
void T();
void F();

void E()
{
    T();

    while (input[i] == '+' || input[i] == '-')
    {
        i++;
        T();
    }
}

void T()
{
    F();

    while (input[i] == '*' || input[i] == '/')
    {
        i++;
        F();
    }
}

void F()
{
    if (isalnum(input[i]))
    {
        i++;
    }
    else if (input[i] == '(')
    {
        i++;
        E();

        if (input[i] == ')')
            i++;
        else
        {
            printf("Invalid Expression\n");
            exit(0);
        }
    }
    else
    {
        printf("Invalid Expression\n");
        exit(0);
    }
}

int main()
{
    printf("Enter an expression: ");
    scanf("%99s", input);

    E();

    if (input[i] == '\0')
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}

