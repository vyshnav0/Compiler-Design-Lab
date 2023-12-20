#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}

void threeadd(char *str){
    top=-1;
    int t1=90;
    char t2,t3;
    for(int i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            push(str[i]);
        }else{
            t3=pop();
            t2=pop();
            printf("%c := %c %c %c\n",t1,t2,str[i],t3);
            push(t1--);
        }
    }
}
int main() {
    char expression[MAX];
    printf("Enter an simple expression: ");
    scanf("%s", expression);
    threeadd(expression);
    return 0;
}