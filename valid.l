%{
	/* Definition section*/
	#include "y.tab.h"
	extern int yylval;
    
%}

%%
[0-9]+ {
			yylval = atoi(yytext);	
			/* to convert string to int and store to yyval which is a global variable accessible to both lex and yacc prgrm */
			return NUMBER;
	   }

[ \t]+		 ; /*For skipping whitespaces*/

\n		 { return 0; }
.		 { return yytext[0]; }

%%
  