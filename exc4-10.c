/* Exercise 4-10
An alternate organization uses getline to read an entire input line 
this makes getch and ungetch unnessasary , Revise the calculator to use this approch */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
int getline1(char line[],int lim);

int ln = 0;
char line[MAXOP];

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
                printf("\tanswer:%.8g\n",pop());
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
    int i,c,v;

    if(line[ln] == '\0')
        if((v = getline1(line,MAXOP)) == 0)
            return EOF;
        else
            ln =0;
        printf("printing no of lines:%d\n",v);
    while((s[0] = c = line[ln++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if(!isdigit(c) && c != '.' && c != '-')
        return c; //not a number

    if(isdigit(c)) //collect integer part
        while(isdigit(s[++i] = c = line[ln++]))
            ;
    
    if(c == '.') //collect fraction part
        while(isdigit(s[++i] = c = line[ln++]))
            ;
    
    s[i] = '\0';
    ln--;
    
    return NUMBER;
}

int getline1(char s[],int lim)//getline function which inputs a given line and returns the length
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
