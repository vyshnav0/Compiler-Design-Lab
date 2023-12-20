#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main(){

    int i,j;
    char ch, str[20];
    char keywords[32][32] =
        {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    FILE *inp, *out;
    inp = fopen("add.c", "r");
    out = fopen("out.txt", "w");
    fprintf(out, "Tokens    Lexemes\n------------------\n");

    while ((ch = fgetc(inp)) != EOF)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            fprintf(out, "%c\tOperators\n",ch);
        }

        else if (ch == '%' || ch == '@' || ch == ',' || ch == ':' || ch == '"' ||
            ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == ';')
        {
            fprintf(out, "%c\tSpecial sym\n",ch);
        }

        else if (isdigit(ch))
        {
            fprintf(out, "%c\tDigits\n",ch);
        }

        else if (isalpha(ch))
        {
            i = 0;
            str[i] = ch;
            ch = fgetc(inp);

            while (isalnum(ch) && i < 19)
            {
                i ++;
                str[i] = ch;
                ch = fgetc(inp);
            }
            str[i+1] = '\0';
            int is_keyword = 0;

            for ( i = 0; i < 32; i++)
            {
                if (strcmp(str, keywords[i]) == 0)
                {
                    is_keyword = 1;
                    break;
                }
            }
            
            if (is_keyword)
                fprintf(out, "%s\tKeyword\n",str);
            else
                fprintf(out, "%s\tIdentifier\n",str);          
        }  
    }

    fclose(inp);
    fclose(out);
}