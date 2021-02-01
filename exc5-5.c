/* Exercise 5-5
    write versions of the library functions strncpy, strncat and strncmp, which operate on at most the first n characters of their argument strings. 
    For example,strncpy(s,t,n)copies at most n charecters of t to s full description are in appendix B*/

#include<stdio.h>

#define MAX 100
#define LIM 100

/*functions for strncpy ,strncat and strncmp are written*/
int getline1(char s[],int lim);
void strncat1(char *, char *, int);
void strncpy1(char *s, char *t, int n);
int strncmp1(char *s, char *t, int n);

int main()
{
	/*char s1[MAX] = "swat";
	char s2[MAX] = "cats";*/
    char s1[MAX];
	char s2[MAX];
	int len1,len2,n,a;
	
	printf("Please enter a string\n");
	len1 = getline1(s1, LIM);
	printf("Please enter another string\n");
	len2 = getline1(s2, LIM);
	printf("enter the n value\n");
    n = getchar();

    strncpy1(s1,s2,n);
    printf("copied string:%s\n",s1);
	strncat1(s1 ,s2,n);
    printf("concatinated string:%s\n",s1);
    a = strncmp1(s1,s2,n);
    printf("string cmp:%d\n",a);
    
	return 0;
}

int getline1(char s[], int lim)
{
	int c,i;
	
	for(i = 0;i < lim-- && (c=getchar()) != EOF && c !='\n' ;i++)
	{
		s[i] = c;
	}
	if(s[i] == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	
	return i;
}

void strncpy1(char *s, char *t, int n)
{
    while(*t && n-- > 0)
        *s++ = *t++;

    while(n-- > 0)
        *s++ = '\0';
}

void strncat1(char *s, char *t,int n)
{
  
    while(*++s != '\0')
        ;

    while(*t && n-- > 0)
        *s++ = *t++;

    while(n-- > 0)
        *s++ = '\0';
    
}

int strncmp1(char *s, char *t, int n)
{
    while(*s == *t)
    {
        if(*s == '\0' || --n <= 0)
            return 0;
        s++;
        t++;
    }
    return *s - *t;
}
