%{
    #include <stdio.h>
%}

%x COMMENT

%%
#include {printf("%s: Preprocessor directive\n",yytext);}
void|int|float|double|for|while|break|continue|return|if|else|signed|unsigned|struct|typedef|long|switch|case|char|short|enum|extern|volatile|do|static {
    printf("%s: Keyword\n",yytext);
}
\"[^\n\"]*\" {printf("%s: String\n",yytext);}
[]{(,;)}] {printf("%s: Special char\n",yytext);}
[ \t\n]

"//" {BEGIN(COMMENT);}
<COMMENT>[^\n]*
<COMMENT>[\n] {BEGIN(INITIAL);}

[a-zA-Z_][a-zA-Z0-9]* {printf("%s: Identifiers\n",yytext);}
. {printf("%s: Operator\n",yytext);}
%%

int yywrap(){
    return 1;
}

int main(){
    FILE *fp;
    fp = fopen("add.c", "r");
    yyin = fp;
    yylex();
    fclose(fp);
    return 0;
}