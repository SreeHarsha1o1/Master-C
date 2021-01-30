/* Exercise 4-13
    write a recursive version of the function reverse(s), which reverses the string s in the place
    */
#include<stdio.h>

#define MAXLINE 100

int getline1(char s[], int lim);
void reverse(char s[]);

int main()
{
    int len;
    char s[MAXLINE];

    len = getline1(s, MAXLINE);
    printf("length = %d, string = %s\n",len,s);
    reverse(s);
    printf("reverse string = %s\n",s);

    return 0;
}

int getline1(char s[], int lim)// getline1 function this function gets the input and makes it a string same a in chapter 1
{
    int c,i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i; 
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
    printf("i=%d\n",i);

    ++i;
    
    void reverser(char s[],int n,int len);

    reverser(s,0,i);
}

reverser(char s[], int n, int len)//reverser function useing recursion
{
    int temp ,j;
    j = len - (n + 1);
    if(n < j)
    {
        temp = s[j];
        s[j] = s[n];
        s[n] = temp;
        reverser(s,++n,len);
    }
}
