/*Exercise 3-1
    our binary search makes two tests inside the loop ,when one would suffice, 
    write a version with only one test inside the loop and measure the difference in run time*/
    
#include<stdio.h>// hearder file that contains all input output file

#define MAX 100// #define symbolic constant

int binsearch(int x,int v[],int n);// function prototyping of the function binsearch

int main()// main function exceution of c program starts here
{
    int c,s,x; // variables of type integer
    int elements[MAX];// integer type array

    x = 0;

    for(c = 0; c < MAX; c++)// for loop that fill the array elements from 0 to 99
        elements[c] = c;
    
    s = binsearch(x,elements,MAX);// function call
    printf("the mid position is %d\n",s); 

    return 0;
}

int binsearch(int x,int v[],int n)// function definition
{
    int low, high, mid; //variables of the function which is of type integer 

    low = 0;
    high = n - 1;
    while(low <= high)// while loop that checks if low is lessthan or equal to high
        {
            mid = (low - high) / 2;// mid is calculated
            if(x < v[mid])// if condition that checks if x is lessthan the mid element of the array v
                high = mid - 1;// if true high is updated
            else 
                low = mid + 1;  // if not low is updated  
        }
    return mid;   // mid value is returned to the calling function s from main
}
