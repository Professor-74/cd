%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyparse(void);
void yyerror(const char *s);
%}

%token FOR ID NUM INC DEC

%%

statement:
    FOR '(' initialization ';' condition ';' increment ')'
    {
        printf("Valid FOR statement\n");
    }
    ;

initialization:
    ID '=' NUM
    ;

condition:
    ID '<' NUM
    ;

increment:
    ID INC
    | ID DEC
    ;

%%

void yyerror(const char *s)
{
    printf("Invalid FOR statement\n");
}

int main(void)
{
    printf("Enter a FOR statement:\n");
    yyparse();
    return 0;
}
