#include<stdio.h>

#define MAXLINE 100
#define abs(x) ((x) < 0 ? (-x) : (x))

void itoa(int n,char s[],int w);
void reverse(char s[]);

int main()//main function C execution starts here
{
    char s[MAXLINE];
    int n = 15;
    int w = 16;
    itoa(n,s,w);
    printf("%s\n",s);

    return 0;
}

void itoa(int n, char s[], int w)
{
    int i,sign;

    i = 0;
    sign = n;

    do
    {
        
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) > 0);
    
    if(sign < 0 )
        s[i++] = '-';
    while(i < w)
        s[i++] = '_'; // I have used underscore '_' to denote spaces     
    s[i] = '\0';
    /*if sign is less than 0 it is appended with '-' minus and then appended with '\0' null 
    or else s[i]='\0'; is executed  */
    reverse(s);    
     
}

void reverse(char s[])//this function reverses a given input
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
}
