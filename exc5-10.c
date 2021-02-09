/* Exercise 5-10
 Write the program expr, which evaluates a reverse polish expression from the command line, where each
 operator or operand is a separate argument. For example 
    expr 2 3 4 + *
    evaluates to 2 * (3 + 4) */
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>
#include <string.h>

#define NUMBER '0' /* signal that a number was found */

void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    int type, c;
    double op2;

    printf("Usage: expr 2 3 4 + x or ./a.out 2 3 4 + x\t here x is multiplication\n");

    while (--argc > 0) {
        if (!isdigit(c = **++argv) && strlen(*argv) == 1)
            type = c;
        else
            type = NUMBER;
    
        switch (type) {
        case NUMBER:
            push(atof(*argv));
            break;
        case '+':
            push(pop() + pop());
            break;
        case 'x':
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
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        default:
            printf("error: unknown command\n");
        break;
        }
    }

    printf("answer= %g\n", pop());

    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}