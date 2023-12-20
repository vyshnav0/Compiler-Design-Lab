%{
#include<stdio.h>
int word = 0, space = 0, line = 0, ch = 0;
%}

%%
[\n] {
    line ++;
    ch += yyleng;
}
[ \t] {
    space ++;
    ch += yyleng;
}
[^\t\n ] {
    word ++;
    ch += yyleng;
}
%%

int yywrap(){
    return 1;
}

int main(){
    printf("Enter the sentence: \n");
    yylex();
    printf("Lines: %d\nWords: %d\nSpaces: %d\nCharacters: %d\n",line,word, space, ch);
    return 0;
}