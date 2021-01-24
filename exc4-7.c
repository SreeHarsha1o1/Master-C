/* Exercise 4-7
write a routine unget(s) that will push back an entire string onto the input 
should ungets know about buf and bufp or should it just use ungetch() */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void ungets(char s[]);

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
    ungets(s);//pushes entire strring
    printf("ungets string = %s\n", s);
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

    printf("bufp: %d, pushed back values: %s\n",bufp,buf);// shows the pushed back values      
}

void ungets(char s[])
{
    int len = strlen(s);
    
    while(len > 0)
        ungetch(s[--len]);
}
