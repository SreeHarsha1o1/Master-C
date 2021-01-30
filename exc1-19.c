/*Exercise 1-19
write a function reverse(s) that reverse the charecter string s. use it to write a program that reverses its input lines at a time*/
#include<stdio.h>
#define MAXLINE 1000

int getline1(char s[],int lim);
int reverse(char s[], int len);

int main()
{
    int len; int r;
    char line[MAXLINE];

    while((len =getline1(line ,MAXLINE)) > 0)
        if((r=reverse(line ,len)) > 0 )//calling reverse function
            printf("the reversed line is %s",line);
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

int reverse(char s[], int len)//this function reverses a given input
{
    int i,j;
    char temp;
    i = 0;j=0;
    while( s[i] != '\0')
        ++i;
    --i;
    if(s[i] == '\n')
        --i;
    
    while(j < i)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        ++j;
        --i;
    }
        
    
    printf("reversed string is %s\n",s);
    return j;
}
