#include<stdio.h>

#define LOWER 0
#define UPPER 300  
#define STEP 20

void tempconv(int ,int );//function prototype gives the name of the function its return type and its parameter type 

int main()
{
    int a,b;
    a = LOWER;
    tempconv(a,b);/*function call this statement calls the function tempconv 
                     program then goes to tempconv functionfor execution*/
}

void tempconv(int frah,int celcius)
/*function definition contains all the parameter variable name its type
its return type the deleration and statements the body of the function */
//function defenition is the execution part 
//function declaration tells what type of function it is ex:its name (argument or parameter) type and return type
//function call calls the function and program jumps to the function definition and starts executing
{
    printf("frah\tcelcius\n");
    while(frah <= UPPER)
    {
        celcius = 5 * (frah-32) / 9;
        printf("%d\t%d\n",frah,celcius);
        frah = frah + STEP;        
    }
    
}
