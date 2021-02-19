/* Exercise 7-2
    Write a program that will print arbitrary input in sensible way. As a minimum, it should print 
    non graphic charecters in hexadecimel or octal according to the local custom, and break long text lines*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int c;

    //printf("hexadecimal values of space=%x, nwline=%x, tabspace=%x\n",' ','\n','\t');
    //printf("octal values of space=%03o, nwline=%03o, tabspace=%03o\n",' ','\n','\t');
    if(argc < 2)
    {
        printf("please give arguments after ./a.out arguments should be octal or hexa\n");
        return -1; 
    }
   
    while((c = getchar()) != EOF)
        if(strcmp(argv[1],"octal") == 0)
            if(iscntrl(c) || c == ' ')
            {            
                printf("\\%03o",c);

                if(c == '\n')
                {                
                    putchar('\n');
                }
            }
            else
            {
                putchar(c);
            }
        else if(strcmp(argv[1],"hexa") == 0)
            if(iscntrl(c) || c == ' ')
            {
                printf("\\%2x",c);

                if(c == '\n')
                {       
                    putchar('\n');
                }
            }
            else
            {
                putchar(c);
            }   
    return 0;
}
