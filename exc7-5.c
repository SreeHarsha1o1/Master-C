/* Exercise 7-5
    Rewrite postfix calculator of chapter 4 to use scanf to do the input and number conversion */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

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
    int i,c,rc;
    float f;

    while((rc = scanf("%c",&c)) != EOF)
        if((s[0] = c = getch() == ' ' || c == '\t'))
            break;
    s[1] = '\0';
    if(rc == EOF)
        return EOF;
    else if(!isdigit(c) && c != '.')
        return c;
    ungetc(c,stdin);
    scanf("%f",&f);
    sprintf(s,"%f",f);
    
    /*if(c == '-')
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
        ungetch(c);*/
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
