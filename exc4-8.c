/* Exercise 4-6
 Add comands for handling variables (It's easy to provide twenty six variables with single letters names) 
 Add a variable for the most recent value printed.
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

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
    double variable[26];
    int i,v,var=0;

    for(i = 0; i < 26; i++)
        variable[i] = 0.0;
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
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z')
                    variable[var - 'A'] = pop();
                else
                    printf("error: no variable name\n");
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variable[type - 'A']);
                else if(type == 'v')
                    push(v);
                else
                    printf("error: unknown command %s\n",s);
                break; 
        }
        var = type;
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

char buf = 0; //here both buf and bufp are commented  and single buf of type char is used 
//char buf[BUFSIZE]; // buffer for unget
//int bufp = 0;   //next free position in buff

int getch(void) // get a (popssibly pushed back) charecter
{
    int c;
    if(buf != 0)
        c = buf; 
    else
        c = getchar();
    buf =0;
    return c;
    //buf is initialized to 0 and every time it gets a charecter buf is made zero
    //getch resets the buf each time it gets a charecter 
    //buf is a char tye not an array since only one charecter gets pushed back each time. 
}

void ungetch(int c) //push charecter back on input
{
    if (buf != 0)
        printf("ungetch: too many charecters\n");
    else
        buf = c;
}
