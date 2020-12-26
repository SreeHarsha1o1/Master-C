/*Exercise 1-12
write a program that prints its input one word per line*/
#include<stdio.h>

int main()
{
    int c;
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')//checks if c = ' ' or c = '\n' or c = '\t' if any one is true putchar is excuted
        {
            
                
                putchar('\n');
            
        }
        else//if the above if contidion is not true then else condition is excuted i.e putchar(c) is executed 
        {
            
            putchar(c);
        }     
    }        
}
