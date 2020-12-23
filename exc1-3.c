/*Exercise 1-3
Modify the temparature conversion program to print a heading above the table*/
#include<stdio.h>

main() //main function c program starts from here
{
    int fahr,celsius,lower,upper,step;// variables that hold integer type values

    lower = 0;//assignment of value '0' to variable lower for lower limit
    upper = 300;//assignment of value '300' to variable upper for upper limit 
    step = 20;//assignment of value '20' to variable step for stepsize 

    fahr = lower; //assigning one variable value to another variable 
    printf("fahr\tcelsius\n");
    while(fahr<=upper) //while loop checks if farh value is greater than upper limit
    {
        celsius = 5*(fahr-32)/9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + step;
    }/* executable statements where celsius is calulated, printed and farh values are updated*/
}
