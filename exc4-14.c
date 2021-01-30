
#include<stdio.h>

#define swap(t,x,y) {int z; z = x; x = y; y = z;}

int main()
{
    int i,j,t;

    i=10;
    j=20;

    printf("i = %d, j = %d\n",i,j);
    swap(t,i,j);
    printf("i = %d, j = %d\n",i,j);
    
    return 0;
}
