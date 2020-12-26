
/*Exercise 1-7
write a program to print the value of EOF*/
#include<stdio.h>

int main()//main function c program starts here
{
    //no need to do c = getchar() !=EOF if you execute the program just with the print satement below
    //you'll get EOF and its -1
    //int c;//variable c of type integer
   // c = getchar() != EOF;//getchar gets the next in characters and assigned to variable c
    //c != EOF;//variable c is checked if its not equal to EOF
    printf("EOF of file is %d\n",EOF);// print statement which prints EOF the value of end of file is -1
}
