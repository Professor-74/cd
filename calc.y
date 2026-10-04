%{
#include<stdio.h>
int yylex(void);
int yyparse(void);
void yyerror(const char*s);

%}

%token NUMBER

%%

calculation:
	
	expression{printf("Result:%d\n", $1);}
	;
	
expression:

	expression '+' term {$$ = $1 + $3;}
	| expression '-' term {$$ = $1 - $3;}
	| term {$$ = $1;}
	;
	
term:

	term '*' factor {$$ = $1*$3;}
	| term '/' factor {$$ = $1/$3;}
	| factor {$$ = $1;}
	;
	
factor:

	'('expression')' {$$ = $2;}
	| NUMBER {$$ = $1;}
	;	
%%

void yyerror(const char*s)
{
	fprintf(stderr, "Error: %s\n", s);
}

int main(void){
	
	printf("Enter an expression:\t");
	yyparse();
	return 0;
}

