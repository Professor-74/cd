
#include <stdio.h>
#include <string.h>

int main()
{
    char line[100];
    char op[10], arg1[20], arg2[20], result[20];
    int n, i;

    printf("Enter number of three-address instructions: ");
    scanf("%d", &n);

    getchar();  // Consume newline after n

    printf("Enter instructions (example: t1 = a + b)\n");

    printf("\n8086 Assembly Code:\n");

    for (i = 0; i < n; i++)
    {
        fgets(line, sizeof(line), stdin);

        if (sscanf(line, "%19s = %19s %9s %19s",
                   result, arg1, op, arg2) != 4)
        {
            printf("Invalid instruction!\n");
            return 1;
        }

        if (strcmp(op, "+") == 0 ||
            strcmp(op, "-") == 0)
        {
            printf("MOV AX, %s\n", arg1);

            if (strcmp(op, "+") == 0)
                printf("ADD AX, %s\n", arg2);
            else
                printf("SUB AX, %s\n", arg2);

            printf("MOV %s, AX\n\n", result);
        }
        else if (strcmp(op, "*") == 0)
        {
            printf("MOV AX, %s\n", arg1);
            printf("MOV BX, %s\n", arg2);
            printf("MUL BX\n");
            printf("MOV %s, AX\n\n", result);
        }
        else if (strcmp(op, "/") == 0)
        {
            printf("MOV AX, %s\n", arg1);
            printf("CWD\n");
            printf("MOV BX, %s\n", arg2);
            printf("IDIV BX\n");
            printf("MOV %s, AX\n\n", result);
        }
        else
        {
            printf("Unsupported operator: %s\n", op);
        }
    }

    return 0;
}

