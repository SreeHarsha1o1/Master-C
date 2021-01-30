/* Exercise 1-11
How would you test the word count program
what kind of input are most likely to uncover bugs if there are any*/
#include<stdio.h>

#define IN 1 // symbolic const
#define OUT 0 // symbolic const

int main()
{
    int c,nl,nw,nc,state;
    state = OUT;
    nl = nw = nc= 0;
    while((c = getchar()) != EOF)
    {
        ++nc;//nc is incremented by 1
        if(c == '\n')//checks if c = \n if true nl is incremented by 1
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')//checks if c = ' ' or c = '\n' or c = '\t' if any one is true State is updated
            state = OUT;
        else if(state == OUT) //checks if state = OUT if true state is made to IN and nw is incremented by 1
        {
          state = IN;
          ++nw;  
        }
    }
    printf("\n nl=%d,nw=%d,nc=%d\n",nl,nw,nc);//print statement prints nos of nl,nw,nc            
}
/*
1) here if there is a series of single charecters the nw word is updated and result is no accurate
2) if the input exceeds int range then there is no valid outpput
3) if there is numbers its also considered as words
4) if there is only one line or tab input the count is updated

and few more things like the above are likely to uncover bugs in this exercise*/


