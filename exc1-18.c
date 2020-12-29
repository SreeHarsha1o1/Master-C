/*Exercise 1-18
write a program to remove trailing blanks and tabs from each line of input and to delete entirely blank lines.*/
#include<stdio.h>
#define MAXLINE 1000

int getline1(char s[],int lim);
int rem(char s[]);

int main()
{
    int len; int r;
    char line[MAXLINE];

    while((len =getline1(line ,MAXLINE)) > 0)
        if((r=rem(line )) > 0 )//calling remove function named rem
            printf("the corrected line is %s",line);
    return 0;        
}

int getline1(char s[],int lim)//getline function which inputs a given line and returns the length
{
    int c,i;

    for(i=0;i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
    }    
    s[i] = '\0';
    return i;
}

int rem(char a[])//removes the trailing blanks and tabs
{
    int i;

    i=0;
    while(a[i] != '\n')//increments the i value till it reaches the index of '\n' 
        ++i;
    --i;//backes one index back 
    while(i>=0 && (a[i] == ' ' || a[i] == '\t')){
        --i;
        }

    
    if(i>=0){
        ++i;
        a[i] = '\n';
        ++i;
        a[i] = '\0';
    } 
    //printf("%s",a );
    return i;       
}
