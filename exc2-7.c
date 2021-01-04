/*write a function invert(x,p,n) that returns x with the n bits that bigin at 
position p inverted(i.e., 1 changed into 0 and vice versa). leaving the others unchanged*/
#include<stdio.h>

int invert(unsigned ,int ,int );// function prototyping 

int main()//main functon 
{
    unsigned x; // variable x which is unsigned i.e its positive from 0 - 4294*****5 
    int p,n,r; // int type variables

    x = 8;
    p = 4;  //values assined to variables
    n = 3;

    r = invert(x,p,n);//function call
    printf("inverted value of x is = %u\n",r);

    return 0;
}

int invert(unsigned x,int p, int n)
{
    x = x ^ (~(~0 << n) << (p+1-n));
    
    return x;
}
/* In this function 
    x ^ (~(~0 << n) << (p+1-n))
    ~0 makes all the 16 bit to 1(high)
    (~0 << n) leftshifts by n bits
    ~(~0 <<n) agian one's complements making all the bits 0 except rightmost bits those will be one's
    (~(~0<<n) << (p+1-n)) will position the bits to required position
    x ^ (~(~0 << n) << (p+1-n)) will XOR x with the calulation and returns the XOR'ed value x
    */
