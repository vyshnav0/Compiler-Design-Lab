#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*
    S=AbCd
    A=Cf
    A=a
    C=gE
    E=h
*/
void first(char);
void follow(char);

int n,m=0,i,j,k;
char prod[10][10],f[10];

void first(char c){
    if(!isupper(c)){    //if c is a terminal
        f[m++]=c;
    }
    for(k=0;k<n;k++){       // non terminal c
        if(prod[k][0]==c){      // if A is c, then check if A->
            if(islower(prod[k][2])){        // check for A->something, something will be prod[k][2]
                f[m++]=prod[k][2];
            }else{                  // like  A->Bc
                first(prod[k][2]);      // find first of B
            }
        }
    }
}

void follow(char c){
    if(prod[0][0]==c){      // if c is Start symbol
        f[m++]='$';
    }
    for(i=0;i<n;i++){
        for(j=2;j<strlen(prod[i]);j++){
            if(prod[i][j]==c){
                if(prod[i][j+1]!='\0'){
                    first(prod[i][j+1]);
                }
                if(prod[i][j+1]=='\0' && c!=prod[i][0]){
                    follow(prod[i][0]);
                }
            }
        }
    }
}

int main(){
    int z;
    char c,ch;
    printf("Enter the no of prooductions = ");
    scanf("%d",&n);
    printf("Enter the productions\n");
    for(i=0;i<n;i++){
        scanf("%s%c",prod[i],&ch);
    }

    do{
        m=0;
        printf("Enter the elemets whose first & follow is to be found : ");
        scanf("%c",&c);
        first(c);
        printf("First(%c) = { ",c);
        for(i=0;i<m;i++){
            printf("%c ",f[i]);
        }printf("}\n");

        strcpy(f," ");
        m=0;
        follow(c);
        printf("Follow(%c) = { ",c);
        for(i=0;i<m;i++){
            printf("%c ",f[i]);
        }printf("}\n");

        printf("Continue(0/1) = ");
        scanf("%d%c",&z,&ch);
    }while(z==1);
    
    return 0;
}

