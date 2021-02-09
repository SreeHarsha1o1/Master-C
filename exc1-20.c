/*Exercise 1-20
    write a program detab that replaces tabs in the input with the proper number of blanks to space to the next stop.
    Assume a fixed set of tab stops, say every n coloumns. Should n be a variable or a symbolic parameter
    */

#include<stdio.h>

#define TABSPACE 2

int main()
{
    int c;
    int blanks, position;

    blanks = 0; //no of blanks 
    position = 1; // position of charecter

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            blanks = TABSPACE - (position - 1) % TABSPACE; //calculation to put the blanks 
            while(blanks > 0)
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
    return 0;
}
