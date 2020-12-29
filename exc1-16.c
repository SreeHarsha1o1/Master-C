/*Exercise 1-16
Revise the main routine of the longest-line program so it will correctly print the length of arbitraryily long inpput lines and 
as much as possible of the text */

#include<stdio.h>
#define MAXLINE 1000

int getline1(char s[],int lim);
void copy(char to[],char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline1(line,MAXLINE)) > 0)//while loop which checks for len > 0 or not it calls a function getline1
        if(len > max){  
            max = len;
            copy(longest, line);//copy function is called
            printf("length = %d string = %s",len ,line);//this gives the length of the string and string that is inputed
        }
    if(max>0)
    { 
        printf("longest_string = %s",longest);
    }
    return 0;        
}

int getline1(char s[],int lim)//getline1 function with character array s[] and lim variable og type integer
{                              //this function reads input and returns its length
    int c,i;

    for(i=0;i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        ++i;
       // printf("i = %d\n",i); 
    }    
    s[i] = '\0';
    return i;
}

void copy(char to[],char from[])//copy function this function copies the charecter arry from[] to to[] 
{
    int i;

    i=0;
    while ((to[i] = from[i]) != '\0')
    ++i;
}
