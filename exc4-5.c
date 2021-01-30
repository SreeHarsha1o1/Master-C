/* Exercise 4-5
Add access to library functions like sin , exp and pow. See <math.h> in appendix B, section 4
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'

int getop(char []);
void push(double);
double pop(void);
void mathfnc(char []);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                mathfnc(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else   
                    printf("error: zero devisor\n");
                break;
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(),op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
                break; 
        }
    }
    return 0;
    
}

#define MAXVAL 100 /*maximum length of val stack*/

int sp = 0; /*next free stack position*/
double val[MAXVAL]; /*value stack*/

void push(double f) //pushes f onto value of stack
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n",f);
}

/*pop: pop and return top value from stack*/
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

/*getop: get next operator or numeric oparand*/
int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if(islower(c))//checks for name
    {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if(c != EOF)
            ungetch(c); //went one char far
        if(strlen(s) > 1)
            return NAME;//>1 char; it is NAME
        else
            return c; //it may be a command
    }
    if(!isdigit(c) && c != '.' && c != '-')
        return c; //not a number
    
    if(c == '-')
        if(isdigit(c = getch()) || c == '.')
            s[++i] = c; //negative number
        else
        {
            if(c != EOF)
                ungetch(c);
            return '-'; // minus sign
        }

    if(isdigit(c)) //collect integer part
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') //collect fraction part
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
   // printf("s[]=%s\n",s);
    if(c != EOF)
        ungetch(c);
    return NUMBER;
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
}

void mathfnc(char s[])//performs math operations
{
    double op2;

    if(strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s , "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s , "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(),op2));
    }
    else 
        printf("error: %s not supported\n",s);
}
