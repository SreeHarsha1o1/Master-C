/*Exercise 4-3
    Extend atof to handle scientific notation in the form 123.45-e6 where a floating-point number may be followed by e or E
and an optionally signed exponent. */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXLINE 100

double atof1(char s[]);

int main()
{
    double sum;
    char line[MAXLINE];
    int getline1(char line[],int max);

    sum =0;
    while(getline1(line,MAXLINE) > 0)
        printf("\t%g\n", sum += atof1(line));
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

double atof1(char s[])
{
    double val, power;
    int exp,i,sign;

    for( i= 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]);i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]);i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power; 

    if(s[i] == 'e' || s[i] == 'E')
    {
        sign = (s[++i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        if(sign == 1)
            while(exp-- > 0)
                val *= 10; //positive exponent
        else
            while(exp-- > 0)
                val *= 10; //negative exponent

    }
    return val;   
}
