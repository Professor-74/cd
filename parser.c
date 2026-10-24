
#include <stdio.h>
#include <string.h>

char stack[100], input[100];
int top = -1, i = 0;

char precedence(char a, char b)
{
    if (a == '$') {
        if (b == '$') return '=';
        if (b == '+' || b == '*' || b == '(' || b == 'i')
            return '<';
    }

    if (a == '+') {
        if (b == '+') return '>';
        if (b == '*') return '<';
        if (b == '(' || b == 'i') return '<';
        if (b == ')' || b == '$') return '>';
    }

    if (a == '*') {
        if (b == '+' || b == '*' || b == ')' || b == '$')
            return '>';
        if (b == '(' || b == 'i') return '<';
    }

    if (a == '(') {
        if (b == ')') return '=';
        if (b == '+' || b == '*' || b == '(' || b == 'i')
            return '<';
    }

    if (a == ')') {
        if (b == '+' || b == '*' || b == ')' || b == '$')
            return '>';
    }

    return ' ';
}

char topTerminal()
{
    int j;

    for (j = top; j >= 0; j--) {
        if (stack[j] != 'E')
            return stack[j];
    }

    return '$';
}

int reduce()
{
    // i -> E
    if (top >= 0 && stack[top] == 'i') {
        stack[top] = 'E';
        return 1;
    }

    // E+E -> E or E*E -> E
    if (top >= 2 &&
        stack[top] == 'E' &&
        (stack[top - 1] == '+' || stack[top - 1] == '*') &&
        stack[top - 2] == 'E') {

        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        return 1;
    }

    // (E) -> E
    if (top >= 2 &&
        stack[top] == ')' &&
        stack[top - 1] == 'E' &&
        stack[top - 2] == '(') {

        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        return 1;
    }

    return 0;
}

int main()
{
    char a, b, relation;

    printf("Enter expression (use i for identifier): ");
    scanf("%99s", input);

    if (strlen(input) > 95) {
        printf("Expression too long\n");
        return 0;
    }

    strcat(input, "$");
    stack[++top] = '$';
    stack[top + 1] = '\0';

    printf("\nSTACK\tINPUT\tACTION\n");

    while (1) {
        a = topTerminal();
        b = input[i];

        if (a == '$' && b == '$') {
            if (top == 1 && stack[1] == 'E') {
                printf("%s\t%s\tACCEPT\n", stack, input + i);
                return 0;
            }

            printf("String Rejected\n");
            return 0;
        }

        relation = precedence(a, b);

        if (relation == '<' || relation == '=') {
            if (b == '$') {
                printf("String Rejected\n");
                return 0;
            }

            stack[++top] = b;
            stack[top + 1] = '\0';
            i++;

            printf("%s\t%s\tSHIFT\n", stack, input + i);

            if (b == 'i') {
                reduce();
                printf("%s\t%s\tREDUCE i to E\n",
                       stack, input + i);
            }
        }
        else if (relation == '>') {
            if (reduce()) {
                printf("%s\t%s\tREDUCE\n", stack, input + i);
            }
            else {
                printf("String Rejected\n");
                return 0;
            }
        }
        else {
            printf("String Rejected\n");
            return 0;
        }
    }
}

