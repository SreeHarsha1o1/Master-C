/*Exercise 1-17
wrie a program to print all input lines that are longer than 80 charecters*/ 
#include<stdio.h>
#define MAXLINE 1000

int getline1(char s[],int lim);//function prototype
int main()
{
    int len;
    int max;
    char line[MAXLINE];
    
    max = 80;
    while((len = getline1(line,MAXLINE)) > 0)
        if(len > max){//here it checks for length stored in len is greater than 80 and only if the length is more than 80 next statement is executed 
            printf("length=%d\n string=%s\n",len ,line);
        }
    
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

