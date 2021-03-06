#include<stdio.h>
#include<ctype.h>
#include<string.h>

void lower(void);
void upper(void);

int main(int argc, char *argv[])
{
    if(argv[1])
    {
        if(strcmp(argv[1],"tolower") == 0)
        {
            lower();
        }
        else if (strcmp(argv[1],"toupper") == 0)
        {
            upper();
        }
    }
    else
    {
        printf("usage: give arguments after ./a.out like'./a.out tolower\' or \'./a.out toupper\'\n");
    }
    return 0;
}

void lower(void)
{
    int c;

    while((c = getchar()) != EOF)
        putchar(tolower(c));
}

void upper(void)
{
    int c;

    while((c = getchar()) != EOF)
        putchar(toupper(c));
}
