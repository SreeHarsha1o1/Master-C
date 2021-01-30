#include<stdio.h>

#define MAXLINE 100

void itob(int n,char s[],int b);
void reverse(char s[]);

int main()//main function C execution starts here
{
    char s[MAXLINE];
    int n = 10;
    int b = 16;
    itob(n,s,b);
    printf("%s\n",s);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i,j,sign;

    i = 0;

    if(n < 0)
    {
        sign = -1;
    }
    else
    {
        sign = 1;
    }

    do
    {
        j = n % b;
        s[i++] = (j <= 9) ? j+'0' : j + 'a' - 10;
    } while ((n /= b) > 0);
    /* j = n%b gives the reminder if n is less than b then it gives the n value itself
        s[i++] = (j <= 9) ? j+'0' : j + 'a' - 10; here s[i] =  (j <= 9) ? j+'0' : j + 'a' - 10; is done first 
        after that i is incremented
        (n /= b) > 0 the while condition is checked if its not true then the loo is exited   */
    if(sign < 0 )
        s[i++] = '-';
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
