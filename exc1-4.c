/*write a program to print the corresponding celcius to fahrenheit table*/
#include<stdio.h>

main() //main function c program starts from here
{
    int fahr,celsius,lower,upper,step;// variables that hold integer type values

    lower = 0;//assignment of value '0' to variable lower for lower limit
    upper = 300;//assignment of value '300' to variable upper for upper limit 
    step = 20;//assignment of value '20' to variable step for stepsize 

    celsius = lower; //assigning one variable value to another variable 
    printf("celsius\tfahr\n");
    while(celsius<=upper) //while loop checks if farh value is greater than upper limit
    {
        fahr =(celsius/5)*9 + 32;
        printf("%d\t%d\n",celsius,fahr);//print statement which indicates decimal or integer values are printed 
        celsius = celsius + step;
    }/* executable statements where fahr is calulated, printed and celsius values are updated*/
}
