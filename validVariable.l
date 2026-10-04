%{
#include "y.tab.h"
%}

%%

[A-Za-z][A-Za-z0-9]* {return VALID;}
[0-9][A-Za-z0-9]*  {return INVALID;}
[\t]+ ;
. {return INVALID;}

%%

int yywrap()
{
	return 1;
}
