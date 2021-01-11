/* Exercise 3-4
 In a two's complement number representation, our version of itoa does not handle the largest negative number,
  that is, the value of n equal to -2^(wordsize-1). Explain why not. 
  Modify it to print that value correctly, regardless of the machine on which it runs. */

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void itoa1(int n, char s[]);
void reverse1(char s[]);

int main()
{
    char s[MAXLINE];
    int a = -2147483648;// this the value of INT_MIN  from exc2-1
    itoa1(a,s);
    printf("%s\n",s);

    return 0;
}

void itoa1(int n, char s[])// functions n to charecters in s
{
    int i,sign;
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
        s[i++] = sign * (n % 10) + '0';
        //here s[0] is udated with the last value
        // of n that is 8 and so on the all the values of n is updated to s array in reverse 
    } while ((n /= 10) != 0);

    if(sign < 0)
    {
        s[i++] = '-';//here the s array is given '-' minus value so now the s[] contains 8463847412-
     }
    s[i] = '\0';//s is ssigned with null i.e s[] = 8 4 6 3 8 4 7 4 1 2 - \0
    
    reverse1(s);
    
}

void reverse1(char s[])//this function reverse the given charecter array 
{
    int len = strlen(s);
    int i, j, k;

    for (i = 0, j = len - 1; i < j; i++, j--) 
    {
        k = s[i];
        s[i] = s[j];
        s[j] = k;
    }

}
