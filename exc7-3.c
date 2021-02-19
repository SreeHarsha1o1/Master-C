/*Exercise 7-3
    Revise minprintf to handle more of the other facilities of printf*/

#include<stdio.h>
#include<stdarg.h>

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    void *ptr_val;

    va_start(ap,fmt);
    for(p = fmt; *p; p++)
    {
        if(*p != '%')
        {
            putchar(*p);
            continue;
        }
        switch(*++p)
        {
        case 'd':
            ival = va_arg(ap,int);
            printf("%d", ival);
            break;
        case 'f':
        case 'g':
        case 'G':
            dval = va_arg(ap,double);
            printf("%f", dval);
            break;
        case 's':
            for(sval = va_arg(ap, char *);*sval; sval++)
                putchar(*sval);
            break;
        case 'x':
            ival = va_arg(ap,int);
            printf("%x", ival);
            break;
        case 'X':
            ival = va_arg(ap,int);
            printf("%X", ival);
            break;
        case 'o':
            ival = va_arg(ap,int);
            printf("%o", ival);
            break;
        case 'p':
            ptr_val = (void *) va_arg(ap,unsigned long);
            printf("%p", ptr_val);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}

int main()
{
    int n;
    n=10;

    int *ptr;
    ptr = &n;
    minprintf("Hexadecimal: %X\n", 255);
    minprintf("print out\n octal = %o\n integer = %d\n string = %s\n float = %f\n double = %G\n",15, n, "cats", 10.12, 100.99);
    minprintf("print out pointer = %p\n",ptr);
    minprintf("Hexadecimal: %x\n", 255);

    return 0;
}
