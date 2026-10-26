
#include <stdio.h>
#include <string.h>

char stack[100], input[100];
int top = -1, i = 0;

int reduce()
{
    // E -> i
    if (top >= 0 && stack[top] == 'i')
    {
        stack[top] = 'E';
        printf("\nReduce E -> i");
        return 1;
    }

    // E -> (E)
    if (top >= 2 &&
        stack[top] == ')' &&
        stack[top - 1] == 'E' &&
        stack[top - 2] == '(')
    {
        top -= 2;
        stack[top] = 'E';
        printf("\nReduce E -> (E)");
        return 1;
    }

    // E -> E*E
    if (top >= 2 &&
        stack[top] == 'E' &&
        stack[top - 1] == '*' &&
        stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        printf("\nReduce E -> E*E");
        return 1;
    }

    // E -> E+E
    if (top >= 2 &&
        stack[top] == 'E' &&
        stack[top - 1] == '+' &&
        stack[top - 2] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        printf("\nReduce E -> E+E");
        return 1;
    }

    return 0;
}

int main()
{
    printf("Enter expression (use i for operands): ");
    scanf("%99s", input);

    printf("\nStack\tInput\tAction\n");

    while (input[i] != '\0')
    {
        stack[++top] = input[i++];

        stack[top + 1] = '\0';
        printf("\n%s\t%s\tShift", stack, input + i);

        while (reduce())
        {
            stack[top + 1] = '\0';
            printf("\nStack: %s", stack);
        }
    }

    while (reduce())
    {
        stack[top + 1] = '\0';
        printf("\nStack: %s", stack);
    }

    if (top == 0 && stack[0] == 'E')
        printf("\n\nString Accepted\n");
    else
        printf("\n\nString Rejected\n");

    return 0;
}

