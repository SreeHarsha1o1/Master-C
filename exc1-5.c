/*Excercise 1-5
Modify the temperature conversion program to print the table in reverse order, 
that is, from 300 degrees to 0?*/

/*in this exercise the temparature coversion is reversed and rints from upper limit to lower limit*/
#include<stdio.h>

main() //main function c program starts from here
{
    int fahr,celsius,lower,upper,step;// variables that hold integer type values

    lower = 0;//assignment of value '0' to variable lower for lower limit
    upper = 300;//assignment of value '300' to variable upper for upper limit 
    step = 20;//assignment of value '20' to variable step for stepsize 

    fahr = upper; //assigning one variable value to another variable 
    printf("fahr\tcelsius\n");
    while(fahr>=lower) //while loop checks if farh value is greater than or equal to lower limit
    {
        celsius = 5*(fahr-32)/9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr - step;
    }/* executable statements where celsius is calulated, printed and farh values are updated*/
}
