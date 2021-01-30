/* Exercise 5-2
    write getfloat, the floating-point analog of getint what type does getfloat return as its floating value
    */
#include<stdio.h>
#include<ctype.h>

#define SIZE 10

int getch(void);
void ungetch(int);
float getfloat(float *pn);


int main()
{
    int n;float a[SIZE];

    for(n = 0; n < SIZE; n++)//makes elements of array to zero
        a[n] = 0;
    
    for(n = 0; n < SIZE && getfloat(&a[n]) != EOF; n++)//calls function getint and gives address of element of array eg: first n=0, a[n] is a[0], &a[0] address of a[0] is sent as an argument
        ;

    for(n = 0; n < SIZE; n++)//prints the value of n and all the elements of array
        printf("vlaue of n:%d\tarray contains: %f\n",n,a[n]);

    return 0;
}

float getfloat(float *pn)
{
    int c;
    float power, sign;

    while (isspace(c = getch()))
        printf("printing space\n");//print state ments are given for understanding purpose
    
    printf("outside while c value:%d\n",c);

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);//not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    
    if(c == '+' || c == '-')
        c = getch();
    
    for(*pn = 0.0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');//for input like 123 or 12 etc *pn is updated
                                    // takes integer part to *pn
    if(c == '.') 
        c = getch();    // checks for decimal point in this case '.'
    
    for(power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;          // takes fractional part  
    }
    //printf("\nspaces\n");
    *pn *= (sign / power);
    
    if(c != EOF)
        ungetch(c);
    
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for unget
int bufp = 0;   //next free position in buff

int getch(void) // get a (popssibly pushed back) charecter
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) //push charecter back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many charecters\n");
    else
        buf[bufp++] = c;

   // printf("bufp: %d, pushed back values: %s\n",bufp,buf);// shows the pushed back values      
}
