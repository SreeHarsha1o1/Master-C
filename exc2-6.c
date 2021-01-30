/* write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the 
rightmost n bits of y, leaving the other bits unchanged*/
#include<stdio.h>

unsigned setbits(unsigned x, int p,int n, unsigned y)//function definition
{
    return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
}/*Here p is the position, n is the number of bits, x and y are inputs
    This function sets the rightmost n bits of y to the given position and no of bits in x
    without changing other bits.
 */

int main()
{
    unsigned int x;// variable x of type unsigned int
    unsigned int y;
    int p,n,z;

    x = 7;
    n = 3;  //assigning of values to each variable
    p = 4;
    y = 5;

    z = setbits(x,p,n,y);//function call
    printf("x = %u p = %d n = %d y = %u  \n",x,n,p,y);
    printf("z = %u\n",z);
                        // print statements 
   return 0;
}
