/*Exercise 5-12a
    Extend entab and detab to accept short hand 
    detab -m +n */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define TABSPACE 8
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

    
    position = 1; // position of charecter

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            
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
            ++position;
        }
    }
}

void set_tab(int argc,char *argv[],char *tab)
{
    int i,pos,inc;
    if(argc <= 1)
        for(i = 1;i <= MAXLINE; ++i)
            if(i % TABSPACE == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+')
    {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);
        for(i = 1; i <= MAXLINE; i++)
            if(i != pos)
                tab[i] = NO;
            else
            {
                tab[i] = YES;
                pos += inc;
            }
    }
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
