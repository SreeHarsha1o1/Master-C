/*Exercise 4-1
    Write the function strndex(s,t), which returns the position of the 
    rightmost occurence of t in s,or -1 if there is none */
#include<stdio.h>

#define MAXLINE 1000

int getline1(char line[], int max);
int strindex(char source[],char searchfor[]);// function declerations 
int strrndex(char s[], char t[]);

char pattern[] = "ould";// golbar variable pattern that holds the string "ould"

int main()
{
    char line[MAXLINE];// charecter array called line which holds the 1000 charecters
    int found = 0;//variable found of type integers it holds only numbers except decimal 
    int pos;

    while(getline1(line,MAXLINE) > 0)//while loop that is calling getline1 function and if its greater than '0' it enters the loop
        if(pos = strrndex(line, pattern) >= 0)//strndex function call inside if condition
        {
            strindex(line, pattern);//strindex function call
            printf("the Position is %d\n",pos);//printing the position of occurence of ould
            printf("%s", line);//printing of line
            found++;// incrementing found
        }

    return found; 
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

int strindex(char s[], char t[])// returns index of t in s , -1 if none
{
    int i,j,k;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = 1,k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrndex(char s[], char t[])// returns the position of ould 
{
    int i,j,k,pos;
    pos = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = 1,k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return (pos = i);
    }
    return -1;
}
