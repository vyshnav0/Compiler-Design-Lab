#include <stdio.h>
#include <stdlib.h>

void single_comment();
void multi_comment();
FILE *in, *out;

void main(){
    in = fopen("add.c", "r");
    out = fopen("out.c", "w");
    char ch;

    while ((ch = fgetc(in)) != EOF) {
        if (ch == '/')
        {
            char d = fgetc(in);
            if (d == '/')
                single_comment();
            else if (d == '*')
                multi_comment();
            else{
                fputc(ch, out);
                fputc(d, out);
            }
        }
        else
            fputc(ch, out);
    }
    fclose(in);
    fclose(out);
}

void single_comment(){
    char d;
    while ((d = fgetc(in)) != EOF)
    {
        if (d == '\n')
            return;
    }
}

void multi_comment(){
    char d, e;
    while ((d = fgetc(in)) != EOF)
    {
        if (d == '*')
        {
            e = fgetc(in);
            if(e == '/')
                return;
        }
    }
}