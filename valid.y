%{
	/* Definition section */
#include <stdio.h>
int yylex();
int yyerror();
%}

%token NUMBER ID
// setting the precedence
// and associativity of operators, bottom and left one has hisgest precedence
%left '+' '-'
%left '*' '/'
%left '(' ')'
/* Rule Section */
%%
/* when T becomes a single token E is printed */
E : T	 {
				printf("\nExpression is valid.\n");
				return 0;
			}

T :
	T '+' T { $$ = $1 + $3; }
	| T '-' T { $$ = $1 - $3; }		
	/* above is the same as T-> T-T, here $$ is root T, = is ->, $1 and $3 are 1st and third params, here T and T */
	| T '*' T { $$ = $1 * $3; }
	| T '/' T { $$ = $1 / $3; }
	| '(' T ')' { $$ = $2; }
	| '-' NUMBER { $$ = -$2; }
	| '-' ID { $$ = -$2; }
	| NUMBER { $$ = $1; }
	| ID { $$ = $1; };
%%

int main() {
	printf("Enter the expression: ");
	yyparse();			/* for scanning the input and returning the next token */
}

/* For printing error messages */
int yyerror(char* s) {
	printf("\nExpression is invalid\n");
}
	