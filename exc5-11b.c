/*Exercise 5-11b
    Modify the Program entab and detab (wrriten as exercise in chapter 1) to accept a list of tabs stops as arguments.
    Use the default tab settings if there are no arguments */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define TABSPACE 2
#define MAXLINE 100
#define YES 1
#define NO 0

void set_tab(int argc,char *argv[],char *tab);
void detab(char *tab);
int tabposition(int pos,char *tab);

int main(int argc,char *argv[])
{
    char tab[MAXLINE+1];

    set_tab(argc,argv,tab);
    detab(tab);
    return 0;
}

void detab(char *tab)
{
    int c;
    int blanks, position;

    //blanks = 0; //no of blanks 
    position = 1; // position of charecter

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            //blanks = TABSPACE - (position - 1) % TABSPACE; //calculation to put the blanks 
            while(tabposition(position++, tab) != YES)
            {
                putchar(' ');
                ++position;
                --blanks;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            position = 1;
        }
        else 
        {
            putchar(c);
            ++position;/* code */
        }
    }
}

void set_tab(int argc,char *argv[],char *tab)
{
    int i,pos;
    if(argc <= 1)
        for(i = 1;i <= MAXLINE; ++i)
            if(i % TABSPACE == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else
    {
        for(i = 1; i <= MAXLINE; i++)
            tab[i] = NO;
        while(--argc > 0)
        {
            pos = atoi(*++argv);
            if(pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
}

int tabposition(int pos, char *tab)
{
    if(pos > MAXLINE)
        return YES;
    else 
        return tab[pos];
}
