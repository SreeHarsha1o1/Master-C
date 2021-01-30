/*Exercise 3-2 
Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s . Use a switch . Write a function for the other direction as well, converting escape sequences into the real characters. */
#include<stdio.h>
#define MAX 1000

void escape(char s[], int r);
void hide(char s[]);

int getline1(char s[],int lim)//getline1 function which gets the user input and makes it a string 
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

int main()
{
    int len1,h,r,e;
    char a[MAX];
    r = '\\\\t';
    
    len1 = getline1(a,MAX);
    escape(a,r);
    printf("the escape sequences present in given string are visible %s\n",a);
    hide(a);
    printf("the escape sequences present in given string are not visible %s\n",a);

    return 0;
    
}

void escape(char s[],int r)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        switch(s[i])
        {
            case '\t':
                s[i] = r;
                break;
            case '\n':
                s[i] = '\\\\n';
                break;
            default:
                break;        
        }
        i++;
    }
}

void hide(char s[])
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        switch(s[i])
        {
            case 't':
                s[i] = '\t';
                break;
            case 'n':
                s[i] = '\n';
                break;
            default:
                break;        
        }
        i++;
    }
}
