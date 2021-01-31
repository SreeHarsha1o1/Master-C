/*Exercise 5-4 
Write the function strend(s, t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise. */

#include<stdio.h>

#define MAX 100
#define LIM 100

int getline1(char s[],int lim);
int strend1(char *, char *);

int main()
{
	
    char s1[MAX];
	char s2[MAX];
	char s3[MAX] = "cats";
	
    int len1,len2,a;
	
	printf("Please enter a string\n");
	len1 = getline1(s1, LIM);
	printf("Please enter another string\n");
	len2 = getline1(s2, LIM);
	
	a = strend1(s1 ,s3);

    printf("a=%d\n",a);
    a = strend1(s2 ,s3);

    printf("a=%d\n",a);
	
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

int strend1(char *s, char *t)
{
    char *s1 = s;
    char *s2 = t;

    while(*++s != '\0');

    while(*++t != '\0');

    while(*s == *t)
    {
        if(s == s1 || t == s2)
            break;
        s--;
        t--;
    
    }
    
    if(*s == *t && t == s2 && *s !='\0')
        return 1;
    else
        return 0;
}
