/* Exercise 1-10
write a program to copy its input to its output replacing each tab by \t, each backspace by \b and each backslash by \\
this makes tabs and backspace visible in an unabiguous way*/
#include<stdio.h>//header file consiting of standered library functions ex:scanf printf etc..

int main() //main function C starts execution from here
{
    int c;//variable C of type integer
    while((c=getchar()) != EOF)//while loop which accepts next in line charecters through getchar() and assigns in to c and checks if its not equal to EOF
    {
        if(c == '\t')
            printf("\\t");
        if(c == '\b')
            printf("\\b");
        if(c == '\\')
            printf("\\");
        printf("%c",c);            
    }
    return 0;//return statement which returns 0 to main and exits the main function
}
/* here from line 11 if condition checks if the charecter in c is a tab space and if its a tab space then the following
print staement to print \\t is exceuted and next if staement is checked if that condition is satisfied then
the following print statement \\b is executed and so on and finally the last print statement printf("%c",c);
is excuted printig all the changes done to c*/
