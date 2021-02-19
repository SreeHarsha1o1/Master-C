#include<stdio.h>
#include<stdarg.h>

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;int *i;
    double *dval;
    void *ptr_val;
    unsigned *u;

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
            i = va_arg(ap,int *);
            scanf("%d", i);
            break;
        case 'f':
        case 'g':
        case 'G':
            dval = va_arg(ap,double *);
            scanf("%f", dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            scanf("%s",sval);
            break;
        case 'x':
            u = va_arg(ap,unsigned *);
            scanf("%x", u);
            break;
        case 'X':
            u = va_arg(ap,unsigned *);
            scanf("%X", u);
            break;
        case 'o':
            u = va_arg(ap,unsigned *);
            scanf("%o", u);
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
    int i,f,hex,oct;
    char str[100];
    minscanf("enter a integer:%d\nenter a decimal or float value:%g\nenter the integer for converting to hex:%d\nenter the integer for converting to octal:%d",&i,&f,&hex,&oct);
    printf("integer value:%d\n",i);
    printf("float value:%g\n",f);
    printf("hexadecimal value:%x\n",hex);
    printf("octal value:%03o\n",oct);
    printf("hexadecimal value:%X\n",hex);

    minscanf("enter a string:%s",str);
    printf("print string %s\n",str);
    return 0;
}
