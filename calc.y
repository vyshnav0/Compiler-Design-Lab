%{
    #include <stdio.h>
    int yylex();
    int yyerror();
%}

%token NUMBER ID

%left '+' '-'
%left '*' '/'
%left '(' ')'

%%
E : T {
    printf("\nResult: %d\n",$$);
    return 0;
}

T :
    T '+' T {$$ = $1 + $3;}
    | T '-' T {$$ = $1 - $3;}
    | T '*' T {$$ = $1 * $3;}
    | T '/' T {$$ = $1 / $3;}
    | '-' ID {$$ = -$2;}
    | '-' NUMBER {$$ = -$2;}
    | ID {$$ = $1;}
    | NUMBER {$$ = $1;}
%%

int main(){
    printf("Enter the expression: ");
    yyparse();
}

int yyerror(){
	printf("\nExpression is invalid\n");
}