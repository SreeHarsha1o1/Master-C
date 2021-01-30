/*exercise 2-2
write a loop equivalent to the for loop above without using && or ||*/
#include <stdio.h>

#define MAX 100

int main()
{
    int i,c;
    int lim = MAX;
    char s[MAX];

    i = 0;
    while(i <= (lim - 1))
    {
        if((c = getchar()) != '\n')
           {
            if(c != EOF)
            {
                s[i] = c;
                
            }
        }
        ++i;
    }
    if(s[i] == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    printf("%s\n",s);
    return 0;
}
