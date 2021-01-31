#include<stdio.h>

#define MAX 100
#define LIM 100

int getline1(char s[],int lim);
void strcat1(char *, char *);

int main()
{
	/*char s1[MAX] = "swat";
	char s2[MAX] = "cats";*/
    char s1[MAX];
	char s2[MAX];
	int len1,len2;
	
	printf("Please enter a string\n");
	len1 = getline1(s1, LIM);
	printf("Please enter another string\n");
	len2 = getline1(s2, LIM);
	
	strcat1(s1 ,s2);

    printf("concatinated string:%s",s1);
	
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

void strcat1(char *s, char *t)
{
  
    while(*++s != '\0')
        ;

    while(*s++ = *t++ )
        ;

    //*s = '\0';
    
}
