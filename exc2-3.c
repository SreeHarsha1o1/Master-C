/*Exercise 2-3
write a function htoi(s),which coverts a string of hexadecimal digits including 0x and 0X into its equivalent integer value
the allowable digits are 0 through 9, a through f and A through F*/ 
#include<stdio.h>

#define MAX 100
#define NO 0
#define YES 1

int htoi(char s[]);

int main()
{
    int a,i,c;
    int lim = MAX;
    char s[MAX];

    printf("\nPlease enter an hexa decimal value eg:0x7f or 0X7F\n");

    for(i = 0; i <= (lim - 1) && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        s[i] = c;
    }
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    a = htoi(s );
    printf("%d\n",a);
    return 0;
}

int htoi(char s[])// function converts hexadecimal values to its respective integers i.e ASCII values 
{
    int i,n,j,k;

    i=0;
    if(s[i] == '0');
        ++i;
    if(s[i] == 'x' || s[i] == 'X') 
        ++i;    

    // if conditions checks if the first charecter is a '0' and second charecter is 'x' or 'X' and incremets the i value 
    //i value is for position in array
    
    n = 0; k = YES;
    
    for( ; k == YES; ++i){ 
        if(s[i] >= '0' && s[i] <= '9')
            j = s[i] -'0';
        else if(s[i] >= 'a' && s[i] <= 'f')
            j = s[i] - 'a' + 10;
        else if(s[i] >= 'A' && s[i] <= 'F')
            j = s[i] - 'A' + 10;
        else
        {
            k = NO;
        }
    
        if( k == YES)             
            n = 16 * n + j;
    }
    
    return n;    
}
