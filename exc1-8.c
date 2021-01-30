/* Exercise 1-8
write a program to count blanks,tabs and newlines*/
#include<stdio.h>

int main()//main function this is where c starts is exceution
{
    int c,nl,nt,nb;//creating variables of type integer
    nl=0;nt=0;nb=0;//assignment of values zero to variables
    while((c = getchar()) != EOF)//while loop that acepts charecters and checks if its not equal to EOF
    {
         if(c == '\n')//if condition which checks if the given condition in brackets i true if true it executes its next statement
            ++nl;//it increments nl by 1
        if(c == '\t')//if condition if the above if is false then this else if condition is checked
            ++nt;//if the if condition is true then nt is incremented by 1 or else the below else if is checked
        if(c == ' ')
            ++nb;
    }
    printf("\n nl=%d, nt=%d, nb=%d\n",nl,nt,nb);//print statement that prints nos of lines,tabs,blanks           
    
}

