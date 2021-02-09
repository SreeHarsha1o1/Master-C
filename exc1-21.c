/*Exercise 1-22
    Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.
    Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop which should 
    be given preference */

#include<stdio.h>

#define TABSPACE 8

int main()
{
    int c, blanks,position,tabs;

    blanks = 0;
    tabs = 0;
    for(position = 1; (c = getchar()) != EOF; ++position)
        if(c == ' ')
        {
            if(position % TABSPACE != 0)
                ++blanks;
            else
            {
                blanks = 0;
                ++tabs;
            }
        }
        else
        {
            for(;tabs > 0; --tabs)
                putchar('\t');
            if(c == '\t')
                blanks = 0;
            else 
                for(; blanks > 0; --blanks)
                    putchar(' ');
            putchar(c);
            if(c == '\n')
                position = 0;
            else if(c == '\t')
                position = position + (TABSPACE - (position -1) % TABSPACE) - 1;
        }
    return 0;
}
