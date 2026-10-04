%{ 
#include<stdio.h>
%}

%%

.*chat.* {printf("String contains chat - NOT ACCEPTED");}
.* {printf("ACCEPTED");}

%%

int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}
