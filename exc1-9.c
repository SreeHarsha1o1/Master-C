/*Exercise 1-9
write a program to copy its input to its output, replacing each string of one or more blanks
by a single blank*/
#include<stdio.h>

int main()
{
    int c,lc;
    
    while((c = getchar()) != EOF)
    {   
        if(c != ' ' || lc != ' ')
            putchar(c);
        lc = c;        
    }
}
/* in line 12
1) c hold the input given by the user and chaecter by charecter its compared wheather is not equal to ' ' space
2) if its equal to ' ' then lc is compared if its equal to ' ' space or not 
3) since OR gate is used if any one of the above condition is true the entire result is true anf if condition is true
    and the putchar is executed
4) lc is assingned with the charecter that c is holding 
5) if both the condition (c != ' ') and (lc != ' ') are not satisfied then putchar() is not excuted 
    and lc is updated
6) this process is repeated till the EOF is meat*/
