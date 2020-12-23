/*Exercise 1-2
Experiment to find out what happens when printf's argument string contains \c where c is some
charecter not listed above*/ 

#include<stdio.h>//header file
 
main()//main function program starts here
{
    printf("hello, world \c");
    /*print statement with \c escape sequence 
    but it prints hello, world c */ 
}
