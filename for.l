%{
#include "y.tab.h"
%}

%%

"for"       { return FOR; }
"("         { return '('; }
")"         { return ')'; }
";"         { return ';'; }
"="         { return '='; }
"++"        { return INC; }
"--"        { return DEC; }

[A-Za-z][A-Za-z0-9]*    { return ID; }
[0-9]+                  { return NUM; }

[ \t\n]                 ;
.                       { return yytext[0]; }

%%

int yywrap(void)
{
    return 1;
}
